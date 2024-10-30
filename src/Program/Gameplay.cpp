#include "Gameplay.h"

Gameplay::Gameplay()
{

}

Gameplay::~Gameplay()
{

}

Gameplay& Gameplay::getInstance()
{
	static Gameplay instance;
	return instance;
}

void Gameplay::Update()
{
	player.Update();
	collisionManager.Update(player, player.GetBullets(),  wave.GetLargeAsteroids(), wave.GetSmallAsteroids());
	wave.Update();
	if (player.GetHP() <= 0)
	{
		std::cout << "Game Over" << std::endl;
		//gameOver.show()
	}
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background.Draw(window);
	wave.Draw(window);
	player.Draw(window);
	
}

