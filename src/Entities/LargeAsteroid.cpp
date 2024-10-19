#include "LargeAsteroid.h"
#include "../Utilities/ResourceManager.h"

LargeAsteroid::LargeAsteroid()
{
	this->asteroidTexture = ResourceManager::GetLargeAsteroidTexture();
	this->sizeMultiplierSpeed = RandomizeFloatValues(0.2f, 0.7f);
	this->sizeMultiplierRotation = RandomizeIntValues(4, 1);
	LoadTexture();
}



