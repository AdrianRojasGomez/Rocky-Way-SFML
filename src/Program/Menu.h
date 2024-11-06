#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"


class Menu
{
public:
	Menu(GameState* gameState);
	~Menu();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	void ResetState();

private:
	static constexpr int OPTIONS_AMOUNT = 4;
	const std::string TITLE = "Rocky Way";
	const std::string MENU_BUTTONS_LABELS[OPTIONS_AMOUNT] = { "PLAY", "Highscore", "Settings", "Quit" };
	const int playButtonSize = 60;
	const int otherButtonsSize = 35;
	GameState* gameState;
	sf::Text menuButtons[OPTIONS_AMOUNT];
	sf::Texture* menuBackgroundTexture = nullptr;
	sf::Sprite menuBackgroundSprite;
	sf::Font* menuFont = nullptr;
	sf::Text gameTitle;

	int selectedIndex = 0;

	void InitializeBackground();
	void CreateTitle();
	void InitializeButtons();
	void UpdateSelectedButton();
	void SelectButton();
	void CheckForDirectionalInput(sf::Event event);
	void CenterTextOrigin(sf::Text& textToCenter);
	
};