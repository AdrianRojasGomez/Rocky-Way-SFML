#include <iostream>
#include "HighScore.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"



HighScore::HighScore(GameState* gameState)
{
	this->gameState = gameState;
	highScoreBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	font = ResourceManager::GetOxaniumSemiBoldFont();
	FetchHighScoreList();
	InitializeHighScoreScreen();
	InitializeTitle();
	InitializeRanking();
	InitializeButton();
	InitializeLabels();
	InitializeLoadedItems();
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
	CenterTextOrigin(highScoreTitle);
	highScoreTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, 50);
}

void HighScore::InitializeRanking()
{
	for (int i = 0; i < RANKING_AMOUNT; i++)
	{
		rankingPositionsText[i].setFont(*font);
		rankingPositionsText[i].setString(RANKING_NUMBER[i]);
		rankingPositionsText[i].setCharacterSize(40);
		rankingPositionsText[i].setFillColor(sf::Color::White);
		rankingPositionsText[i].setOutlineThickness(1.0f);
		rankingPositionsText[i].setStyle(sf::Text::Italic);
		CenterTextOrigin(rankingPositionsText[i]);
		float posX = 0, posY = 0;
		posX = ScreenResolution::SCREEN_WIDTH_720P * 0.30f;
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.35f) + i * 55;
		rankingPositionsText[i].setPosition(sf::Vector2f(posX, posY));
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
	CenterTextOrigin(menuButton);
	menuButton.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, 650);
}

void HighScore::InitializeLoadedItems()
{
	for (int i = 0; i < RANKING_AMOUNT; i++)
	{
		rankingNames[i].setString(highScoresList[i].name);
		ModifyLoadedTextProperties(rankingNames[i]);
		CenterTextOrigin(rankingNames[i]);
		rankingScore[i].setString(std::to_string(highScoresList[i].score));
		ModifyLoadedTextProperties(rankingScore[i]);
		CenterTextOrigin(rankingScore[i]);
		rankingMaxWave[i].setString(std::to_string(highScoresList[i].maxWave));
		ModifyLoadedTextProperties(rankingMaxWave[i]);
		CenterTextOrigin(rankingMaxWave[i]);
		float posX = 0, posY = 0;
		posX = ScreenResolution::SCREEN_WIDTH_720P * 0.40f;
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.35f) + i * 55;
		rankingNames[i].setPosition(sf::Vector2f(posX, posY));
		rankingScore[i].setPosition(sf::Vector2f(posX + 200, posY));
		rankingMaxWave[i].setPosition(sf::Vector2f(posX + 400, posY));

	}
	std::cout << "strings loaded\n";
}

void HighScore::InitializeLabels()
{
	for (int i = 0; i < LABEL_AMOUNT; i++)
	{
		rankingLabelsText[i].setString(RANKING_LABELS[i]);
		ModifyLoadedTextProperties(rankingLabelsText[i]);
		rankingLabelsText[i].setCharacterSize(30);
		rankingLabelsText[i].setOutlineColor(sf::Color::Transparent);
		CenterTextOrigin(rankingLabelsText[i]);
		float posX = 0, posY = 0;
		posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.40f) + i * 200;
		posY = ScreenResolution::SCREEN_HEIGHT_720P * 0.25f;
		rankingLabelsText[i].setPosition(sf::Vector2f(posX, posY));

	}

}

void HighScore::ModifyLoadedTextProperties(sf::Text& text)
{
	text.setFont(*font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setOutlineThickness(1.5);
	text.setStyle(sf::Text::Bold);

	if (text.getString() == ScoreManager::getInstance().GetName())
	{
		text.setFillColor(sf::Color::Yellow);
		text.setOutlineThickness(2);
		text.setOutlineColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold);
	}
}



void HighScore::SelectButton()
{
	hasHighscoresUpdated = false;
	std::cout << "hasUpdated Hs?" << hasHighscoresUpdated;
	*gameState = GameState::MainMenu;
}

void HighScore::CenterTextOrigin(sf::Text& textToCenter)
{
	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width / 2, rc.height / 2);
}

void HighScore::FetchHighScoreList()
{
	highScoresList = ScoreManager::getInstance().GetHighScoresList();
	hasHighscoresUpdated = true;
}

void HighScore::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Enter)
			SelectButton();
	}
}

void HighScore::Update()
{
	if (!hasHighscoresUpdated)
	{
		FetchHighScoreList();
		InitializeLoadedItems();
	}
}

void HighScore::Draw(sf::RenderWindow& window)
{
	window.draw(highScoreBackgroundSprite);
	window.draw(highScoreTitle);
	for (int i = 0; i < RANKING_AMOUNT; i++)
	{
		window.draw(rankingPositionsText[i]);
		window.draw(rankingNames[i]);
		window.draw(rankingScore[i]);
		window.draw(rankingMaxWave[i]);
	}
	for (int i = 0; i < LABEL_AMOUNT; i++)
	{
		window.draw(rankingLabelsText[i]);
	}

	window.draw(menuButton);
}





