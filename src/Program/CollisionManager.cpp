#include <iostream>
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::Update(Player& player, std::list<Bullet*> bullets, std::list<LargeAsteroid*> largeAsteroids, std::list<SmallAsteroid*> smallAsteroids)
{
	for (std::list<LargeAsteroid*>::iterator it = largeAsteroids.begin(); it != largeAsteroids.end(); it++)
	{
		LargeAsteroid* currentAsteroid = *it;
		if (currentAsteroid != nullptr && !currentAsteroid->GetIsActive())
		{
			continue;
		}

		if (PlayerVsLargeAsteroidCollision(player, *currentAsteroid))
		{
			//TODO: Behavior Player vs Large Asteroid
		}
	}

	for (std::list<SmallAsteroid*>::iterator it = smallAsteroids.begin(); it != smallAsteroids.end(); it++)
	{
		SmallAsteroid* currentAsteroid = *it;
		if (currentAsteroid != nullptr && !currentAsteroid->GetIsActive())
		{
			continue;
		}

		if (PlayerVsSmallAsteroidCollision(player, *currentAsteroid))
		{
			//TODO: Behavior Player vs Small Asteroid
		}
	}

	for (std::list<Bullet*>::iterator bulletIterator = bullets.begin(); bulletIterator != bullets.end(); bulletIterator++)
	{
		Bullet* currentBullet = *bulletIterator;
		if (currentBullet != nullptr && !currentBullet->GetIsActive())
		{
			continue;
		}

		for (std::list<LargeAsteroid*>::iterator largeAsteroidIterator = largeAsteroids.begin(); largeAsteroidIterator != largeAsteroids.end(); largeAsteroidIterator++)
		{
			LargeAsteroid* currentLargeAsteroid = *largeAsteroidIterator;
			if (BulletVsLargeAsteroidCollision(*currentBullet, *currentLargeAsteroid))
			{
				//TODO: Behavior Bullet vs Large Asteroid

			}
		}

		for (std::list<SmallAsteroid*>::iterator smallAsteroidIterator = smallAsteroids.begin(); smallAsteroidIterator != smallAsteroids.end(); smallAsteroidIterator++)
		{
			SmallAsteroid* currentSmallAsteroid = *smallAsteroidIterator;
			if (BulletVsSmallAsteroidCollision(*currentBullet, *currentSmallAsteroid))
			{
				//TODO: Behavior Player vs Small Asteroid

			}
		}
	}
}

bool CollisionManager::PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& largeAsteroid)
{
	return player.GetPlayerSprite().getGlobalBounds().intersects(largeAsteroid.GetAsteroidSprite().getGlobalBounds());
}

bool CollisionManager::PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& smallAsteroid)
{
	return player.GetPlayerSprite().getGlobalBounds().intersects(smallAsteroid.GetAsteroidSprite().getGlobalBounds());
}

bool CollisionManager::BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& largeAsteroid)
{
	return bullet.GetBulletSprite().getGlobalBounds().intersects(largeAsteroid.GetAsteroidSprite().getGlobalBounds());
}

bool CollisionManager::BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& smallAsteroid)
{
	return bullet.GetBulletSprite().getGlobalBounds().intersects(smallAsteroid.GetAsteroidSprite().getGlobalBounds());
}
