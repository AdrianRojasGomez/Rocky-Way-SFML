#pragma once
#include <iostream>
#include <list>
#include "Bullet.h"
#include "../Program/GameState.h"
#include "../Program/UI.h"
#include "../Utilities/ScreenShakeUtility.h"



class Player
{
public:
	Player(UI* ui, GameState* gameState, ScreenShake* screenshake);
	~Player();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	void Respawn();
	void RemoveInvulnerability();
	sf::FloatRect GetPlayerHitbox() { return *playerHitZone; }
	std::list<Bullet*>& GetBullets() { return bullets; }
	bool GetIsInvulnerable() { return isInvulnerable; }
	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive);
	int GetHP() { return HP; }
	bool CheckHasHPLeft();
	void TriggerScreenshake();
	void ResetFromPause();
	void EnableShield();
	void CallDoubleScore();

private:

	ScreenShake* screenShake;
	GameState* gameState;
	UI* ui;
	sf::Texture* playerTexture;
	sf::Sprite playerSprite;
	sf::FloatRect* playerHitZone;

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator iterator;

	sf::IntRect textureRect;

	sf::Clock animationClock;
	sf::Clock deathClock;
	sf::Clock cooldownClock;
	sf::Clock respawnClock;
	sf::Clock shieldClock;
	sf::Clock dobleClock;

	const float COOLDOWN_RATE = 0.15f;
	const float SCALE = 0.5f;
	const float ROTATION_SPEED = 250.0f;
	const float MOVE_SPEED = 250.0f;
	const float NUM_PI = 3.14159265f;
	const float hitzoneSizeMultiplier = 0.5f;

	const int BULLET_CAPACITY = 30;
	const int FIXED_DEGREES = 90;
	const int RESPAWN_TIME = 2;
	const int INVULNERABLE_TIME = 3.5;

	bool isAlive = true;
	bool isInvulnerable = false;
	bool isFiring = false;
	bool isReadyToRevive = false;
	bool hasShield = false;
	bool hasDobleMultiplier = false;

	int MaxHP = 3;
	int HP;
	int intRectPosX = 0;

	float bonusTime = 10.0f;

	float playerOffsetWrap = 15.0f;
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
	void UpdateFrameAnimation();
	void HasShieldExpired();
	void HasDobleExpired();



	//debug shapes
	sf::CircleShape shieldShape;
};