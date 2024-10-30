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
	std::string waveNumberString = "";
	std::vector<sf::CircleShape*> hpUI;
	sf::Font* uiFont;
	sf::Text waveTitle;
	sf::Text waveNumber;
	int maxHP = 0;
	int HP = 0;
	bool isInitialized = false;


	void InitializeUI(int HP);
	void UpdateUIHealth();
};