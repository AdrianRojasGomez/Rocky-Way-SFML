#include "Wave.h"

 Wave::Wave()
 {
	 CreateAsteroids();
 }

 void Wave::CreateAsteroids()
 {
	 for (int i = 0; i < 5; i++)
	 {
		 LargeAsteroid* asteroid = new LargeAsteroid();
		 largeAsteroids.push_back(asteroid);
		 //std::cout << "one Large Asteroid\n";
	 }

	 for (int i = 0; i < 5; i++)
	 {
		 SmallAsteroid* asteroid = new SmallAsteroid();
		 smallAsteroids.push_back(asteroid);
		 //std::cout << "one Small Asteroid\n";

	 }
 }

 void Wave::SpawnWave(sf::FloatRect restrictedSpawnArea)
 {
	 this->restrictedSpawnArea = restrictedSpawnArea;
 }

 void Wave::Update()
 {
	 for (largeIterator = largeAsteroids.begin(); largeIterator != largeAsteroids.end(); largeIterator++)
	 {
		 LargeAsteroid* asteroidToDraw = *largeIterator;
		 if (asteroidToDraw->GetIsActive())
		 {
			 asteroidToDraw->Update();
		 }
	 }

	 for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	 {
		 SmallAsteroid* asteroidToDraw = *smallIterator;
		 if (asteroidToDraw->GetIsActive())
		 {
			 asteroidToDraw->Update();
		 }
	 }
 }


 void Wave::Draw(sf::RenderWindow& window)
 {
	 for (largeIterator = largeAsteroids.begin(); largeIterator != largeAsteroids.end(); largeIterator++)
	 {
		 LargeAsteroid* asteroidToDraw = *largeIterator;
		 if(asteroidToDraw->GetIsActive())
		 {
			 asteroidToDraw->Draw(window);
		 }
	 }

	 for (smallIterator = smallAsteroids.begin(); smallIterator != smallAsteroids.end(); smallIterator++)
	 {
		 SmallAsteroid* asteroidToDraw = *smallIterator;
		 if (asteroidToDraw->GetIsActive())
		 {
			 asteroidToDraw->Draw(window);
		 }
	 }

 }

