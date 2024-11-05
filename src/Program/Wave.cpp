#include <cmath>
#include "Wave.h"
#include "../Utilities/ScoreManager.h"

Wave::Wave(UI* ui)
{
	this->ui = ui;
	//CreateAsteroids();
	//CreateWave();
}

Wave::~Wave()
{

}

void Wave::WaveReset()
{
	waveCounter = 0;

	for (largeIterator = largeAsteroids.begin(); largeIterator != largeAsteroids.end(); largeIterator++)
	{
		LargeAsteroid* asteroidToReset = *largeIterator;
		asteroidToReset->SetIsActive(false);
	}
	for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	{
		SmallAsteroid* asteroidToReset = *smallIterator;
		asteroidToReset->SetIsActive(false);
	}
}


void Wave::CreateAsteroids()
{
	for (int i = 0; i < LARGE_ASTEROID_POOL; i++)
	{
		LargeAsteroid* asteroid = new LargeAsteroid();
		largeAsteroids.push_back(asteroid);
	}

	for (int i = 0; i < SMALL_ASTEROID_POOL; i++)
	{
		SmallAsteroid* asteroid = new SmallAsteroid();
		smallAsteroids.push_back(asteroid);
	}
}

void Wave::CreateWave()
{
	waveCounter++;
	ScoreManager::getInstance().SetWave(waveCounter);
	ui->SetUIWave(waveCounter);

	if (waveCounter <= 1)
	{
		this->largePerWave = FIRST_WAVE_LARGE;
		this->smallPerWave = FIRST_WAVE_SMALL;
	}
	else
	{
		for (int i = 0; i < waveCounter; i++)
		{
			largePerWave += (int)(floor(GROWTH * i * i * RATIO));
			smallPerWave += (int)(floor((int)(GROWTH * 0.2f)) * i * i * RATIO);
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
	}

	index = 0;
	for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	{

		if (index >= smallPerWave)
			break;

		index++;
		SmallAsteroid* asteroidToActivate = *smallIterator;
		asteroidToActivate->SetIsActive(true);
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

template <typename list, typename Iterator>
int Wave::CountInactiveAsteroids(list asteroidType, Iterator iterator)
{
	int aux = 0;
	for (iterator = asteroidType.begin(); iterator != asteroidType.end(); iterator++)
	{
		auto* asteroidToProcess = *iterator;
		if (asteroidToProcess->GetIsActive())
		{
			aux++;
		}
	}
	return aux;
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

void Wave::CheckInactiveAsteroids()
{
	asteroidsInPool = 0;
	this->asteroidsInPool += CountInactiveAsteroids(largeAsteroids, largeIterator);
	this->asteroidsInPool += CountInactiveAsteroids(smallAsteroids, smallIterator);
	if (asteroidsInPool <= 0)
		shouldCreateWave = true;
}


void Wave::Update()
{

	if (shouldCreateWave)
	{
		asteroidsInPool = 0;
		shouldCreateWave = false;
		CreateWave();
	}
	UpdateLargeAsteroids();
	UpdateSmallAsteroids();
	CheckInactiveAsteroids();

}

void Wave::Draw(sf::RenderWindow& window)
{
	DrawLargeAsteroids(window);
	DrawSmallAsteroids(window);
}

