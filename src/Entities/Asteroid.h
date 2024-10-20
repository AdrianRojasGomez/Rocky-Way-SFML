#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utilities/Framerate.h"
#include "../Utilities/WrappingScreenUtility.h"


class Asteroid
{
public:
	Asteroid();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
	virtual bool GetIsActive() { return isActive; }
	sf::Sprite GetAsteroidSprite() { return asteroidSprite; }


protected:

	sf::Texture* asteroidTexture;
	sf::Sprite asteroidSprite;
	const std::string spritePath = "res/assets/Enemies/MeteorSmall.png";

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
	float speed = 300.0f;

	virtual void Move();
	virtual void Deactivate();
	virtual void LoadTexture();
	int RandomizeIntValues(int max, int min);
	float RandomizeFloatValues(float max, float min);

private:

	void InitDir();
};