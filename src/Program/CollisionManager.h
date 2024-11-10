#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "../Entities/Player.h"
#include "../Entities/LargeAsteroid.h"
#include "../Entities/SmallAsteroid.h"
#include "../Entities/Bullet.h"
#include "../Entities/Collectable.h"


class CollisionManager
{
public:
	CollisionManager();
	void Update(Player& player,
		std::list<Bullet*> bullets,
		std::list<LargeAsteroid*> largeAsteroids,
		std::list<SmallAsteroid*> smallAsteroids,
		std::vector<Collectable*> collectables);
	bool PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& asteroid);
	bool PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& asteroid);
	bool PlayerVsCollectable(Player&, Collectable& collectable);
	bool BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& asteroid);
	bool BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& asteroid);

private:
	const int MAX_DEBRIS = 3;
	const int MIN_DEBRIS = 2;
	bool canShutDownCollectables = false;
	void SpawnSmallAsteroids(std::list<SmallAsteroid*> smallAsteroids, sf::Vector2f largePosition);
};