#include <SFML/Graphics.hpp>
#include "WrappingScreenUtility.h"
#include "../Utilities/ScreenResolution.h"

void WrapAroundScreen(float& posX, float& posY, float dirX, float dirY , float offset, sf::Sprite currentSprite)
{
	if (posX < - offset && dirX < 0)
		posX = ScreenResolution::SCREEN_WIDTH_720P;
	else if (posX > ScreenResolution::SCREEN_WIDTH_720P + offset && dirX > 0)
		posX = 0;

	if (posY < - offset && dirY < 0)
		posY = ScreenResolution::SCREEN_HEIGHT_720P;
	else if (posY > ScreenResolution::SCREEN_HEIGHT_720P + offset && dirY > 0)
		posY = 0;

	currentSprite.setPosition(posX, posY);
}