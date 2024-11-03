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

private:
	GameState* gameState;
	const std::string pauseTitleString = "PAUSE";
	sf::Font* menuFont = nullptr;
	sf::Text pauseTitleText;

	void InitializeTitle();
	void CenterTextOrigin(sf::Text& textToCenter);


};