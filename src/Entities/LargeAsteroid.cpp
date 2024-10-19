#include "LargeAsteroid.h"

LargeAsteroid::LargeAsteroid()
{

	Asteroid::LoadTexture(spritePath);
	this->sizeMultiplierSpeed = RandomizeFloatValues(0.2f, 0.7f);
	this->sizeMultiplierRotation = RandomizeIntValues(4, 1);
}



