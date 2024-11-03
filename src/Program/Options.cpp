#include "Options.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Options::Options(GameState* gameState)
{
	this->gameState = gameState;
	optionsBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	musicOffTexture = ResourceManager::GetMusicOffTexture();
	musicOnTexture = ResourceManager::GetMusicOnTexture();
	InitializeBackground();
	InitializeMusicSprites();

}

Options::~Options()
{
}

void Options::Input(sf::Event event)
{

}

void Options::Update()
{
}

void Options::Draw(sf::RenderWindow& window)
{
	window.draw(optionsBackgroundSprite);
	window.draw(optionTitle);
}

void Options::InitializeBackground()
{
	if (optionsBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = optionsBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		optionsBackgroundSprite.setTexture(*optionsBackgroundTexture);
		optionsBackgroundSprite.setScale(scaleX, scaleY);
	}
}

void Options::InitializeMusicSprites()
{
	if (musicOffTexture != nullptr && musicOnTexture != nullptr)
	{
		musicOffSprite.setTexture(*musicOffTexture);
		musicOnSprite.setTexture(*musicOnTexture);
		///TEST VALUES, CREATE VARIABLE
		musicOffSprite.setScale(10, 10);
		musicOnSprite.setScale(10, 10);
		sf::FloatRect bounds = musicOffSprite.getLocalBounds();
		musicOffSprite.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
		bounds = musicOnSprite.getLocalBounds();
		musicOnSprite.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
	}
}

void Options::InitializeTitle()
{
	optionTitle.setString(OPTION_TITLE);
	optionTitle.setCharacterSize(130);
	optionTitle.setFillColor(sf::Color::White);
	optionTitle.setStyle(sf::Text::Bold);
	optionTitle.setOutlineThickness(3.0f);
	CenterTextOrigin(optionTitle);
	optionTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P / 2, 50);
}

void Options::CenterTextOrigin(sf::Text& textToCenter)
{
	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width / 2, rc.height / 2);
}

