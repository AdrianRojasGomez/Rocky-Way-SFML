#include "SmallAsteroid.h"

SmallAsteroid::SmallAsteroid()
{
	Asteroid::LoadTexture(spritePath);
	this->sizeMultiplierSpeed = RandomizeFloatValues(0.3f, 0.9f);
	this->sizeMultiplierRotation = RandomizeIntValues(2, 1);

}
