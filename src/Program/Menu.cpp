#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Menu::Menu()
{
	//menuBackgroundTexture = new sf::Texture;
	//gameTitle = new sf::Text();
	titleFont = new sf::Font();
	this->menuBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	this->titleFont = ResourceManager::GetOxaniumSemiBoldFont();
	//InitializeBackground();
	//CreateTitle();
}

Menu::~Menu()
{
	if (menuBackgroundTexture != nullptr)
	{
		delete menuBackgroundTexture;
		menuBackgroundTexture = nullptr;
	}

	if (titleFont != nullptr)
	{
		delete titleFont;
		titleFont = nullptr;
	}

	if (gameTitle != nullptr)
	{
		delete gameTitle;
		gameTitle = nullptr;
	}
}

void Menu::InitializeBackground()
{
	if (menuBackgroundTexture != nullptr)
	{
		//sf::Vector2u backgroundSize = menuBackgroundTexture->getSize();
		//float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		//float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		//menuBackgroundSprite.setTexture(*menuBackgroundTexture);
		//menuBackgroundSprite.setScale(scaleX, scaleY);
	}
	//else
		//std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Menu::CreateTitle()
{
	//gameTitle->setFont(*titleFont);
	//gameTitle->setString(TITLE);
	//gameTitle->setCharacterSize(100);
	//gameTitle->setFillColor(sf::Color::White);
	//gameTitle->setStyle(sf::Text::Bold);
	//gameTitle->setPosition(350, 100);
}

void Menu::Update()
{
	//Change the game state:
	//Game::gameState = GameState::Gameplay;
}

void Menu::Draw(sf::RenderWindow& window)
{
	//window.draw(menuBackgroundSprite);
	//window.draw(*gameTitle);
}
