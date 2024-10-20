#include <iostream>
#include "Background.h"
#include "../Utilities/ResourceManager.h"


Background::Background()
{
	this->backgroundTexture = ResourceManager::GetBackgroundTexture();
	InitializeBackground();
}

void Background::InitializeBackground()
{
	if (backgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = backgroundTexture->getSize();
		float scaleX = (float)1280 / backgroundSize.x;
		float scaleY = (float)720 / backgroundSize.y;
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
