#include <SFML/Graphics.hpp>
#include "Program\Game.h"
#include "Entities/Bullet.h"
#include <iostream>
#include <list>


int main()
{
	/*
	std::list<Bullet*> bullets;


	for (int i = 0; i < 10; i++)
	{
		Bullet* bullet = new Bullet();
		bullets.push_back(bullet);
	}

	std::list<Bullet*>::iterator iterator;

	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		std::cout << "Bullet daño: " << (*iterator)->getDamage() << std::endl;
	}

	for (iterator = bullets.begin(); iterator != bullets.end(); iterator++)
	{
		if ((*iterator) != nullptr)
		{
			delete (*iterator);
			(*iterator) = nullptr;
		}
	}
	*/

	Game game;
	game.Run();
	return 0;
}
