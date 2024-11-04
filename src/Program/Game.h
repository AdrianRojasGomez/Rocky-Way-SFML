#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Gameplay.h"
#include "GameState.h"
#include "GameOver.h"
#include "HighScore.h"
#include "Options.h"
#include "SplashScreen.h"


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

	GameState gameState;

	SplashScreen* splash;
	Menu* menu;
	Gameplay* gameplay;
	GameOver* gameOver;
	HighScore* highScore;
	Options* options;

	sf::VideoMode* videoMode;
	sf::RenderWindow* window;
	sf::Image* iconImage;

	void SetIcon();
};