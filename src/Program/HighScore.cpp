#include <iostream>
#include "HighScore.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"


HighScore::HighScore()
{
	highScoreBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	font = ResourceManager::GetOxaniumSemiBoldFont();
	InitializeHighScoreScreen();
	InitializeTitle();
	InitializeRanking();
	InitializeButton();
	gameState = GameState::HighScores;

}

HighScore::~HighScore()
{
}

void HighScore::InitializeHighScoreScreen()
{
	if (highScoreBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = highScoreBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		highScoreBackgroundSprite.setTexture(*highScoreBackgroundTexture);
		highScoreBackgroundSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void HighScore::InitializeTitle()
{
	highScoreTitle.setFont(*font);
	highScoreTitle.setString(TITLE);
	highScoreTitle.setCharacterSize(70);
	highScoreTitle.setFillColor(sf::Color::White);
	highScoreTitle.setStyle(sf::Text::Bold);
	highScoreTitle.setOutlineThickness(3.0f);
	highScoreTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.35, 50);
}

void HighScore::InitializeRanking()
{
	for (int i = 0; i < RANKING_AMOUNT; i++)
	{
		rankingNumbersText[i].setFont(*font);
		rankingNumbersText[i].setString(RANKING_NUMBER[i]);
		rankingNumbersText[i].setCharacterSize(45);
		rankingNumbersText[i].setFillColor(sf::Color::White);
		highScoreTitle.setOutlineThickness(3.0f);
		highScoreTitle.setStyle(sf::Text::Italic);
		float posX = 0, posY = 0;
		posX = ScreenResolution::SCREEN_WIDTH_720P * 0.3f;
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.25f) + i * 55;
		rankingNumbersText[i].setPosition(sf::Vector2f(posX, posY));
	}
}

void HighScore::InitializeButton()
{
	menuButton.setFont(*font);
	menuButton.setString(BUTTON_LABEL);
	menuButton.setCharacterSize(playButtonSize);
	menuButton.setFillColor(sf::Color::Yellow);
	menuButton.setOutlineThickness(0.5f);
	menuButton.setOutlineColor(sf::Color::Black);
	menuButton.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.45, 550);
}

void HighScore::SelectButton()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		gameState = GameState::MainMenu;
}

GameState HighScore::Update()
{
	SelectButton();
	return gameState;
}

void HighScore::Draw(sf::RenderWindow& window)
{
	window.draw(highScoreBackgroundSprite);
	window.draw(highScoreTitle);
	for (int i = 0; i < RANKING_AMOUNT; i++)
		window.draw(rankingNumbersText[i]);

	window.draw(menuButton);
}

void HighScore::ResetState()
{
	if (gameState == GameState::HighScores)
		return;

	gameState = GameState::HighScores;
}




