#include<iostream>
#include "SplashScreen.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

SplashScreen::SplashScreen(GameState* gameState)
{
	this->gameState = gameState;
	splashTexture = ResourceManager::getInstance().GetSplashTexture();
	enterTexture = ResourceManager::getInstance().GetEnterUITexture();
	powerUpTexture = ResourceManager::getInstance().GetPowerUpTexture();
	InitializeBackground();
	InitializeEnter();
	InitializePowerUp();
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
	UpdateAnimation();
	CheckSplashTime();
}

void SplashScreen::Draw(sf::RenderWindow& window)
{
	window.draw(splashSprite);
	window.draw(enterSprite);
	window.draw(powerUpSprite);
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

void SplashScreen::InitializeEnter()
{
	if (enterTexture != nullptr)
	{
		sf::IntRect rect(0, 0, 96, 96);
		float scale = 1.0f;
		enterSprite.setTexture(*enterTexture);
		enterSprite.setTextureRect(rect);
		enterSprite.setScale(scale, scale);
		sf::FloatRect bounds = enterSprite.getLocalBounds();
		enterSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		enterSprite.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.80, ScreenResolution::SCREEN_HEIGHT_720P * 0.84);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING ENTER TEXTURE" << std::endl;
}

void SplashScreen::InitializePowerUp()
{
	if (enterTexture != nullptr)
	{
		sf::IntRect rect(0, 0, 128, 128);
		float scale = 1.0f;
		powerUpSprite.setTexture(*powerUpTexture);
		powerUpSprite.setTextureRect(rect);
		powerUpSprite.setScale(scale, scale);
		sf::FloatRect bounds = powerUpSprite.getLocalBounds();
		powerUpSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
		powerUpSprite.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.81, ScreenResolution::SCREEN_HEIGHT_720P * 0.58);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING ENTER TEXTURE" << std::endl;
}

void SplashScreen::SkipSplash()
{
	*gameState = GameState::MainMenu;
}

void SplashScreen::UpdateAnimation()
{
	if (animTime.getElapsedTime().asMilliseconds() > 200)
	{
		intRectEnter = enterSprite.getTextureRect().left;

		if (intRectEnter == 0)
			intRectEnter = 96;
		else
			intRectEnter = 0;

		enterSprite.setTextureRect(sf::IntRect(intRectEnter, 0, 96, 96));

		intRectPower = powerUpSprite.getTextureRect().left;

		if (intRectPower >= 384)
			intRectPower = 0;
		else
			intRectPower += 128;

		powerUpSprite.setTextureRect(sf::IntRect(intRectPower, 0, 128, 128));


		animTime.restart();
	}
}

void SplashScreen::CheckSplashTime()
{
	if (splashTime.getElapsedTime().asSeconds() > splashTimer)
		SkipSplash();
}
