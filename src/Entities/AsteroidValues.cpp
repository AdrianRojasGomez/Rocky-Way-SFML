#include "AsteroidValues.h"

AsteroidValues::AsteroidValues()
{
	srand(time(NULL));
	ReadCSV();
}

void AsteroidValues::ReadCSV()
{
	//TODO: READ THE CSV
	//TODO: ASSIGN VARIABLES LARGE
		//TODO: AssignParamenters
	Asteroid::setLargeAsteroidValues(minSize, maxSize, minSpeed, maxSpeed);
	//TODO: ASSIGN VARIABLES MEDIUM
		//TODO: AssignParamenters
	Asteroid::setMediumAsteroidValues(minSize, maxSize, minSpeed, maxSpeed);
	//TODO: ASSIGN VARIABLES SMALL
		//TODO: AssignParamenters
	Asteroid::setSmallAsteroidValues(minSize, maxSize, minSpeed, maxSpeed);

}


