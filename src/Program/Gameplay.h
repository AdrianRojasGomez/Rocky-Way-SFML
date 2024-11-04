#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Wave.h"
#include "CollisionManager.h"
#include "UI.h"
#include "GameState.h"
#include "Pause.h"

class Gameplay
{
public:
	Gameplay(GameState* gameState);
	~Gameplay();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	void ResetGameplay(bool isMenu);

private:


	GameState* gameState;
	Background* background;
	UI* ui;
	Player* player;
	Wave* wave;
	CollisionManager* collisionManager;
	Pause* pause;

};