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
	CollectableType GetCollectableType() const { return type; }
	void SetIsAlive(bool isAlive);
	int GetARandomPosX();
	int GetARandomPosY();
	void SetPosition(sf::Vector2f pos);

private:
	static constexpr int SPAWN_PLACES = 5;
	int possiblePosX[SPAWN_PLACES] =
	{
		(int)(ScreenResolution::SCREEN_WIDTH_720P / 2.0f),
		(int)(ScreenResolution::SCREEN_WIDTH_720P * 0.25f),
		(int)(ScreenResolution::SCREEN_WIDTH_720P * 0.65f),
		(int)(ScreenResolution::SCREEN_WIDTH_720P * 0.15f),
		(int)(ScreenResolution::SCREEN_WIDTH_720P * 0.85f),
	};

	int possiblePosY[SPAWN_PLACES] =
	{
		(int)(ScreenResolution::SCREEN_HEIGHT_720P / 2.0f),
		(int)(ScreenResolution::SCREEN_HEIGHT_720P * 0.25f),
		(int)(ScreenResolution::SCREEN_HEIGHT_720P * 0.65f),
		(int)(ScreenResolution::SCREEN_HEIGHT_720P * 0.15f),
		(int)(ScreenResolution::SCREEN_HEIGHT_720P * 0.85f),
	};

	CollectableType type = CollectableType::Unassigned;
	sf::Texture* shotgunTexture = nullptr;
	sf::Texture* shieldTexture = nullptr;
	sf::Texture* doubleScoreTexture;
	sf::Sprite assignedCollectableType;
	bool isAlive = false;

	//For Building, remove when textures are made
	sf::CircleShape collectableShape;

	void AssignCollectableTypeVisual(int collectableType);
};
