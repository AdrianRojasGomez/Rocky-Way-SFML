#include "Wave.h"

 Wave::Wave()
 {
	 CreateAsteroids();
 }

 Wave::~Wave()
 {

 }

 void Wave::CreateAsteroids()
 {
	 for (int i = 0; i < 10; i++)
	 {
		 LargeAsteroid* asteroid = new LargeAsteroid();
		 largeAsteroids.push_back(asteroid);
	 }

	 for (int i = 0; i < 5; i++)
	 {
		 SmallAsteroid* asteroid = new SmallAsteroid();
		 asteroid->SetIsActive(true);
		 smallAsteroids.push_back(asteroid);
	 }
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

