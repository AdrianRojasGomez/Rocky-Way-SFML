#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/Framerate.h"

class Player
{
public:
	Player();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Clock cooldownClock;
	

	const float COOLDOWN_RATE = 0.25f;
	const float SCALE_X = 0.5f;
	const float SCALE_Y = 0.5f;
	const float ROTATION_SPEED = 200.0f;
	const float MOVE_SPEED = 400.0f;
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int BULLET_CAPACITY = 5;

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator iterator;
	bool isFiring = false;
	float posX = 0;
	float posY = 0;
	float rotation = 0;
	float directionX = 0.0f;
	float directionY = 0.0f;



	void LoadPlayerTexture();
	void SetInitialPosition();
	void Movement();
	void CreateBullets();
	void Fire();
	
};