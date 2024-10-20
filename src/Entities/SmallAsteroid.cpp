#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->sizeMultiplierSpeed = RandomizeFloatValues(0.3f, 0.9f);
	this->sizeMultiplierRotation = RandomizeIntValues(2, 1);
	LoadTexture();
	this->isActive = true;
}
