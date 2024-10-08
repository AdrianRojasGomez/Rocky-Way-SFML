#include <iostream> // for Debug logs currently
#include "Background.h"

Background::Background()
{
	InitializeBackground();
}

void Background::InitializeBackground()
{
	if (backgroundTexture.loadFromFile("res/assets/Background/Background01.png"))
	{
		//TO DO: FIND A WAY TO USE THE WINDOWS SIZE GLOBALLY, IT'S USED IN MANY PLACES
		sf::Vector2u backgroundSize = backgroundTexture.getSize();
		float scaleX = (float)1280 / backgroundSize.x;
		float scaleY = (float)720 / backgroundSize.y;
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(scaleX, scaleY);
		
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}
