#include "LargeAsteroid.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities//RandomUtility.h"

LargeAsteroid::LargeAsteroid()
{
	asteroidTexture = ResourceManager::getInstance().GetLargeAsteroidTexture();
	hitzoneSizeMultiplier = 0.4f;
	scale = RandomUtility::GetRandomFloat(maxScale, minScale);
	wrapOffset = 35.0f;
	initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	isActive = false;
}



