#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/RandomUtility.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	this->multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}
