#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->sizeMultiplierSpeed = RandomizeFloatValues(minSpeed, maxspeed);
	this->sizeMultiplierRotation = RandomizeIntValues(maxRotation, minRotation);
	LoadTexture();
	this->isActive = true;
}
