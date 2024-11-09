#include "Player.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ScreenResolution.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../SingletonManagers/ScoreManager.h"
#include "../SingletonManagers/AudioManager.h"

Player::Player(UI* ui, GameState* gameState, ScreenShake* screenShake)
{
	this->gameState = gameState;
	this->ui = ui;
	this->screenShake = screenShake;
	HP = MaxHP;
	playerHitZone = new sf::FloatRect;
	textureRect = sf::IntRect(0, 0, 128, 128);
	cooldownClock.restart();
	playerTexture = ResourceManager::getInstance().GetPlayerTexture();
	SetTextureValues();
	SetInitialPosition();
	CreateBullets();
	ui->SetUIHP(HP);
}

Player::~Player()
{
	if (playerHitZone != nullptr)
	{
		delete playerHitZone;
		playerHitZone = nullptr;
	}

}

void Player::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape)
			*gameState = GameState::Pause;

		if (event.key.code == sf::Keyboard::W || event.KeyPressed == sf::Keyboard::Up)
		{
			if (!isAlive)
				return;
			AudioManager::getInstance().PlayEngineSound();
		}

		if (event.key.code == sf::Keyboard::R)
		{

			//DEBUG ONLY
			//screenShake->StartShake(0.2f, 5.0f);
			//SetIsAlive(false);
		}
	}

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W || event.KeyPressed == sf::Keyboard::Up)
		{
			AudioManager::getInstance().StopEngineSound();
		}
	}

}

void Player::Update()
{
	if (deathClock.getElapsedTime().asSeconds() < 1.7)
		return;

	if (!CheckHasHPLeft())
	{
		ScoreManager::getInstance().CompareHighScore();
		ScoreManager::getInstance().ResetScore();
		SetInitialPosition();
		HP = MaxHP;
		ui->SetUIHP(HP);
		*gameState = GameState::GameOver;
		return;
	}

	HasShieldExpired();
	HasDobleExpired();
	HasShotgunExpired();
	Respawn();
	RemoveInvulnerability();
	Fire();
	Movement();
	UpdateFrameAnimation();
	WrapAroundScreen(posX, posY, directionX, directionY, playerOffsetWrap, playerSprite);
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
	window.draw(shieldShape);
}

void Player::SetTextureValues()
{
	if (playerTexture != nullptr)
	{
		playerSprite.setTexture(*playerTexture);
		playerSprite.setTextureRect(textureRect);
		playerSprite.setScale(SCALE, SCALE);
		sf::FloatRect bounds = playerSprite.getLocalBounds();
		playerSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		posX = playerSprite.getPosition().x;
		posY = playerSprite.getPosition().y;

	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING PLAYER TEXTURE" << std::endl;
}

void Player::SetInitialPosition()
{
	playerSprite.setPosition(ScreenResolution::GetScreenCenter720());
	*playerHitZone = playerSprite.getGlobalBounds();
	playerHitZone->height *= hitzoneSizeMultiplier;
	playerHitZone->width *= hitzoneSizeMultiplier;
}

void Player::Movement()
{
	rotation = playerSprite.getRotation() - FIXED_DEGREES;
	directionX = std::cos(rotation * NUM_PI / 180.0f);
	directionY = std::sin(rotation * NUM_PI / 180.0f);
	speedX = directionX * MOVE_SPEED;
	speedY = directionY * MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		playerSprite.move(speedX * Framerate::getDeltaTime(), directionY * MOVE_SPEED * Framerate::getDeltaTime());


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		playerSprite.rotate(-ROTATION_SPEED * Framerate::getDeltaTime());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
		playerSprite.rotate(ROTATION_SPEED * Framerate::getDeltaTime());

	posX = playerSprite.getPosition().x;
	posY = playerSprite.getPosition().y;
	sf::Vector2f originOffset = playerSprite.getOrigin() * hitzoneSizeMultiplier;
	playerHitZone->left = posX - originOffset.x / 2;
	playerHitZone->top = posY - originOffset.y / 2;

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
			screenShake->StartShake(0.1f, 1.25f);

			if (hasShotgun)
			{
				float angles[] = { -spreadShotgun, 0.0f, spreadShotgun };

				for (int i = 0; i < 3; ++i)
				{
					float angle = angles[i];
					sf::Vector2f rotatedDirection = RotateVector(sf::Vector2f(directionX, directionY), angle);

					for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
					{
						if (!(*iterator)->GetIsActive())
						{
							(*iterator)->Fire(posX, posY, rotatedDirection.x, rotatedDirection.y);
							isFiring = true;
							cooldownClock.restart();
							break;
						}
					}
				}
			}
			else
			{
				sf::Vector2f rotatedDirection(directionX, directionY);
				for (iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
				{
					if (!(*iterator)->GetIsActive())
					{
						(*iterator)->Fire(posX, posY, rotatedDirection.x, rotatedDirection.y);
						isFiring = true;
						cooldownClock.restart();
						break;
					}
				}
			}
		}
	}
}

