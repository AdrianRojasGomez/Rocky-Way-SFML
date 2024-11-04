#include "Player.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"
#include "../Utilities/ScoreManager.h"
#include "../Audio/AudioManager.h"

Player::Player(UI* ui, GameState* gameState)
{
	this->gameState = gameState;
	this->ui = ui;
	textureRect = sf::IntRect(0, 0, 128, 128);
	HP = MaxHP;
	cooldownClock.restart();
	playerTexture = ResourceManager::GetPlayerTexture();
	SetTextureValues();
	SetInitialPosition();
	CreateBullets();
	ui->SetUIHP(HP);
}

Player::~Player()
{
}

void Player::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape)
			*gameState = GameState::Pause;
	}
}

void Player::Update()
{
	if (!CheckHasHPLeft())
	{
		ScoreManager::getInstance().CompareHighScore();
		*gameState = GameState::GameOver;
	}

	Respawn();
	RemoveInvulnerability();
	Fire();
	Movement();
	UpdateFrameanimation();
	WrapAroundScreen(posX, posY, directionX, directionY, 15.0f, playerSprite);
	playerSprite.setPosition(posX, posY);
	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		Bullet* bulletToDraw = *iterator;
		if (bulletToDraw->GetIsActive())
		{
			bulletToDraw->Update();
		}
	};
}

void Player::Draw(sf::RenderWindow& window)
{
	if (!isAlive)
		return;
	window.draw(playerSprite);

	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		Bullet* bulletToDraw = *iterator;
		if (bulletToDraw->GetIsActive())
		{
			bulletToDraw->Draw(window);
		}
	}

}


void Player::PlayerReset()
{
	*gameState = GameState::Gameplay;
	SetInitialPosition();
	HP = MaxHP;
	ui->SetUIHP(HP);
}

void Player::SetTextureValues()
{
	if (playerTexture != nullptr)
	{
		playerSprite.setTexture(*playerTexture);
		playerSprite.setTextureRect(textureRect);
		playerSprite.setScale(SCALE,SCALE);
		sf::FloatRect bounds = playerSprite.getLocalBounds();
		playerSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		this->posX = playerSprite.getPosition().x;
		this->posY = playerSprite.getPosition().y;

	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING PLAYER TEXTURE" << std::endl;
}

void Player::SetInitialPosition()
{
	playerSprite.setPosition(ScreenResolution::GetScreenCenter720());
}

void Player::Movement()
{

	this->rotation = playerSprite.getRotation() - FIXED_DEGREES;
	this->directionX = std::cos(rotation * NUM_PI / 180.0f);
	this->directionY = std::sin(rotation * NUM_PI / 180.0f);
	speedX = directionX * MOVE_SPEED;
	speedY = directionY * MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		playerSprite.move(speedX * Framerate::getDeltaTime(), directionY * MOVE_SPEED * Framerate::getDeltaTime());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		playerSprite.rotate(-ROTATION_SPEED * Framerate::getDeltaTime());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		playerSprite.rotate(ROTATION_SPEED * Framerate::getDeltaTime());

	this->posX = playerSprite.getPosition().x;
	this->posY = playerSprite.getPosition().y;

}

void Player::CreateBullets()
{
	for (int i = 0; i < BULLET_CAPACITY; i++)
	{
		Bullet* bullet = new Bullet();
		bullets.push_back(bullet);
	}
}

void Player::Fire()
{
	if (!isAlive)
		return;

	if (cooldownClock.getElapsedTime().asSeconds() >= COOLDOWN_RATE)
	{
		isFiring = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isFiring == false)
		{
			AudioManager::getInstance().PlayShootSound();
			for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
			{
				if ((*iterator)->GetIsActive() == false)
				{
					(*iterator)->Fire(posX, posY, directionX, directionY);
					isFiring = true;
					cooldownClock.restart();
					break;
				}
			}
		}

	}
}

bool Player::CheckHasHPLeft()
{
	if (HP <= 0)
		return false;
	else
		return true;

}

void Player::Respawn()
{
	if (!isAlive && respawnClock.getElapsedTime().asSeconds() > RESPAWN_TIME)
	{
		isAlive = true;
		SetInitialPosition();
	}
}

void Player::RemoveInvulnerability()
{
	if (respawnClock.getElapsedTime().asSeconds() > INVULNERABLE_TIME)
	{
		isInvulnerable = false;
	}
}

void Player::SetIsAlive(bool isAlive)
{
	if (isInvulnerable)
		return;

	this->isAlive = isAlive;
	if (!isAlive)
		HP--;
	ui->SetUIHP(HP);
	respawnClock.restart();
	isInvulnerable = true;
}

void Player::UpdateFrameanimation()
{
	if (animationClock.getElapsedTime().asMilliseconds() > 42)
	{
		if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))))
		{
			if (intRectPosX <= 0)
				intRectPosX = 0;
			else
				intRectPosX -= 128;
		}
		else if (speedX != 0 || speedY != 0)
		{
			if (intRectPosX >= 384)
				intRectPosX = 128;
			else
				intRectPosX += 128;
		}

		textureRect = sf::IntRect(intRectPosX, 0, 128, 128);
		playerSprite.setTextureRect(textureRect);
		animationClock.restart();
	}
}



