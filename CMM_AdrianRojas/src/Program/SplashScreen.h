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
	sf::Texture* powerUpTexture;
	sf::Sprite splashSprite;
	sf::Sprite enterSprite;
	sf::Sprite powerUpSprite;
	sf::Clock splashTime;
	sf::Clock animTime;
	bool firstTime = true;
	int intRectEnter = 0;
	int intRectPower = 0;
	float splashTimer = 7.0f;


	void InitializeBackground();
	void InitializeEnter();
	void InitializePowerUp();
	void SkipSplash();
	void UpdateAnimation();
	void CheckSplashTime();
};
