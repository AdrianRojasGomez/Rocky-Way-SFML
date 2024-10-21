#include "LargeAsteroid.h"
#include "../Utilities/ResourceManager.h"

LargeAsteroid::LargeAsteroid()
{
	this->asteroidTexture = ResourceManager::GetLargeAsteroidTexture();
	this->hitzoneHeight = 0.8f;
	this->hitzoneWidth  = 0.8f;
	this->multiplierSpeed = RandomizeFloatValues(minSpeed, maxspeed);
	this->multiplierRotation = RandomizeIntValues(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = true;
}



