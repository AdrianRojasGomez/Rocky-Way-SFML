#pragma once
#include <SFML/Graphics.hpp>
class GameOver
{
public:
	GameOver();
	void Update();
	void Draw(sf::RenderWindow& window);

	sf::Texture* backgroundTexture = nullptr;
	sf::Font* menuFont = nullptr;
	static constexpr int OPTIONS_AMOUNT = 2;
	const std::string MENU_BUTTONS_LABELS[OPTIONS_AMOUNT] = { "Play Again", "Main Menu" };
	const int playButtonSize = 60;
	sf::Text gameOverTitle;
	sf::Text menuButtons[OPTIONS_AMOUNT];


};