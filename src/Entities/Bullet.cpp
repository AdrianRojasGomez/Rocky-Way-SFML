#include <iostream>
#include "Bullet.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/RandomUtility.h"
#include "../Utilities/WrappingScreenUtility.h"

Bullet::Bullet()
{
	bulletTexture = ResourceManager::getInstance().GetBulletTexture();
	bulletRedTexture = ResourceManager::getInstance().GetPowerBulletTexture();
	gen = std::mt19937(rd());
	dis = std::uniform_real_distribution<float>(-MAX_SPREAD_ANGLE, MAX_SPREAD_ANGLE);
	timer = new sf::Clock;
	SetTextureValues();
}

Bullet::~Bullet()
{
	if (timer != nullptr)
	{
		delete timer;
		timer = nullptr;
	}
}

void Bullet::SetTextureValues()
{
	textureRect = sf::IntRect(0, 0, 160, 320);
	if (bulletTexture != nullptr)
	{
		bulletSprite.setTexture(*bulletTexture);
		bulletSprite.setTextureRect(textureRect);
		bulletSprite.setScale(scaleBulletX, scaleBulletY);
		sf::FloatRect bounds = bulletSprite.getLocalBounds();
		bulletSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BULLET TEXTURE" << std::endl;
}

void Bullet::Fire(float posX, float posY, float dirX, float dirY)
{
	intRectPosX = 0;
	sf::Vector2f originalDir(dirX, dirY);
	float length = std::sqrt(originalDir.x * originalDir.x + originalDir.y * originalDir.y);
	if (length != 0)
		originalDir /= length;
	else
		originalDir = sf::Vector2f(1.0f, 0.0f);

	float deviationDegrees = getRandomDeviation();
	float deviationRadians = degToRad(deviationDegrees);

	sf::Vector2f deviatedDir = rotateVector(originalDir, deviationRadians);

	this->bulletDirX = deviatedDir.x;
	this->bulletDirY = deviatedDir.y;

	this->posX = posX;
	this->posY = posY;
	isActive = true;
	timer->restart();
	SetPosition();
	SetRotation();
	BulletTimer();
}

float Bullet::getRandomDeviation()
{
	return dis(gen); // Returns a random float between -MAX_SPREAD_ANGLE and +MAX_SPREAD_ANGLE
}

float Bullet::degToRad(float degrees)
{
	return degrees * (3.14159265f / 180.0f);
}

sf::Vector2f Bullet::rotateVector(const sf::Vector2f& vec, float angleRadians)
{
	float cosA = std::cos(angleRadians);
	float sinA = std::sin(angleRadians);
	return sf::Vector2f(
		vec.x * cosA - vec.y * sinA,
		vec.x * sinA + vec.y * cosA
	);
}

void Bullet::UpdateFrameAnimation()
{
	if (!isActive)
		return;

	if (!(animationClock.getElapsedTime().asMilliseconds() > 30))
		return;

	BulletAnimation();
	animationClock.restart();
}

void Bullet::BulletAnimation()
{
	textureRect = bulletSprite.getTextureRect();

	if (intRectPosX >= 320)
		intRectPosX = 320;
	else
		intRectPosX += 160;

	textureRect = sf::IntRect(intRectPosX, 0, 160, 320);
	bulletSprite.setTextureRect(textureRect);
}


void Bullet::SetRotation()
{
	float angleInRadians = std::atan2(bulletDirY, bulletDirX);
	float angleDegrees = angleInRadians * 180 / 3.14159265f;
	bulletSprite.setRotation(angleDegrees + 90);
}

void Bullet::SetPosition()
{
	bulletSprite.setPosition(posX, posY);
}

void Bullet::BulletMovement()
{
	bulletSpeed = initialBulletSpeed;
	bulletSprite.move(bulletDirX * bulletSpeed * Framerate::getDeltaTime(), bulletDirY * bulletSpeed * Framerate::getDeltaTime());
	posX = bulletSprite.getPosition().x;
	posY = bulletSprite.getPosition().y;
}

void Bullet::BulletTimer()
{
	if (timer->getElapsedTime().asSeconds() > BULLET_LIFETIME)
	{
		bulletSprite.setTextureRect(sf::IntRect(0, 0, 160, 320));
		isActive = false;
	}
}

void Bullet::Update()
{
	if (!isActive)
		return;
	BulletMovement();
	BulletTimer();
	WrapAroundScreen(posX, posY, bulletDirX, bulletDirY, 5.0f, bulletSprite);
	UpdateFrameAnimation();

}

void Bullet::Draw(sf::RenderWindow& window)
{
	if (!isActive)
		return;
	window.draw(bulletSprite);
	window.draw(debugCircle);
}

void Bullet::SetBulletSprite(bool isActive)
{
	this->isActive = isActive;

	if (!isActive)
	{
		bulletSprite.setPosition(-100, -100);
		bulletSpeed = 0.0f;
	}
}

void Bullet::ChangeTexture(BulletType bulletType)
{
	if (this->bulletType == bulletType)
		return;

	switch (bulletType)
	{
	case BulletType::Normal:
		this->bulletType = bulletType;
		bulletSprite.setTexture(*bulletTexture);
		break;
	case BulletType::Red:
		this->bulletType = bulletType;
		bulletSprite.setTexture(*bulletRedTexture);
		break;
	default:
		break;
	}
}
