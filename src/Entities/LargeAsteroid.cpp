#include "LargeAsteroid.h"
#include "../Utilities/ResourceManager.h"

LargeAsteroid::LargeAsteroid()
{
	this->asteroidTexture = ResourceManager::GetLargeAsteroidTexture();
	this->sizeMultiplierSpeed = RandomizeFloatValues(minSpeed, maxspeed);
	this->sizeMultiplierRotation = RandomizeIntValues(maxRotation, minRotation);
	LoadTexture();
	this->isActive = true;
}



