#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ResourceManager.h"

enum class GameState
{
	SplashScreen = 0,
	MainMenu = 1,
	Gameplay = 2,
	GameOver = 3,
	Stats = 4,
	Options = 5,
	ExitGame = 6,
	Error = 7
};

class Game

{
public:
	Game();
	~Game();
	void Run();
	void SetGameState(GameState newState) { gameState = newState; }
	GameState gameState;

private:
	void ProcessEvents();
	void Update();
	void Draw();

	Menu* menu;
	ResourceManager* resourceManager;
	sf::VideoMode* videoMode;
	sf::RenderWindow* window;
};