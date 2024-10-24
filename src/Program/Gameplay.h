#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Wave.h"
#include "CollisionManager.h"

class Gameplay
{
public:
	static Gameplay& getInstance();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	Gameplay(){}
	Background background;
	Wave wave;
	CollisionManager collisionManager;
	Player player;
};