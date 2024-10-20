#pragma once
#include "Asteroid.h"

class SmallAsteroid : public Asteroid
{
public:
	SmallAsteroid();


private:
	float minSpeed = 1.0f;
	float maxspeed = 3.0f;
	int minRotation = 2;
	int maxRotation = 5;
};

