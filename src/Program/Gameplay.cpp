#include "Gameplay.h"



Gameplay& Gameplay::getInstance()
{
	static Gameplay instance;
	return instance;
}

void Gameplay::Update()
{
	player.Update();
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background.Draw(window);
	player.Draw(window);
}
