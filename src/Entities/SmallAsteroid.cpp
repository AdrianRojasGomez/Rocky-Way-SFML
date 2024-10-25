#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/RandomUtility.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->wrapOffset = 5.0f;
	this->hitzoneHeight = 0.9f;
	this->hitzoneWidth = 0.9;
	this->initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	this->multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}
