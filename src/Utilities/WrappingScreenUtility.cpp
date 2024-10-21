#include "WrappingScreenUtility.h"
#include "../Utilities/ScreenResolution.h"

void WrapAroundScreen(float& x, float& y, float offset)
{
	if (x < - offset)
		x = ScreenResolution::SCREEN_WIDTH_720P;
	else if (x > ScreenResolution::SCREEN_WIDTH_720P + offset)
		x = 0;

	if (y < - offset)
		y = ScreenResolution::SCREEN_HEIGHT_720P;
	else if (y > ScreenResolution::SCREEN_HEIGHT_720P + offset)
		y = 0;
}