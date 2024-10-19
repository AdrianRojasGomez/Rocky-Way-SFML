#include "Gameplay.h"



Gameplay& Gameplay::getInstance()
{
	static Gameplay instance;
	return instance;
}

void Gameplay::Update()
{
	player.Update();
	wave.Update();
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background.Draw(window);
	wave.Draw(window);
	player.Draw(window);
	
}
