#pragma once
#include <SFML/Graphics.hpp>
#include "../Entities/Player.h"

class Gameplay
{

public:
	static Gameplay& getInstance();

	void Update();
	void Draw(sf::RenderWindow& window);


private:
	Gameplay(){}

	Player player;


	///How can I prevent the instantiation of this class?
};