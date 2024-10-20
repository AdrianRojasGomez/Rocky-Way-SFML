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
	static bool PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& asteroid);
	static bool PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& asteroid);
	static bool BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& asteroid);
	static bool BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& asteroid);


};