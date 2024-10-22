#include <cmath>
//#include <functional>
#include "Wave.h"

Wave::Wave()
{
	CreateAsteroids();
	CreateWave();
}

Wave::~Wave()
{

}

void Wave::CreateAsteroids()
{
	for (int i = 0; i < largeAsteroidPool; i++)
	{
		LargeAsteroid* asteroid = new LargeAsteroid();
		largeAsteroids.push_back(asteroid);
	}

	for (int i = 0; i < smallAsteroidPool; i++)
	{
		SmallAsteroid* asteroid = new SmallAsteroid();
		smallAsteroids.push_back(asteroid);
	}
}

void Wave::CreateWave()
{
	waveCounter++;
	std::cout << "WaveCounter = " << waveCounter << std::endl;

	if (isFirstWave)
	{
		this->isFirstWave = false;
		this->largePerWave = 4;
		this->smallPerWave = 2;
		std::cout << "First Wave!\n";

	}
	else
	{
		for (int i = 0; i < waveCounter; i++)
		{
			this->largePerWave += (int)(floor(growth * i * i * ratio));
			this->smallPerWave += (int)(floor(growth * i * i * ratio));
		}
	}

	int index = 0;
	for (largeIterator = largeAsteroids.begin(); largeIterator != largeAsteroids.end(); largeIterator++)
	{
		if (index >= largePerWave)
			break;

		index++;
		LargeAsteroid* asteroidToActivate = *largeIterator;
		asteroidToActivate->SetIsActive(true);
		std::cout << "index Large " << index << std::endl;
	}

	index = 0;
	for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	{

		if (index >= smallPerWave)
			break;

		index++;
		SmallAsteroid* asteroidToActivate = *smallIterator;
		asteroidToActivate->SetIsActive(true);
		std::cout << "index Small " << index << std::endl;
	}
}

template <typename list ,typename Iterator, typename Func>
void Wave::IterateAsteroids(list asteroidType ,Iterator iterator, Func func)
{
	
	for (iterator = asteroidType.begin(); iterator != asteroidType.end(); iterator++)
	{
		auto* asteroidToProcess = *iterator;
		if (asteroidToProcess->GetIsActive())
		{
			(asteroidToProcess->*func)();
		}
	}
}

template <typename list, typename Iterator, typename Func>
void Wave::IterateAsteroids(list asteroidType, Iterator iterator, Func func, sf::RenderWindow& window)
{

	for (iterator = asteroidType.begin(); iterator != asteroidType.end(); iterator++)
	{
		auto* asteroidToProcess = *iterator;
		if (asteroidToProcess->GetIsActive())
		{
			(asteroidToProcess->*func)(window);
		}
	}
}



void Wave::UpdateLargeAsteroids()
{
	IterateAsteroids(largeAsteroids, largeIterator, &LargeAsteroid::Update);
}

void Wave::UpdateSmallAsteroids()
{
	IterateAsteroids(smallAsteroids, smallIterator, &SmallAsteroid::Update);
}

void Wave::DrawLargeAsteroids(sf::RenderWindow& window)
{
	IterateAsteroids(largeAsteroids, largeIterator, &LargeAsteroid::Draw, window);
}

void Wave::DrawSmallAsteroids(sf::RenderWindow& window)
{
	IterateAsteroids(smallAsteroids, smallIterator, &SmallAsteroid::Draw, window);
}


void Wave::Update()
{
	if (shouldCreateWave)
	{
		shouldCreateWave = false;
		asteroidsInPool = 0;
		CreateWave();
	}
	UpdateLargeAsteroids();
	UpdateSmallAsteroids();
	//TODO: Check for Dead Asteroids
}

void Wave::Draw(sf::RenderWindow& window)
{
	DrawLargeAsteroids(window);
	DrawSmallAsteroids(window);


	//for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	//{
	//	SmallAsteroid* asteroidToDraw = *smallIterator;
	//	if (asteroidToDraw->GetIsActive())
	//	{
	//		asteroidToDraw->Draw(window);
	//	}
	//}
}

