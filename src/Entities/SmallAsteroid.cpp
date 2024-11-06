#include "SmallAsteroid.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/RandomUtility.h"


SmallAsteroid::SmallAsteroid()
{
	asteroidTexture = ResourceManager::getInstance().GetSmallAsteroidTexture();
	hitzoneSizeMultiplier = 0.3f;
	impactFrames = 20;
	scale = RandomUtility::GetRandomFloat(maxScale, minScale);
	wrapOffset = 3.0f;
	initialMultiplierSpeed = RandomUtility::GetRandomFloat(minSpeed, maxspeed);
	multiplierRotation = RandomUtility::GetRandomInt(maxRotation, minRotation);
	SetTextureValues();
	isActive = false;
}
