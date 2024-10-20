#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "../Entities/Player.h"
#include "../Entities/LargeAsteroid.h"
#include "../Entities/SmallAsteroid.h"



class Wave
{
public:
	Wave();
	void Update();
	void Draw(sf::RenderWindow& window);
	std::list<LargeAsteroid*>& GetLargeAsteroids() { return largeAsteroids; }
	std::list<SmallAsteroid*>& GetSmallAsteroids() { return smallAsteroids; }

private:

	void CreateAsteroids();
	void SpawnWave(sf::FloatRect restrictedSpawnArea);

	sf::FloatRect restrictedSpawnArea;
	std::list<LargeAsteroid*> largeAsteroids;
	std::list<LargeAsteroid*>::iterator largeIterator;
	std::list<SmallAsteroid*> smallAsteroids;
	std::list<SmallAsteroid*>::iterator smallIterator;


};