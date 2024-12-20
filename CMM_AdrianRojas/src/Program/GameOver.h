#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
class GameOver
{
public:
	GameOver(GameState* gameState);
	~GameOver();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	bool GetIsMenu() { return isMenu; }

private:
	static constexpr int OPTIONS_AMOUNT = 2;
	const std::string MENU_BUTTONS_LABELS[OPTIONS_AMOUNT] = { "Play Again", "Main Menu" };
	const std::string GAME_OVER_TITLE = "GAME OVER";
	const int replayButtonSize = 60;
	const int otherButtonsSize = 40;
	sf::Texture* GameOverBackgroundTexture = nullptr;
	sf::Sprite GameOverBackgroundSprite;
	sf::Font* menuFont = nullptr;
	sf::Text gameOverTitle;
	sf::Text menuButtons[OPTIONS_AMOUNT];
	GameState* gameState;

	int selectedIndex = 0;
	bool canChange = false;
	bool isMenu = false;

	void CreateTitle();
	void InitializeBackground();
	void InitializeButtons();
	void UpdateSelectedButton();
	void SelectButton();
	void CenterTextOrigin(sf::Text& textToCenter);
};