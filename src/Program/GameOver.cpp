#include <iostream>
#include "GameOver.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

GameOver::GameOver(GameState* gameState)
{
	this->gameState = gameState;
	GameOverBackgroundTexture = ResourceManager::getInstance().GetMenuBackgroundTexture();
	menuFont = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
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
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			if (selectedIndex == 0)
				selectedIndex = 1;

			else
				selectedIndex = 0;
		}
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
	CenterTextOrigin(gameOverTitle);
	gameOverTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, ScreenResolution::SCREEN_HEIGHT_720P * 0.25f);
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
		if (i == 0)
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.5f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.60f);
		}
		else
		{
			posX = ScreenResolution::SCREEN_WIDTH_720P * 0.5f;
			posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.75f);
		}
		CenterTextOrigin(menuButtons[i]);
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
			CenterTextOrigin(menuButtons[i]);
		}
		else
		{
			menuButtons[i].setCharacterSize(i == 0 ? replayButtonSize : otherButtonsSize);
			CenterTextOrigin(menuButtons[i]);
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
		isMenu = false;
		selectedIndex = 0;
		canChange = false;
		break;
	case 1:
		*gameState = GameState::Replay;
		isMenu = true;
		selectedIndex = 0;
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

void GameOver::CenterTextOrigin(sf::Text& textToCenter)
{
	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width / 2, rc.height / 2);

}

