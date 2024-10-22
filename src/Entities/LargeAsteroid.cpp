#include "LargeAsteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities//RandomUtility.h"

LargeAsteroid::LargeAsteroid()
{
	this->asteroidTexture = ResourceManager::GetLargeAsteroidTexture();
	this->hitzoneHeight = 0.8f;
	this->hitzoneWidth  = 0.8f;
	this->initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	this->multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}



