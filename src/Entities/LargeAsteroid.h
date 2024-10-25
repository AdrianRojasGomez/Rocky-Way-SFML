#pragma once
#include "Asteroid.h"

class LargeAsteroid : public Asteroid
{
public:
	LargeAsteroid();


private:
	float minSpeed = .5f;
	float maxspeed = 2.5f;
	int minRotation = 2;
	int maxRotation = 7;
};
