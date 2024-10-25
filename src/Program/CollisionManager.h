#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "../Entities/Player.h"
#include "../Entities/LargeAsteroid.h"
#include "../Entities/SmallAsteroid.h"
#include "../Entities/Bullet.h"


class CollisionManager
{
public:
	CollisionManager();
	void Update(Player& player, std::list<Bullet*> bullets, std::list<LargeAsteroid*> largeAsteroids, std::list<SmallAsteroid*> smallAsteroids);
	bool PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& asteroid);
	bool PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& asteroid);
	bool BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& asteroid);
	bool BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& asteroid);

private:
	const int SMALL_FROM_LARGE = 3;
	void SpawnSmallAsteroids(std::list<SmallAsteroid*> smallAsteroids, sf::Vector2f largePosition);
};