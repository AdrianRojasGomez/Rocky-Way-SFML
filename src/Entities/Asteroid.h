#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Utilities/WrappingScreenUtility.h"


class Asteroid
{
public:
	Asteroid();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
	virtual bool GetIsActive() { return isActive; }
	virtual void SetIsActive(bool isActive) { this->isActive = isActive; }
	sf::Sprite GetAsteroidSprite() { return asteroidSprite; }


protected:
	const float NUM_PI = 3.14159265f;
	sf::Texture* asteroidTexture;
	sf::Sprite asteroidSprite;

	bool isActive = false;
	float sizeMultiplierSpeed = 1.0f;
	float sizeMultiplierRotation = 1.0f;
	float scaleX = 1.0f;
	float scaleY = 1.0f;
	float posX;
	float posY;
	float dirX;
	float dirY;
	float rotationSpeed = 10.0f;
	float rotation;
	float speed = 100.0f;

	virtual void Move();
	virtual void LoadTexture();
	int RandomizeIntValues(int max, int min);
	float RandomizeFloatValues(float max, float min);

private:
	void InitDir();
};