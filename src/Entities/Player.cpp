#include "Player.h"



Player::Player()
{
	cooldownClock.restart();
	LoadPlayerTexture();
	SetInitialPosition();
	CreateBullets();
}

void Player::LoadPlayerTexture()
{
	if (playerTexture.loadFromFile("res/assets/Player/player.png"))
	{
		playerSprite.setTexture(playerTexture);
		playerSprite.setScale(SCALE_X, SCALE_Y);
		sf::FloatRect bounds = playerSprite.getLocalBounds();
		playerSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING PLAYER TEXTURE" << std::endl;
}

void Player::SetInitialPosition()
{
	//TODO: Is there a way to get these values from Game withouth loading all Game class? 
	playerSprite.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
}

void Player::Movement()
{
	this->rotation = playerSprite.getRotation() - 90.0f;
	this->directionX = std::cos(rotation * 3.14159265f / 180.0f);
	this->directionY = std::sin(rotation * 3.14159265f / 180.0f);

	Fire();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		playerSprite.move(directionX * MOVE_SPEED, directionY * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerSprite.rotate(-ROTATION_SPEED);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.rotate(ROTATION_SPEED);

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


	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		std::cout << "Bullet daño: " << (*iterator)->getDamage() << std::endl;
	}

}

void Player::Fire()
{
	if (cooldownClock.getElapsedTime().asSeconds() >= COOLDOWN_RATE)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
			{
				Bullet* bulletSelected = *iterator;
				if (bulletSelected->getIsActive() == false)
				{
					//bulletSelected->Fire(playerPosition2f, rotation, directionX, directionY);
				}
			}
		}
		cooldownClock.restart();

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
		if (bulletToDraw->getIsActive())
		{
			bulletToDraw->Update();
		}
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);

	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		Bullet* bulletToDraw = *iterator;
		if (bulletToDraw->getIsActive())
		{
			bulletToDraw->Draw(window);
		}
	}
}

