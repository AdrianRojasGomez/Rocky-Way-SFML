#include <iostream>
#include "Bullet.h"


Bullet::Bullet()
{
	LoadBulletTexture();
}


void Bullet::LoadBulletTexture()
{
	if (bulletTexture.loadFromFile("res/assets/Traces/BasicShoot.png"))
	{
		bulletSprite.setTexture(bulletTexture);
		bulletSprite.setScale(scaleX, scaleY);

	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BULLET TEXTURE" << std::endl;
}

void Bullet::Fire(float initPosX, float initPosY, float initDirX, float initDirY)
{
	this->posX = initPosX;
	this->posY = initPosX;
	this->shooterDirX = initPosX;
	this->shooterDirY = initPosX;
	this->isActive = true;
	CalculateRotation();
	BulletTimer();
}

void Bullet::CalculateRotation()
{
	this->angleRotation = std::atan2f(shooterDirY, shooterDirX);
	bulletSprite.setRotation(angleRotation);
}

void Bullet::BulletMovement()
{
	bulletSprite.move(shooterDirX * BULLET_SPEED, shooterDirY * BULLET_SPEED);
	posX = bulletSprite.getPosition().x;
	posY = bulletSprite.getPosition().y;
}

void Bullet::BulletTimer()
{
	timer.restart();
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
	WrapAroundScreen(posX, posY, SCREEN_WIDTH, SCREEN_HEIGHT);
	bulletSprite.setPosition(posX, posY);


}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(bulletSprite);
}



