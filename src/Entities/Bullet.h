#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{

public:

	Bullet();
	void Update();
	void Draw(sf::RenderWindow& window);
	void Fire(float posX, float posY, float dirX, float dirY);
	int getDamage() { return damage; }
	bool getIsActive() { return isActive; }
	sf::Sprite getBulletSprite() { return bulletSprite; }

private:
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::Clock timer;
	

	const float BULLET_SPEED = 650.0f;
	const float BULLET_LIFETIME = 0.7f;

	bool isActive = false;
	int damage = 10;
	float scaleX = .04f;
	float scaleY = .25f;
	float posX = 0.0f;
	float posY = 0.0f;
	float shooterDirX = 0.0f;
	float shooterDirY = 0.0f;


	void LoadBulletTexture();
	void BulletMovement();
	void BulletTimer();
	void SetRotation();
	void SetPosition();
};