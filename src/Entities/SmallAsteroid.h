#pragma once
#include "Asteroid.h"

class SmallAsteroid : public Asteroid
{
public:
	SmallAsteroid();


private:
	float minSpeed = 0.1f;
	float maxspeed = 0.5f;
	int minRotation = 2;
	int maxRotation = 5;
};

