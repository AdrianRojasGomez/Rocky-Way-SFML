#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Wave.h"
#include "CollisionManager.h"
#include "UI.h"
#include "GameState.h"

class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	GameState Update();
	void Draw(sf::RenderWindow& window);
	GameState ResetGameplay();



private:
	GameState gameState;
	Background* background;
	UI* ui;
	Player* player;
	Wave* wave;
	CollisionManager* collisionManager;


};