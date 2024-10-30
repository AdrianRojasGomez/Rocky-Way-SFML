#include "LargeAsteroid.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities//RandomUtility.h"

LargeAsteroid::LargeAsteroid()
{
	this->asteroidTexture = ResourceManager::GetLargeAsteroidTexture();
	this->hitzoneSizeMultiplier = 0.4f;
	this->wrapOffset = 35.0f;
	this->initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	this->multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	this->isActive = false;
}



