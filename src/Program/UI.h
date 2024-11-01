#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI();
	~UI();
	void Update();
	void Draw(sf::RenderWindow& window);
	void SetUIHP(int HP);
	void SetUIWave(int wave);


private:
	const std::string WAVE_TITLE_STRING = "WAVE";
	const std::string SCORE_TITLE_STRING = "SCORE";

	std::vector<sf::CircleShape*> hpUI;
	sf::Font* uiFont;
	sf::Text waveTitle;
	sf::Text waveNumber;
	sf::Text scoreTitle;
	sf::Text scoreShown;
	sf::Clock scoreClock;

	std::string waveNumberString = "";
	std::string scoreString = "00000";
	int maxHP = 0;
	int HP = 0;
	int score = 0;
	int newScore = 0;
	bool isInitialized = false;


	void InitializeUI(int HP);
	void InitializeHealthAndWaveUI();
	void InitializeScoreUI();
	void UpdateUIHealth();
	void UpdateUIScore();
	void UpdateScore();
};