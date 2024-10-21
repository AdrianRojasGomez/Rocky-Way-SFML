#include "Asteroid.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/Framerate.h"

Asteroid::Asteroid()
{
	asteroidHitZone = new sf::FloatRect;
	InitDir();
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


void Asteroid::InitDir()
{
	bool isAssigned = false;
	do
	{
		this->rotation = RandomizeIntValues(360, 1);
		this->dirX = std::cos(rotation * NUM_PI / 180.0f);
		this->rotation = RandomizeIntValues(360, 1);
		this->dirY = std::sin(rotation * NUM_PI / 180.0f);

		if (dirX != 0 && dirY != 0)
			isAssigned = true;

	} while (!isAssigned);
}

void Asteroid::InitPos()
{

}

int Asteroid::RandomizeIntValues(int max, int min)
{
	return rand() % max + min;
}

float Asteroid::RandomizeFloatValues(float max, float min)
{
	float randomValue = (float)rand() / (RAND_MAX + 1.0f);
	return min + randomValue * (max - min);
}

void Asteroid::Move()
{
	asteroidSprite.rotate(-rotationSpeed * multiplierRotation * Framerate::getDeltaTime());
	asteroidSprite.move(dirX * speed * multiplierSpeed * Framerate::getDeltaTime(), dirY * speed * multiplierSpeed * Framerate::getDeltaTime());
	this->posX = asteroidSprite.getPosition().x;
	this->posY = asteroidSprite.getPosition().y;
	asteroidHitZone->height *= hitzoneHeight;
	asteroidHitZone->width *= hitzoneWidth;
}

void Asteroid::Update()
{
	*asteroidHitZone = asteroidSprite.getGlobalBounds();
	Move();
	WrapAroundScreen(posX, posY, 35.0f);
	asteroidSprite.setPosition(posX, posY);
}

void Asteroid::Draw(sf::RenderWindow& window)
{
	window.draw(asteroidSprite);
}

void Asteroid::SetIsActive(bool isActive)
{
	this->isActive = isActive; 

	if (!isActive)
	{
		this->asteroidSprite.setPosition(-1000, 1000);
		*asteroidHitZone = asteroidSprite.getGlobalBounds();
		this->multiplierSpeed = 0.0f;
	}
}


