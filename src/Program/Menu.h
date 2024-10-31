#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Menu
{
public:
	Menu();
	~Menu();
	GameState Update();
	void Draw(sf::RenderWindow& window);

private:
	static constexpr int OPTIONS_AMOUNT = 4;
	const std::string TITLE = "Rocky Way";
	const std::string MENU_BUTTONS_LABELS[OPTIONS_AMOUNT] = { "Play", "Highscore", "Options", "Quit" };
	const int playButtonSize = 60;
	const int otherButtonsSize = 35;
	GameState gameState;
	sf::Text menuButtons[OPTIONS_AMOUNT];
	sf::Texture* menuBackgroundTexture = nullptr;
	sf::Sprite menuBackgroundSprite;
	sf::Font* menuFont = nullptr;
	sf::Text gameTitle;
	sf::Clock cdClock;

	int selectedIndex = 0;
	bool canChange = true;

	void InitializeBackground();
	void CreateTitle();
	void InitializeButtons();
	void UpdateSelectedButton();
	void ChangeButton();
	bool ButtonCooldown(bool& canChange);
	void SelectButton();
	void CloseProgram(sf::RenderWindow& window);
};