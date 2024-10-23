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
	Stats = 3,
	ExitGame = 4,
	Error = 5
};

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

	GameState* gameState;
	Menu* menu;
	ResourceManager* resourceManager;
	sf::VideoMode* videoMode;
	sf::RenderWindow* window;




};