sf::Vector2f Player::RotateVector(sf::Vector2f vectorDirection, float degrees)
{
	float angleRadians = degrees * NUM_PI / 180;
	float cosA = std::cos(angleRadians);
	float sinA = std::sin(angleRadians);

	return sf::Vector2f(vectorDirection.x * cosA - vectorDirection.y * sinA, vectorDirection.x * sinA + vectorDirection.y * cosA);
}

bool Player::CheckHasHPLeft()
{
	if (HP <= 0)
		return false;
	else
		return true;

}

void Player::TriggerScreenshake()
{
	if (HP > 0)
		screenShake->StartShake(0.2f, 5.0f);
	else
		screenShake->StartShake(0.5f, 5.0f);

}

void Player::ResetFromPause()
{
	ScoreManager::getInstance().ResetScore();
	SetInitialPosition();
	HP = MaxHP;
	ui->SetUIHP(HP);
	hasShield = false;
}

void Player::EnableShield()
{

	hasShield = true;
	shieldShape.setRadius(20);
	shieldShape.setOutlineColor(sf::Color::Blue);
	shieldShape.setOutlineThickness(3);
	shieldShape.setFillColor(sf::Color::Transparent);
	shieldShape.setPosition(playerSprite.getGlobalBounds().left, playerSprite.getGlobalBounds().top);
	shieldClock.restart();
}

void Player::CallDoubleScore()
{
	hasDobleMultiplier = true;
	ScoreManager::getInstance().EnableDobleScore();
	dobleClock.restart();
}

void Player::EnableShotgun()
{
	hasShotgun = true;
	shotgunClock.restart();
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

	if (hasShield)
		return;

	this->isAlive = isAlive;
	if (!isAlive)
	{
		HP--;
		AudioManager::getInstance().PlayPlayerDestroyedSound();
	}
	ui->SetUIHP(HP);
	respawnClock.restart();
	isInvulnerable = true;

	if (HP <= 0)
	{
		AudioManager::getInstance().StopAllMusic();
		AudioManager::getInstance().StopEngineSound();
		deathClock.restart();
	}
}

void Player::UpdateFrameAnimation()
{
	if (!(animationClock.getElapsedTime().asMilliseconds() > 42))
		return;

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

void Player::HasShieldExpired()
{
	if (shieldClock.getElapsedTime().asSeconds() > bonusTime)
	{
		hasShield = false;
		shieldShape.setRadius(0);
	}
	else
	{
		shieldShape.setPosition(playerSprite.getGlobalBounds().left, playerSprite.getGlobalBounds().top);

	}
}

void Player::HasDobleExpired()
{
	if (hasDobleMultiplier && dobleClock.getElapsedTime().asSeconds() > bonusTime)
	{
		hasDobleMultiplier = false;
		ScoreManager::getInstance().DisableMutiplier();
	}
}

void Player::HasShotgunExpired()
{
	if (hasShotgun && shotgunClock.getElapsedTime().asSeconds() > bonusTime)
	{
		hasShotgun = false;
	}
}

