#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class SplashScreen
{
public:
	SplashScreen(GameState* gameState);
	~SplashScreen();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);



private:
	GameState* gameState;

	sf::Texture* splashTexture;
	sf::Sprite splashSprite;
	sf::Clock splashTime;
	bool firstTime = true;


	void InitializeBackground();
	void SkipSplash();
	void CheckSplashTime();
};
