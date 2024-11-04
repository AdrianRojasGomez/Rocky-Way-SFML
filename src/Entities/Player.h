#pragma once
#include <iostream>
#include <list>
#include "Bullet.h"
#include "../Program/UI.h"
#include "../Program/GameState.h"


class Player
{
public:
	Player(UI* ui, GameState* gameState);
	~Player();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	void Respawn();
	void RemoveInvulnerability();
	sf::Sprite GetPlayerSprite() { return playerSprite; }
	std::list<Bullet*>& GetBullets() { return bullets; }
	bool GetIsInvulnerable() { return isInvulnerable; }
	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive);
	int GetHP() { return HP; }
	bool CheckHasHPLeft();
	void PlayerReset();

private:
	GameState* gameState;
	UI* ui;
	sf::Texture* playerTexture;
	sf::Sprite playerSprite;
	sf::Clock cooldownClock;
	sf::Clock respawnClock;
	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator iterator;

	sf::IntRect textureRect;
	sf::Clock animationClock;
	int intRectPosX = 0;

	const float COOLDOWN_RATE = 0.15f;
	const float SCALE_X = 0.6f;
	const float SCALE_Y = 0.6f;
	const float ROTATION_SPEED = 200.0f;
	const float MOVE_SPEED = 250.0f;
	const float NUM_PI = 3.14159265f;
	const int BULLET_CAPACITY = 30;
	const int FIXED_DEGREES = 90;
	const int RESPAWN_TIME = 2;
	const int INVULNERABLE_TIME = 3;

	bool isAlive = true;
	bool isInvulnerable = false;
	bool isFiring = false;
	int MaxHP = 1;
	int HP;
	float posX = 0.0f;
	float posY = 0.0f;
	float rotation = 0.0f;
	float directionX = 0.0f;
	float directionY = 0.0f;
	float speedX = 0.0f;
	float speedY = 0.0f;

	void SetTextureValues();
	void SetInitialPosition();
	void Movement();
	void CreateBullets();
	void Fire();
	void UpdateFrameanimation();


};