#pragma once
#include "Asteroid.h"

class SmallAsteroid : public Asteroid
{
public:
	SmallAsteroid();


private:
	float minSpeed = 1.8f;
	float maxspeed = 2.6f;
	int minRotation = -10;
	int maxRotation = 10;
	float minScale = 0.3f;
	float maxScale = 1.0f;
};

