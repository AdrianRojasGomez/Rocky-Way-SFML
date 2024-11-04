#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{

public:
	Bullet();
	~Bullet();
	void Update();
	void Draw(sf::RenderWindow& window);
	void Fire(float posX, float posY, float dirX, float dirY);
	int GetDamage() { return damage; }
	bool GetIsActive() { return isActive; }
	sf::Sprite GetBulletSprite() { return bulletSprite; }
	void SetBulletSprite(bool isActive);

private:
	sf::Texture* bulletTexture;
	sf::Sprite bulletSprite;
	sf::Clock* timer;
	
	const float BULLET_LIFETIME = 0.65f;
	float initialBulletSpeed = 750.0f;
	float bulletSpeed = 650.0f;
	bool isActive = false;
	int damage = 10;
	float scaleX = .04f;
	float scaleY = .25f;
	float posX = 0.0f;
	float posY = 0.0f;
	float bulletDirX = 0.0f;
	float bulletDirY = 0.0f;

	void SetTextureValues();
	void BulletMovement();
	void BulletTimer();
	void SetRotation();
	void SetPosition();
};