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
			if (player.GetIsInvulnerable())
				break;
			player.SetIsAlive(false);
			currentAsteroid->SetIsActive(false);
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
			if (player.GetIsInvulnerable())
				break;
			player.SetIsAlive(false);
			currentAsteroid->SetIsActive(false);
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
			sf::Vector2f currentLargePosition = currentLargeAsteroid->GetPosition();
			if (BulletVsLargeAsteroidCollision(*currentBullet, *currentLargeAsteroid))
			{
				SpawnSmallAsteroids(smallAsteroids, currentLargePosition);
				currentLargeAsteroid->SetIsActive(false);
				currentBullet->SetBulletSprite(false);
			}
		}

		for (std::list<SmallAsteroid*>::iterator smallAsteroidIterator = smallAsteroids.begin(); smallAsteroidIterator != smallAsteroids.end(); smallAsteroidIterator++)
		{
			SmallAsteroid* currentSmallAsteroid = *smallAsteroidIterator;
			if (BulletVsSmallAsteroidCollision(*currentBullet, *currentSmallAsteroid))
			{
				currentSmallAsteroid->SetIsActive(false);
				currentBullet->SetBulletSprite(false);
			}
		}
	}
}

bool CollisionManager::PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& largeAsteroid)
{
	return player.GetPlayerSprite().getGlobalBounds().intersects(largeAsteroid.GetAsteroidHitBox());
}

bool CollisionManager::PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& smallAsteroid)
{
	return player.GetPlayerSprite().getGlobalBounds().intersects(smallAsteroid.GetAsteroidHitBox());
}

bool CollisionManager::BulletVsLargeAsteroidCollision(Bullet& bullet, LargeAsteroid& largeAsteroid)
{
	return bullet.GetBulletSprite().getGlobalBounds().intersects(largeAsteroid.GetAsteroidHitBox());
}

bool CollisionManager::BulletVsSmallAsteroidCollision(Bullet& bullet, SmallAsteroid& smallAsteroid)
{
	return bullet.GetBulletSprite().getGlobalBounds().intersects(smallAsteroid.GetAsteroidHitBox());
}

void CollisionManager::SpawnSmallAsteroids(std::list<SmallAsteroid*> smallAsteroids, sf::Vector2f largePosition)
{
	std::cout << "SmallSpawn Called!\n";
	int smallSpawned = 0;
	for (std::list<SmallAsteroid*>::iterator smallAsteroidIterator = smallAsteroids.begin(); smallAsteroidIterator != smallAsteroids.end(); smallAsteroidIterator++)
	{
		int maxDebris = rand() % 3 + 2;
		if (smallSpawned >= maxDebris)
			break;
		SmallAsteroid* currentAsteroid = *smallAsteroidIterator;
		if (!currentAsteroid->GetIsActive())
		{
			currentAsteroid->SetIsActive(true);
			currentAsteroid->SetNewDebrisPosition(largePosition);
			smallSpawned++;
		}

	}
}


