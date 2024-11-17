#pragma once
#include "Asteroid.h"

class LargeAsteroid : public Asteroid
{
public:
	LargeAsteroid();


private:
	float minSpeed = 2.0f;
	float maxspeed = 2.5f;
	int minRotation = -10;
	int maxRotation = 10;
	float minScale = 0.6f;
	float maxScale = 1.4f;
};
