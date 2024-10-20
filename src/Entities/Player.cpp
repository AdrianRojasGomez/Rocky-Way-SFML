#include "Player.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/ResourceManager.h"



Player::Player()
{
	cooldownClock.restart();
	this->playerTexture = ResourceManager::GetPlayerTexture();
	LoadPlayerTexture();
	SetInitialPosition();
	CreateBullets();
}

void Player::LoadPlayerTexture()
{
	if (playerTexture != nullptr)
	{
		playerSprite.setTexture(*playerTexture);
		playerSprite.setScale(SCALE_X, SCALE_Y);
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
	playerSprite.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
}

void Player::Movement()
{
	this->rotation = playerSprite.getRotation() - 90.0f;
	this->directionX = std::cos(rotation * 3.14159265f / 180.0f);
	this->directionY = std::sin(rotation * 3.14159265f / 180.0f);

	Fire();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		playerSprite.move(directionX * MOVE_SPEED * Framerate::getDeltaTime(), directionY * MOVE_SPEED * Framerate::getDeltaTime());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerSprite.rotate(-ROTATION_SPEED * Framerate::getDeltaTime());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.rotate(ROTATION_SPEED * Framerate::getDeltaTime());

	this->posX = playerSprite.getPosition().x;
	this->posY = playerSprite.getPosition().y;
	this->playerArea.setPosition(posX, posY);

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
	if (cooldownClock.getElapsedTime().asSeconds() >= COOLDOWN_RATE)
	{
		isFiring = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isFiring == false)
		{
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

void Player::Update()
{
	Movement();
	WrapAroundScreen(posX, posY, SCREEN_WIDTH, SCREEN_HEIGHT);
	playerSprite.setPosition(posX, posY);
	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		Bullet* bulletToDraw = *iterator;
		if (bulletToDraw->GetIsActive())
		{
			bulletToDraw->Update();
		}
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerArea);
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

