#pragma once
#include <SFML/Graphics.hpp>
#include "../Utilities/ScreenResolution.h"


enum class CollectableType
{
	Shotgun = 0,
	Shield = 1,
	DoubleScore = 2,
	Unassigned = 3,
};

class Collectable
{

public:
	Collectable(int collectableType);
	~Collectable();
	void Update();
	void Draw(sf::RenderWindow& window);
	sf::FloatRect GetCollectableHitbox() { return collectableHitZone; }
	CollectableType GetCollectableType() const { return type; }
	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive);
	int GetARandomPosX();
	int GetARandomPosY();
	void SetPosition(sf::Vector2f pos);


private:
	const int fileSize = 128;
	CollectableType type = CollectableType::Unassigned;
	sf::Texture* shotgunTexture = nullptr;
	sf::Texture* shieldTexture = nullptr;
	sf::Texture* dobleScoreTexture = nullptr;
	sf::Sprite collectableSprite;
	bool isAlive = false;
	sf::Clock animationClock;
	sf::FloatRect collectableHitZone;
	int intRectX = 0;
	sf::Vector2f initPos;

	void AssignCollectableTypeVisual(int collectableType);
	void AssignSprite(sf::Texture* assignedTexture,
		float sizeX, float sizeY, float scale);
	void UpdateAnimation();
	void UpdateBounce();

};
