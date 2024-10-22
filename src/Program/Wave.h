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
	~Wave();
	void Update();
	void ActivateSmallAsteroids();
	void ActivateLargeAsteroids();
	void Draw(sf::RenderWindow& window);
	std::list<LargeAsteroid*>& GetLargeAsteroids() { return largeAsteroids; }
	std::list<SmallAsteroid*>& GetSmallAsteroids() { return smallAsteroids; }

private:

	std::list<LargeAsteroid*> largeAsteroids;
	std::list<LargeAsteroid*>::iterator largeIterator;
	std::list<SmallAsteroid*> smallAsteroids;
	std::list<SmallAsteroid*>::iterator smallIterator;

	const int growth = 10;
	const float ratio = 0.1f;
	const int largeAsteroidPool = 20;
	const int smallAsteroidPool = 20;
	int waveCounter = 0;
	int currentAsteroidCounter = 0;
	int maxAsteroidperWave = 0;
	bool isFirstWave = true;
	int largePerWave = 0;
	int smallPerWave = 0;
	int asteroidsInPool = 0;
	bool shouldCreateWave = false;

	void CreateAsteroids();
	void CreateWave();

};