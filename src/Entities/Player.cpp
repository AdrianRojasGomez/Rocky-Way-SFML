#include <iostream> // for Debug logs currently
#include "Player.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "Bullet.h"

Player::Player()
{
	LoadPlayerTexture();
	SetInitialPosition();
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
	float rotation = playerSprite.getRotation() - 90.0f;
	float directionX = std::cos(rotation * 3.14159265f / 180.0f);
	float directionY = std::sin(rotation * 3.14159265f / 180.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		playerSprite.move(directionX * MOVE_SPEED , directionY * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerSprite.rotate(-ROTATION_SPEED);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.rotate(ROTATION_SPEED);

	this->posX = playerSprite.getPosition().x;
	this->posY = playerSprite.getPosition().y;

}



void Player::CreateBullets()
{

}

void Player::Update()
{
	Movement();
	WrapAroundScreen(posX, posY, SCREEN_WIDTH, SCREEN_HEIGHT);
	playerSprite.setPosition(posX, posY);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

