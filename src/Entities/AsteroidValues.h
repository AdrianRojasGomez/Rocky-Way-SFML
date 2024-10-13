#pragma once
#include "Asteroid.h"
#include <cstdlib>

class AsteroidValues
{
public:
	AsteroidValues();


private:
	float minSize = 0.0f;
	float maxSize = 0.0f;
	float minSpeed = 0.0f;
	float maxSpeed = 0.0f;

	void ReadCSV();
};
