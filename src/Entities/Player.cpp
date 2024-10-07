#include <iostream> // for Debug logs currently

#include "Player.h"

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
	playerSprite.setPosition(1280 * 0.5f, 720 * 0.5f);
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

}

void Player::Update()
{
	Movement();
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}

