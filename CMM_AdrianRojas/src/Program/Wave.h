#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "../Entities/Player.h"
#include "../Entities/LargeAsteroid.h"
#include "../Entities/SmallAsteroid.h"
#include "../Entities/Collectable.h"

class Wave
{
public:
	Wave(UI* ui);
	~Wave();
	void Update();
	void Draw(sf::RenderWindow& window);
	std::list<LargeAsteroid*>& GetLargeAsteroids() { return largeAsteroids; }
	std::list<SmallAsteroid*>& GetSmallAsteroids() { return smallAsteroids; }
	std::vector<Collectable*>& GetCollectables() { return collectables; }
	void WaveReset();

private:

	UI* ui;
	std::list<LargeAsteroid*> largeAsteroids;
	std::list<LargeAsteroid*>::iterator largeIterator;
	std::list<SmallAsteroid*> smallAsteroids;
	std::list<SmallAsteroid*>::iterator smallIterator;
	std::vector<Collectable*> collectables;
	std::list<Collectable*>::iterator collectableIterator;

	sf::Vector2f coordinates[(int)CollectableType::Unassigned];


	bool shouldSpawnCollectable = false;

	const int GROWTH = 5;
	const float RATIO = 0.1f;
	const int LARGE_ASTEROID_POOL = 20;
	const int SMALL_ASTEROID_POOL = 20;
	const int FIRST_WAVE_LARGE = 1;
	const int FIRST_WAVE_SMALL = 1;
	int waveCounter = 0;
	int currentAsteroidCounter = 0;
	int maxAsteroidperWave = 0;
	int largePerWave = 0;
	int smallPerWave = 0;
	int asteroidsInPool = 0;
	bool shouldCreateWave = false;

	void CreateAsteroids();
	void CreateWave();

	void CreateCollectables();
	void SetCollectables();



	template <typename list, typename Iterator, typename Func>
	void IterateAsteroids(list asteroidType, Iterator it, Func func);
	template <typename list, typename Iterator, typename Func>
	void IterateAsteroids(list asteroidType, Iterator iterator, Func func, sf::RenderWindow& window);
	template <typename list, typename Iterator>
	int CountInactiveAsteroids(list asteroidType, Iterator iterator);
	void UpdateSmallAsteroids();
	void UpdateLargeAsteroids();
	void DrawCollectibles(sf::RenderWindow& window);
	void DrawLargeAsteroids(sf::RenderWindow& window);
	void DrawSmallAsteroids(sf::RenderWindow& window);
	void CheckInactiveAsteroids();

};