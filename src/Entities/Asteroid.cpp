#include <iostream>
#include "Asteroid.h"



Asteroid::Asteroid()
{
	SelectAsteroidType(asteroidSize);
}

void Asteroid::SelectAsteroidType(Size asteroidSize)
{
	switch (asteroidSize)
	{
	case Asteroid::Unselected:
		std::cout << "Error, no Asteroid Size selected\n";
		break;
	case Asteroid::Large:
		this->asteroidSize = asteroidSize;
		break;
	case Asteroid::Medium:
		this->asteroidSize = asteroidSize;
		break;
	case Asteroid::Small:
		this->asteroidSize = asteroidSize;
		break;
	case Asteroid::Error:
		std::cout << "Error, wrong Asteroid Size selected\n";

		break;
	default:
		std::cout << "Error, Default switch selected\n";

		break;
	}
}


void Asteroid::LoadAsteroidTexture()
{

	if (asteroidTexture.loadFromFile("res/assets/Traces/BasicShot.png"))
	{
		asteroidSprite.setTexture(asteroidTexture);
		asteroidSprite.setScale(scaleX, scaleY);
		sf::FloatRect bounds = asteroidSprite.getLocalBounds();
		asteroidSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING ASTEROID TEXTURE" << std::endl;
}