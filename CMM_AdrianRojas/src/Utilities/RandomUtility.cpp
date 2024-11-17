#include <cstdlib>
#include <iostream> // debug
#include "RandomUtility.h"


float RandomUtility::GetRandomFloat(float max, float min)
{
	float randomValue = (float)rand() / (RAND_MAX + 1.0f);
	return min + randomValue * (max - min);
}

float RandomUtility::GetRandomInt(int max, int min)
{

	return rand() % max + min;
}

