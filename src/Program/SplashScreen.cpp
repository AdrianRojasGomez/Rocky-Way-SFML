#include<iostream>
#include "SplashScreen.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

SplashScreen::SplashScreen(GameState* gameState)
{
	this->gameState = gameState;
	splashTexture = ResourceManager::getInstance().GetSplashTexture();
	InitializeBackground();
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
			SkipSplash();
	}
}

void SplashScreen::Update()
{
	if (firstTime)
	{
		firstTime = false;
		splashTime.restart();
	}

	CheckSplashTime();

}

void SplashScreen::Draw(sf::RenderWindow& window)
{
	window.draw(splashSprite);
}

void SplashScreen::InitializeBackground()
{
	if (splashTexture != nullptr)
	{
		sf::Vector2u backgroundSize = splashTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		splashSprite.setTexture(*splashTexture);
		splashSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void SplashScreen::SkipSplash()
{
	*gameState = GameState::MainMenu;
}

void SplashScreen::CheckSplashTime()
{
	if (splashTime.getElapsedTime().asSeconds() > 2.5)
		SkipSplash();

}
