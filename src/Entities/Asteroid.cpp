#include "Asteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/Framerate.h"

Asteroid::Asteroid()
{
	InitDir();
}

void Asteroid::LoadTexture()
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
		this->dirX = std::cos(rotation * 3.14159265f / 180.0f);
		this->rotation = RandomizeIntValues(360, 1);
		this->dirY = std::sin(rotation * 3.14159265f / 180.0f);
		std::cout << "DirX :" << dirX << "  DirY: " << dirY << std::endl;

		if (dirX != 0 && dirY != 0)
			isAssigned = true;

	} while (!isAssigned);
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
	asteroidSprite.rotate(-rotationSpeed * sizeMultiplierRotation * Framerate::getDeltaTime());
	asteroidSprite.move(dirX * speed * sizeMultiplierSpeed * Framerate::getDeltaTime(), dirY * speed * sizeMultiplierSpeed * Framerate::getDeltaTime());
	this->posX = asteroidSprite.getPosition().x;
	this->posY = asteroidSprite.getPosition().y;

}

void Asteroid::Deactivate()
{

}

void Asteroid::Update()
{
	Move();
	WrapAroundScreen(posX, posY, 1280, 720);
	asteroidSprite.setPosition(posX, posY);
}

void Asteroid::Draw(sf::RenderWindow& window)
{
	window.draw(asteroidSprite);
}


