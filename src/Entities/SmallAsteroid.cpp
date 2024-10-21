#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->multiplierSpeed = RandomizeFloatValues(minSpeed, maxspeed);
	this->multiplierRotation = RandomizeIntValues(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}
