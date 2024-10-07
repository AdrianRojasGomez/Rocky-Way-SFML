#include "WrappingScreenUtility.h"

void WrapAroundScreen(float& x, float& y, float screenWidth, float screenHeight)
{
	if (x < 0)
		x = screenWidth;
	else if (x > screenWidth)
		x = 0;

	if (y < 0)
		y = screenHeight;
	else if (y > screenHeight)
		y = 0;
}