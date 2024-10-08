#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Player.h"
#include "Background.h"

class Gameplay
{

public:
	static Gameplay& getInstance();

	void Update();
	void Draw(sf::RenderWindow& window);


private:
	Gameplay(){}
	Background background;
	Player player;
	

};