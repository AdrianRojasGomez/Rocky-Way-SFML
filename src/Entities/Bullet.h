#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{

public:

	Bullet();
	void Update();
	void Draw(sf::RenderWindow& window);
	void Fire(sf::Vector2f shooterPosition, float rotation, float dirX, float dirY);
	int getDamage() { return damage; }
	bool getIsActive() { return isActive; }
	sf::Sprite getSprite() { return bulletSprite; }

private:
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::Clock timer;
	sf::Vector2f shooterPosition;

	const float BULLET_SPEED = .000005f;
	const float BULLET_LIFETIME = 1.2f;

	bool isActive = false;
	int damage = 10;
	float scaleX = .05f;
	float scaleY = .2f;
	float posX = 0.0f;
	float posY = 0.0f;
	float shooterRotation = 0.0f;
	float shooterDirX = 0.0f;
	float shooterDirY = 0.0f;


	void LoadBulletTexture();
	void BulletMovement();
	void BulletTimer();
	void SetRotation();
	void SetPosition();
};