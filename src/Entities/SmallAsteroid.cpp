#include "SmallAsteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/RandomUtility.h"


SmallAsteroid::SmallAsteroid()
{
	this->asteroidTexture = ResourceManager::GetSmallAsteroidTexture();
	this->hitzoneSizeMultiplier = 0.3f;
	this->wrapOffset = 3.0f;
	this->initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	this->multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}
