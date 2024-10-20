#include "WrappingScreenUtility.h"

void WrapAroundScreen(float& x, float& y, float screenWidth, float screenHeight, float offset)
{
	if (x < - offset)
		x = screenWidth;
	else if (x > screenWidth + offset)
		x = 0;

	if (y < - offset)
		y = screenHeight;
	else if (y > screenHeight + offset)
		y = 0;
}