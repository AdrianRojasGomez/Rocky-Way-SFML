#include <iostream>
#include <SFML/Window/Event.hpp>
#include "GameOver.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

GameOver::GameOver(GameState* gameState)
{
	this->gameState = gameState;
	GameOverBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	menuFont = ResourceManager::GetOxaniumSemiBoldFont();
	InitializeBackground();
	CreateTitle();
	InitializeButtons();
}

GameOver::~GameOver()
{
}

void GameOver::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
			SelectButton();

		if (event.key.code == sf::Keyboard::Up)
		{
			if (selectedIndex == 0)
				selectedIndex = 1;
			else
				selectedIndex = 0;

			std::cout << "Up\n";
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			if (selectedIndex == 0)
				selectedIndex = 1;

			else
				selectedIndex = 0;

			std::cout << "Down\n";
		}

			std::cout << "Input\n";
	}
}

void GameOver::InitializeBackground()
{
	if (GameOverBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = GameOverBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		GameOverBackgroundSprite.setTexture(*GameOverBackgroundTexture);
		GameOverBackgroundSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING GAME OVER BACKGROUND TEXTURE" << std::endl;
}

void GameOver::CreateTitle()
{
	gameOverTitle.setFont(*menuFont);
	gameOverTitle.setString(GAME_OVER_TITLE);
	gameOverTitle.setCharacterSize(130);
	gameOverTitle.setFillColor(sf::Color::White);
	gameOverTitle.setStyle(sf::Text::Bold);
	gameOverTitle.setOutlineThickness(3.0f);
	gameOverTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.22f, ScreenResolution::SCREEN_HEIGHT_720P * 0.15f);
}

void GameOver::InitializeButtons()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		menuButtons[i].setFont(*menuFont);
		menuButtons[i].setString(MENU_BUTTONS_LABELS[i]);
		menuButtons[i].setCharacterSize(i == 0 ? replayButtonSize : otherButtonsSize);
		menuButtons[i].setFillColor(sf::Color::White);

		float posX = 0, posY = 0;
		if (i < 1)
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.4f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.50f);
		}
		else
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.40f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.65f);
		}
		menuButtons[i].setPosition(sf::Vector2f(posX, posY));
	}
}

void GameOver::UpdateSelectedButton()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		if (i == selectedIndex)
		{
			menuButtons[i].setFillColor(sf::Color::Yellow);
			menuButtons[i].setOutlineColor(sf::Color::Black);
			menuButtons[i].setOutlineThickness(0.5f);
			menuButtons[i].setCharacterSize(i == 0 ? replayButtonSize + 10 : otherButtonsSize + 10);
		}
		else
		{
			menuButtons[i].setCharacterSize(i == 0 ? replayButtonSize : otherButtonsSize);
			menuButtons[i].setFillColor(sf::Color::White);
			menuButtons[i].setOutlineThickness(0);
			menuButtons[i].setOutlineColor(sf::Color::Transparent);
		}
	}

}

void GameOver::SelectButton()
{
		switch (selectedIndex)
		{
		case 0:
			*gameState = GameState::Replay;
			canChange = false;
			break;
		case 1:
			*gameState = GameState::MainMenu;
			canChange = false;
			break;
		}
}

void GameOver::Update()
{
	UpdateSelectedButton();
}

void GameOver::Draw(sf::RenderWindow& window)
{
	window.draw(GameOverBackgroundSprite);
	window.draw(gameOverTitle);
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
		window.draw(menuButtons[i]);
}


