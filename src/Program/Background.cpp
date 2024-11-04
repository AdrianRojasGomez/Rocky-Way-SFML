#include <iostream>
#include "Background.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"


Background::Background()
{
	this->backgroundTexture = ResourceManager::getInstance().GetBackgroundTexture();
	InitializeBackground();
}

Background::~Background()
{
}

void Background::InitializeBackground()
{
	if (backgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = backgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		backgroundSprite.setTexture(*backgroundTexture);
		backgroundSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}
