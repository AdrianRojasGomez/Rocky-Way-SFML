#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "../Utilities/ScoreManager.h"

class HighScore
{
public:
	HighScore(GameState* gameState);
	~HighScore();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	static constexpr int RANKING_AMOUNT = 6;
	static constexpr int LABEL_AMOUNT = 3;
	const std::string TITLE = "HIGHSCORES";
	const std::string BUTTON_LABEL = "Main Menu";
	const std::string RANKING_NUMBER[RANKING_AMOUNT] = { "1.","2.","3.","4.","5.","6." };
	const std::string RANKING_LABELS[RANKING_AMOUNT] = { "ID","SCORE","WAVE"};
	const int playButtonSize = 40;
	bool hasHighscoresUpdated = false;
	GameState* gameState;
	std::vector<HighScoresValues> highScoresList;
	sf::Text highScoreTitle;
	sf::Text rankingLabelsText[LABEL_AMOUNT];
	sf::Text rankingPositionsText[RANKING_AMOUNT];
	sf::Text rankingNames[RANKING_AMOUNT];
	sf::Text rankingScore[RANKING_AMOUNT];
	sf::Text rankingMaxWave[RANKING_AMOUNT];
	sf::Text menuButton;
	sf::Texture* highScoreBackgroundTexture = nullptr;
	sf::Sprite highScoreBackgroundSprite;
	sf::Font* font = nullptr;

	sf::Text loadedName[RANKING_AMOUNT];
	sf::Text loadedScore[RANKING_AMOUNT];
	sf::Text loadedMaxWave[RANKING_AMOUNT];



	void InitializeHighScoreScreen();
	void InitializeTitle();
	void InitializeRanking();
	void InitializeButton();
	void InitializeLoadedItems();
	void InitializeLabels();
	void ModifyLoadedTextProperties(sf::Text& text);
	void FetchHighScoreList();
	void SelectButton();
	void CenterTextOrigin(sf::Text& textToCenter);
};