#pragma once
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



class Asteroid
{
	enum Size { Unselected, Large, Medium, Small, Error };

public:
	Asteroid();
	Size getSize() { return asteroidSize; }
	Size setSize(Size size) { this->asteroidSize = size; }

	void static setLargeAsteroidValues(float minSize, float maxSize, float minSpeed, float maxSpeed)
	{
		largeValues.minSize = minSize;
		largeValues.maxSize = maxSize;
		largeValues.minSpeed = minSpeed;
		largeValues.maxSpeed = maxSpeed;
	}

	void static setMediumAsteroidValues(float minSize, float maxSize, float minSpeed, float maxSpeed)
	{
		mediumValues.minSize = minSize;
		mediumValues.maxSize = maxSize;
		mediumValues.minSpeed = minSpeed;
		mediumValues.maxSpeed = maxSpeed;
	}
	void static setSmallAsteroidValues(float minSize, float maxSize, float minSpeed, float maxSpeed)
	{
		smallValues.minSize = minSize;
		smallValues.maxSize = maxSize;
		smallValues.minSpeed = minSpeed;
		smallValues.maxSpeed = maxSpeed;
	}


private:

	sf::Texture asteroidTexture;
	sf::Sprite asteroidSprite;
	Size asteroidSize = Size::Unselected;

	float scaleX = 0;
	float scaleY = 0;
	float health = 0;
	float initPosX = 0.0f;
	float initPosY = 0.0f;
	float dirX = 0.0f;
	float dirY = 0.0f;

	struct AsteroidRadomizer
	{
		float minSize = 0.0f;
		float maxSize = 0.0f;
		float minSpeed = 0.0f;
		float maxSpeed = 0.0f;
	};

	static AsteroidRadomizer largeValues;
	static AsteroidRadomizer mediumValues;
	static AsteroidRadomizer smallValues;



	void SelectAsteroidType(Size asteroidSize);
	void LoadAsteroidTexture();
	void GenerateAsteroidParameters();
	void InitializeAsteroidValues();

};