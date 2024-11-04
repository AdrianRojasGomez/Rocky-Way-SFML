#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Menu::Menu(GameState* gameState)
{
	this->gameState = gameState;
	menuBackgroundTexture = ResourceManager::getInstance().GetMenuBackgroundTexture();
	menuFont = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	InitializeBackground();
	CreateTitle();
	InitializeButtons();
}

Menu::~Menu()
{
}

void Menu::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
			SelectButton();

		if (event.key.code == sf::Keyboard::Up)
		{
			selectedIndex = (selectedIndex + 3) % 4;
		}
		if (event.key.code == sf::Keyboard::Down)
		{
			selectedIndex = (selectedIndex + 1) % 4;
		}

		if (event.key.code == sf::Keyboard::Right)
		{
			selectedIndex = (selectedIndex + 2) % 4;
		}

		if (event.key.code == sf::Keyboard::Left)
		{
			if (selectedIndex % 2 == 0)
				selectedIndex = 2 - selectedIndex;
			else
				selectedIndex = 4 - selectedIndex;
		}

	}
}

void Menu::InitializeBackground()
{
	if (menuBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = menuBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		menuBackgroundSprite.setTexture(*menuBackgroundTexture);
		menuBackgroundSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Menu::CreateTitle()
{
	gameTitle.setFont(*menuFont);
	gameTitle.setString(TITLE);
	gameTitle.setCharacterSize(130);
	gameTitle.setFillColor(sf::Color::White);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setOutlineThickness(3.0f);
	gameTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P / 4, 50);
}

void Menu::InitializeButtons()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		menuButtons[i].setFont(*menuFont);
		menuButtons[i].setString(MENU_BUTTONS_LABELS[i]);
		menuButtons[i].setCharacterSize(i == 0 ? playButtonSize : otherButtonsSize);
		menuButtons[i].setFillColor(sf::Color::White);

		float posX = 0, posY = 0;
		if (i <= 1)
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.22f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.65f) + i * 90;
		}
		else
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.70f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.68f) + (i - 2) * 55;
		}
		menuButtons[i].setPosition(sf::Vector2f(posX, posY));
	}
}

void Menu::UpdateSelectedButton()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		if (i == selectedIndex)
		{
			menuButtons[i].setFillColor(sf::Color::Yellow);
			menuButtons[i].setOutlineColor(sf::Color::Black);
			menuButtons[i].setOutlineThickness(0.5f);
			menuButtons[i].setCharacterSize(i == 0 ? playButtonSize + 10 : otherButtonsSize + 10);
		}
		else
		{
			menuButtons[i].setCharacterSize(i == 0 ? playButtonSize : otherButtonsSize);
			menuButtons[i].setFillColor(sf::Color::White);
			menuButtons[i].setOutlineThickness(0);
			menuButtons[i].setOutlineColor(sf::Color::Transparent);
		}
	}

}

void Menu::SelectButton()
{
		switch (selectedIndex)
		{
		case 0:
			*gameState = GameState::Gameplay;
			break;
		case 1:
			*gameState = GameState::HighScores;
			break;
		case 2:
			*gameState = GameState::Options;
			break;
		case 3:
			*gameState = GameState::ExitGame;
			break;
		default:
			break;
		}
}

void Menu::Update()
{
	UpdateSelectedButton();
}

void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(menuBackgroundSprite);
	window.draw(gameTitle);
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
		window.draw(menuButtons[i]);
}

void Menu::ResetState()
{
	 *gameState = GameState::MainMenu; 
}
