#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "GameOver.h"
#include "Wave.h"
#include "CollisionManager.h"
#include "UI.h"

class Gameplay
{
public:
	static Gameplay& getInstance();
	void Update();
	void Draw(sf::RenderWindow& window);

	Gameplay(const Gameplay&) = delete;
	Gameplay& operator=(const Gameplay&) = delete;

private:
	Gameplay();
	~Gameplay();
	Background* background;
	UI* ui;
	Player* player;
	Wave* wave;
	CollisionManager* collisionManager;
	GameOver* gameOver;
};