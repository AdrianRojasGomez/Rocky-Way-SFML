#include <iostream>
#include "CollisionManager.h"
#include "../SingletonManagers/ScoreManager.h"

CollisionManager::CollisionManager()
{
}

void CollisionManager::Update(Player& player,
	std::list<Bullet*> bullets, 
	std::list<LargeAsteroid*> largeAsteroids,
	std::list<SmallAsteroid*> smallAsteroids,
	std::list<Collectable*> collectables)
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
			player.TriggerScreenshake();
			currentAsteroid->ShutDownAsteroid();
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
			player.TriggerScreenshake();
			currentAsteroid->ShutDownAsteroid();
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
				currentLargeAsteroid->ShutDownAsteroid();
				currentBullet->SetBulletSprite(false);
				ScoreManager::getInstance().AddScoreLarge();
			}
		}

		for (std::list<SmallAsteroid*>::iterator smallAsteroidIterator = smallAsteroids.begin(); smallAsteroidIterator != smallAsteroids.end(); smallAsteroidIterator++)
		{
			SmallAsteroid* currentSmallAsteroid = *smallAsteroidIterator;
			if (BulletVsSmallAsteroidCollision(*currentBullet, *currentSmallAsteroid))
			{
				currentSmallAsteroid->ShutDownAsteroid();
				currentBullet->SetBulletSprite(false);
				ScoreManager::getInstance().AddScoreSmall();
			}
		}
	}

	for (std::list<Collectable*>::iterator collectableIterator = collectables.begin(); collectableIterator != collectables.end(); collectableIterator++)
	{

		Collectable* currentCollectable = *collectableIterator;
		if (currentCollectable != nullptr && !currentCollectable->GetIsAlive())
		{
			continue;
		}

		if (PlayerVsCollectable(player, *currentCollectable))
		{
			std::cout << "collision player vs currentCollectable\n";
			CollectableType currentType = currentCollectable->GetCollectableType();

			switch (currentType)
			{
			case CollectableType::Shotgun:
				//player Shotgun Behavior
				break;
			case CollectableType::Shield:
				//player shield Behavior
				break;
			case CollectableType::DoubleScore:
				//player 2X Behavior
				break;
			case CollectableType::Unassigned:
				//Error unassigned
				break;
			default:
				break;

			}
			canShutDownCollectables = true;
		}
	}

	if (canShutDownCollectables)
	{
		canShutDownCollectables = false;
		for (std::list<Collectable*>::iterator collectableIterator = collectables.begin(); collectableIterator != collectables.end(); collectableIterator++)
		{
			Collectable* currentCollectable = *collectableIterator;
			currentCollectable->SetIsAlive(false);
		}
	}
}

bool CollisionManager::PlayerVsLargeAsteroidCollision(Player& player, LargeAsteroid& largeAsteroid)
{
	return player.GetPlayerHitbox().intersects(largeAsteroid.GetAsteroidHitBox());
}

bool CollisionManager::PlayerVsSmallAsteroidCollision(Player& player, SmallAsteroid& smallAsteroid)
{
	return player.GetPlayerHitbox().intersects(smallAsteroid.GetAsteroidHitBox());
}

bool CollisionManager::PlayerVsCollectable(Player& player, Collectable& collectable)
{
	return player.GetPlayerHitbox().intersects(collectable.GetCollectableHitbox());
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
	//This should be done by Wave, it is a Wave task, but collision Manager does not have to know Wave, 
	//so the question is, should it know it or is there another way to generate this function?
	int smallSpawned = 0;
	for (std::list<SmallAsteroid*>::iterator smallAsteroidIterator = smallAsteroids.begin(); smallAsteroidIterator != smallAsteroids.end(); smallAsteroidIterator++)
	{
		int maxDebris = rand() % MAX_DEBRIS + MIN_DEBRIS;
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


