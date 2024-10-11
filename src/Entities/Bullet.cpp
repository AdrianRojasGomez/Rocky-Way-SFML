#include <iostream>
#include "Bullet.h"
#include "../Utilities/WrappingScreenUtility.h"


Bullet::Bullet()
{
	LoadBulletTexture();
}


void Bullet::LoadBulletTexture()
{
	if (bulletTexture.loadFromFile("res/assets/Traces/BasicShot.png"))
	{
		bulletSprite.setTexture(bulletTexture);
		bulletSprite.setScale(scaleX, scaleY);
		sf::FloatRect bounds = bulletSprite.getLocalBounds();
		bulletSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BULLET TEXTURE" << std::endl;
}

void Bullet::Fire(sf::Vector2f shooterPosition, float rotation, float dirX, float dirY)
{

	this->shooterPosition = shooterPosition;
	this->shooterRotation = rotation;
	this->shooterDirX = dirX;
	this->shooterDirY = dirY;
	this->isActive = true;
	timer.restart();
	SetPosition();
	SetRotation();
	BulletTimer();

	std::cout << "Fire from Bullet\n";
}

void Bullet::SetRotation()
{
	bulletSprite.setRotation(shooterRotation);
}

void Bullet::SetPosition()
{
	bulletSprite.setPosition(shooterPosition);
}

void Bullet::BulletMovement()
{
	bulletSprite.move(shooterDirX * BULLET_SPEED, shooterDirY * BULLET_SPEED);
	this->posX = bulletSprite.getPosition().x;
	this->posY = bulletSprite.getPosition().y;
}

void Bullet::BulletTimer()
{
	if (timer.getElapsedTime().asSeconds() > BULLET_LIFETIME)
	{
		this->isActive = false;
	}
}

void Bullet::Update()
{
	if (!isActive)
		return;
	BulletMovement();
	BulletTimer();
	WrapAroundScreen(posX, posY, 1280, 720);
	bulletSprite.setPosition(posX, posY);


}

void Bullet::Draw(sf::RenderWindow& window)
{
	if (!isActive)
		return;
	window.draw(bulletSprite);
}



