#include "Asteroid.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ScreenResolution.h"
#include "../Utilities/RandomUtility.h"

Asteroid::Asteroid()
{
	asteroidHitZone = new sf::FloatRect;
	InitPosition();
	InitDirection();

}

Asteroid::~Asteroid()
{
	if (asteroidHitZone != nullptr)
	{
		delete asteroidHitZone;
		asteroidHitZone == nullptr;
	}
}

void Asteroid::SetTextureValues()
{
	if (asteroidTexture != nullptr)
	{
		asteroidSprite.setTexture(*asteroidTexture);
		asteroidSprite.setScale(scaleX, scaleY);
		sf::FloatRect bounds = asteroidSprite.getLocalBounds();
		asteroidSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		this->posX = asteroidSprite.getPosition().x;
		this->posY = asteroidSprite.getPosition().y;
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! NULL TEXTURE" << std::endl;
}


void Asteroid::InitDirection()
{
	sf::Vector2f vScreenCenter = ScreenResolution::GetScreenCenter720();
	this->dirX = (vScreenCenter.x + RandomUtility::GetRandomInt(300, 100)) - posX;
	this->dirY = (vScreenCenter.y + RandomUtility::GetRandomInt(300, 100)) - posY;
	float magnitude = std::sqrt(dirX * dirX + dirY * dirY);
	if (magnitude != 0)
	{
		this->dirX /= magnitude;
		this->dirY /= magnitude;
	}
}

void Asteroid::InitPosition()
{
	InitialPosition initialPosition = (InitialPosition)RandomUtility::GetRandomInt((int)InitialPosition::EAST, (int)InitialPosition::NORTH);
	float initPosX = 0;
	float initPosY = 0;
	switch (initialPosition)
	{
	case InitialPosition::UNASSIGNED:
		std::cout << "Error UNASSIGNED" << std::endl;
		break;
	case InitialPosition::NORTH:
		initPosX = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_WIDTH_720P, 1);
		initPosY = -300;
		asteroidSprite.setPosition(initPosX, initPosY);
		break;
	case InitialPosition::WEST:
		initPosX = ScreenResolution::SCREEN_WIDTH_720P + 300;
		initPosY = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_HEIGHT_720P, 1);
		asteroidSprite.setPosition(initPosX, initPosY);
		break;
	case InitialPosition::SOUTH:
		initPosX = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_WIDTH_720P, 1);
		initPosY = ScreenResolution::SCREEN_HEIGHT_720P + 300;
		asteroidSprite.setPosition(initPosX, initPosY);
		break;
	case InitialPosition::EAST:
		initPosX = -300;
		initPosY = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_HEIGHT_720P, 1);
		asteroidSprite.setPosition(initPosX, initPosY);
		break;
	default:
		std::cout << "Error Default Case" << std::endl;
		break;
	}
	this->posX = initPosX;
	this->posY = initPosY;


	*asteroidHitZone = asteroidSprite.getGlobalBounds();
	asteroidHitZone->height = asteroidSprite.getGlobalBounds().height;
	asteroidHitZone->width = asteroidSprite.getGlobalBounds().width;
	asteroidHitZone->height *= hitzoneSizeMultiplier;
	asteroidHitZone->width *= hitzoneSizeMultiplier;
}

void Asteroid::Move()
{
	asteroidSprite.rotate(-rotationSpeed * multiplierRotation * Framerate::getDeltaTime());
	asteroidSprite.move(dirX * speed * initialMultiplierSpeed * Framerate::getDeltaTime(), dirY * speed * initialMultiplierSpeed * Framerate::getDeltaTime());
	this->posX = asteroidSprite.getPosition().x;
	this->posY = asteroidSprite.getPosition().y;
	sf::Vector2f originOffset = asteroidSprite.getOrigin() * hitzoneSizeMultiplier;
	asteroidHitZone->left = posX - originOffset.x;
	asteroidHitZone->top = posY - originOffset.y;
	
}

void Asteroid::SetIsActive(bool isActive)
{
	this->isActive = isActive;

	if (!isActive)
	{
		this->asteroidSprite.setPosition(-1000, 1000);
		*asteroidHitZone = asteroidSprite.getGlobalBounds();
		this->currentSpeed = 0.0f;
	}

	if (isActive)
	{
		this->currentSpeed = initialMultiplierSpeed;
		InitPosition();
		InitDirection();
	}
}

void Asteroid::SetNewDebrisPosition(sf::Vector2f pos)
{
	this->asteroidSprite.setPosition(pos);
}

void Asteroid::Update()
{
	Move();
	WrapAroundScreen(posX, posY, dirX, dirY, wrapOffset, asteroidSprite);
}

void Asteroid::Draw(sf::RenderWindow& window)
{
	window.draw(asteroidSprite);

	///DEBUG ONLY
	///window.draw(DebugHitzone());
}

sf::RectangleShape Asteroid::DebugHitzone()
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(2.5f);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setSize(sf::Vector2f(asteroidHitZone->width, asteroidHitZone->height));
	rectangle.setPosition(asteroidHitZone->left, asteroidHitZone->top);

	return rectangle;
}

