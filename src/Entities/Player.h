#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	const float SCALE_X = 0.5f;
	const float SCALE_Y = 0.5f;
	const float ROTATION_SPEED = .05f;
	const float MOVE_SPEED = .05f;
	const int WIDTH = 1280;
	const int HEIGHT = 720;

	float posX = 0;
	float posY = 0;

	void LoadPlayerTexture();
	void SetInitialPosition();
	void Movement();
	
};