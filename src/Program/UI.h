#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI();
	~UI();
	void Update();
	void Draw(sf::RenderWindow& window);
	void SetUIHP(int playerHP);
	void SetUIWave(int wave);


private:
	const std::string WAVE_TITLE_STRING = "WAVE";
	const std::string SCORE_TITLE_STRING = "SCORE";
	const float SCALE = 0.3f;
	
	std::vector<sf::Sprite> lifeUISprites;
	sf::Clock animationClock;
	sf::Sprite lifeLostUISprite;
	sf::Font* uiFont;
	sf::Text waveTitle;
	sf::Text waveNumber;
	sf::Text scoreTitle;
	sf::Text scoreShown;

	sf::Texture* lifeUITexture = nullptr;
	sf::Texture* lifeLostUITexture = nullptr;
	sf::IntRect lifeIntRect;
	sf::IntRect lifeLostIntRect;
	std::string waveNumberString = "";
	std::string scoreString = "00000";
	int maxHP = 3;
	int HP = 0;
	int score = 0;
	int newScore = 0;
	bool isInitialized = false;


	void InitializeUI();
	void InitializeHealthAndWaveUI();
	void InitializeScoreUI();
	void UpdateHP();
	void UpdateUIScore();
	void UpdateScore();
	void UpdateUIAnimation();
};