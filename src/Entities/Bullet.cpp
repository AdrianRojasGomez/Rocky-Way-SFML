#include <iostream>
#include "Bullet.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/Framerate.h"


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

void Bullet::Fire(float posX, float posY, float dirX, float dirY)
{

	this->posX = posX;
	this->posY = posY;
	this->shooterDirX = dirX;
	this->shooterDirY = dirY;
	this->isActive = true;
	timer.restart();
	SetPosition();
	SetRotation();
	BulletTimer();

}

void Bullet::SetRotation()
{
	float angleInRadians = std::atan2(shooterDirY, shooterDirX);
	float angleDregrees = angleInRadians * 180 / 3.14159265f;
	bulletSprite.setRotation(angleDregrees + 90);
}

void Bullet::SetPosition()
{

	bulletSprite.setPosition(posX,posY);
}

void Bullet::BulletMovement()
{
	bulletSprite.move(shooterDirX * BULLET_SPEED * Framerate::getDeltaTime(), shooterDirY * BULLET_SPEED * Framerate::getDeltaTime());
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



