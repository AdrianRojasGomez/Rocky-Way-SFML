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
	CollectableType type = CollectableType::Unassigned;
	sf::Texture* shotgunTexture = nullptr;
	sf::Texture* shieldTexture = nullptr;
	sf::Texture* doubleScoreTexture;
	sf::Sprite assignedCollectableType;
	bool isAlive = false;

	//For Building, remove when textures are made
	sf::CircleShape collectableShape;
	sf::FloatRect collectableHitZone;

	void AssignCollectableTypeVisual(int collectableType);

};
