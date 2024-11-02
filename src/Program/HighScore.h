#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "../Utilities/ScoreManager.h"

class HighScore
{
public:
	HighScore();
	~HighScore();
	GameState Update();
	void Draw(sf::RenderWindow& window);
	void ResetState();

private:
	static constexpr int RANKING_AMOUNT = 6;
	const std::string TITLE = "HIGHSCORES";
	const std::string BUTTON_LABEL = "Main Menu";
	const std::string RANKING_NUMBER[RANKING_AMOUNT] = { "1.","2.","3.","4.","5.","6." };
	const int playButtonSize = 40;
	GameState gameState;
	std::vector<HighScoresValues> highScoresList;
	sf::Text highScoreTitle;
	sf::Text rankingNumbersText[RANKING_AMOUNT];
	sf::Text rankingNames[RANKING_AMOUNT];
	sf::Text rankingScore[RANKING_AMOUNT];
	sf::Text rankingMaxWave[RANKING_AMOUNT];
	sf::Text menuButton;
	sf::Texture* highScoreBackgroundTexture = nullptr;
	sf::Sprite highScoreBackgroundSprite;
	sf::Font* font = nullptr;

	void InitializeHighScoreScreen();
	void InitializeTitle();
	void InitializeRanking();
	void InitializeButton();
	void SelectButton();
	void FetchHighScoreList();
};