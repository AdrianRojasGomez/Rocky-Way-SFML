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
	sf::Texture* enterTexture;
	sf::Sprite splashSprite;
	sf::Sprite enterSprite;
	sf::Clock splashTime;
	sf::Clock animTime;
	bool firstTime = true;
	int intRectX = 0;
	float splashTimer = 7.0f;


	void InitializeBackground();
	void InitializeEnter();
	void SkipSplash();
	void UpdateAnimation();
	void CheckSplashTime();
};
