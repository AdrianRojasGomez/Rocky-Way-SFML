#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Gameplay.h"
#include "GameState.h"
#include "GameOver.h"
#include "HighScore.h"
#include "Options.h"
#include "SplashScreen.h"
#include "../Utilities/ScreenShakeUtility.h"



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

	bool isMenu = false;
	GameState gameState;

	SplashScreen* splash;
	Menu* menu;
	Gameplay* gameplay;
	GameOver* gameOver;
	HighScore* highScore;
	Options* options;
	ScreenShake* screenShake;
	

	sf::VideoMode* videoMode;
	sf::View* view;
	sf::RenderWindow* window;
	sf::Image* iconImage;

	void SetIcon();
};