#pragma once
#include "Asteroid.h"

class LargeAsteroid : public Asteroid
{
public:
	LargeAsteroid();

private:
	float minSpeed = 0.2f;
	float maxspeed = 0.7f;
	int minRotation = 2;
	int maxRotation = 7;
};
