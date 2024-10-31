#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ResourceManager.h"
#include "Gameplay.h"
#include "GameState.h"
#include "GameOver.h"

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
	ResourceManager* resourceManager;
	sf::VideoMode* videoMode;
	sf::RenderWindow* window;
	GameState gameState;
};