#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
class Pause
{
public:
	Pause(GameState* gameState);
	~Pause();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	bool GetIsReset() { return isReset; }
	void SetIsReset(bool isReset) { this->isReset = isReset; }

private:
	static constexpr int OPTIONS_AMOUNT = 2;
	GameState* gameState;
	const std::string pauseTitleString = "PAUSE";
	const std::string PAUSE_BUTTONS_LABELS[OPTIONS_AMOUNT] = { "Resume Game", "Main Menu" };
	const int playButtonSize = 40;
	const int otherButtonsSize = 35;
	sf::Font* menuFont = nullptr;
	sf::Text pauseTitleText;
	sf::Text menuButtons[OPTIONS_AMOUNT];

	int selectedIndex = 0;
	bool isReset = false;

	void InitializeTitle();
	void InitializeButtons();
	void UpdateSelectedButton();
	void SelectButton();
	void CheckForDirectionalInput(sf::Event event);
	void CenterTextOrigin(sf::Text& textToCenter);


};