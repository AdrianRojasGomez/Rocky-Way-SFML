#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum class InitialPosition
{
	UNASSIGNED = 0,
	NORTH = 1,
	WEST = 2, 
	SOUTH = 3,
	EAST = 4, 
};


class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
	virtual bool GetIsActive() { return isActive; }
	virtual void SetIsActive(bool isActive);
	sf::FloatRect GetAsteroidHitBox() { return *asteroidHitZone; }


protected:
	const float NUM_PI = 3.14159265f;
	const float speed = 100.0f;
	sf::Texture* asteroidTexture;
	sf::Sprite asteroidSprite;
	sf::FloatRect* asteroidHitZone;

	bool isActive = false;
	float initialMultiplierSpeed = 1.0f;
	float currentSpeed = 1.0f;
	float multiplierRotation = 1.0f;
	float scaleX = 1.0f;
	float scaleY = 1.0f;
	float posX;
	float posY;
	float dirX;
	float dirY;
	float rotationSpeed = 10.0f;
	float rotation;
	float hitzoneHeight = 1.0f;
	float hitzoneWidth = 1.0f;

	virtual void Move();
	virtual void SetTextureValues();

private:
	void InitDirection();
	void InitPosition();
};