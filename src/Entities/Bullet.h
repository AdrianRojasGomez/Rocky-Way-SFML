#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{

public:

	Bullet();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::Clock timer;

	const float BULLET_SPEED = .05f;
	const float BULLET_LIFETIME = 1.2f;

	bool isActive = false;
	int damage = 10;
	float scaleX = 0.5f;
	float scaleY = 0.5f;
	float posX = 0.0f;
	float posY = 0.0f;
	float shooterDirX = 0.0f;
	float shooterDirY = 0.0f;
	float angleRotation = 0.0f;

	void LoadBulletTexture();
	void Fire(float initPosX, float initPosY, float initRotationX, float initRotationY);
	void BulletMovement();
	void BulletTimer();
	void CalculateRotation();
	int getDamage() { return damage; }
};