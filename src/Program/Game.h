#pragma once
#include <SFML/Graphics.hpp>
#include "../Utilities/ResourceManager.h"
#include "Menu.h"
#include "Gameplay.h"
#include "GameState.h"
#include "GameOver.h"
#include "HighScore.h"


class Game

{
public:
	Game();
	~Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Draw();

	Menu* menu;
	Gameplay* gameplay;
	GameOver* gameOver;
	HighScore* highScore;
	ResourceManager* resourceManager;
	sf::VideoMode* videoMode;
	sf::RenderWindow* window;
	GameState gameState;
};