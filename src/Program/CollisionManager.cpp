#include "CollisionManager.h"

bool CollisionManager::PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& asteroid)
{
	return false;
}

bool CollisionManager::PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& asteroid)
{
	return false;
}

bool CollisionManager::BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& asteroid)
{
	return false;
}

bool CollisionManager::BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& asteroid)
{
	return false;
}
