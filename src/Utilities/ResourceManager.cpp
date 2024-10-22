#include <iostream>
#include "ResourceManager.h"

const std::string ResourceManager::spritePathMenuBG = "res/assets/Background/Background00.png";
const std::string ResourceManager::spritePathBG = "res/assets/Background/Background01.png";
const std::string ResourceManager::spritePathPlayer = "res/assets/Player/Player.png";
const std::string ResourceManager::spritePathBullet = "res/assets/Traces/BasicShot.png";
const std::string ResourceManager::spritePathLarge  = "res/assets/Enemies/MeteorLarge.png";
const std::string ResourceManager::spritePathSmall  = "res/assets/Enemies/MeteorSmall.png";
sf::Texture* ResourceManager::menuBackgroundTexture = nullptr;
sf::Texture* ResourceManager::gameBackgroundTexture = nullptr;
sf::Texture* ResourceManager::playerTexture = nullptr;
sf::Texture* ResourceManager::bulletTexture = nullptr;
sf::Texture* ResourceManager::largeAsteroidTexture = nullptr;
sf::Texture* ResourceManager::smallAsteroidTexture = nullptr;

ResourceManager::~ResourceManager()
{
	if (menuBackgroundTexture != nullptr)
	{
		delete gameBackgroundTexture;
		gameBackgroundTexture = nullptr;
	}

	if (gameBackgroundTexture != nullptr)
	{
		delete gameBackgroundTexture;
		gameBackgroundTexture = nullptr;
	}

	if (playerTexture != nullptr)
	{
		delete playerTexture;
		playerTexture = nullptr;
	}

	if (bulletTexture != nullptr)
	{
		delete bulletTexture;
		bulletTexture = nullptr;
	}

	if (largeAsteroidTexture != nullptr)
	{
		delete largeAsteroidTexture;
		largeAsteroidTexture = nullptr;
	}

	if (smallAsteroidTexture != nullptr)
	{
		delete smallAsteroidTexture;
		smallAsteroidTexture = nullptr;
	}
}

sf::Texture* ResourceManager::GetMenuBackgroundTexture()
{
	if (gameBackgroundTexture == nullptr)
	{
		gameBackgroundTexture = LoadTexture(spritePathBG);
	}
	return gameBackgroundTexture;
}

sf::Texture* ResourceManager::GetBackgroundTexture()
{
	if (gameBackgroundTexture == nullptr)
	{
		gameBackgroundTexture = LoadTexture(spritePathBG);
	}
	return gameBackgroundTexture;
}

sf::Texture* ResourceManager::GetPlayerTexture()
{
	if (playerTexture == nullptr)
	{
		playerTexture = LoadTexture(spritePathPlayer);
	}
	return playerTexture;
}

sf::Texture* ResourceManager::GetBulletTexture()
{
	if (bulletTexture == nullptr)
	{
		bulletTexture = LoadTexture(spritePathBullet);
	}
	return bulletTexture;
}

sf::Texture* ResourceManager::GetSmallAsteroidTexture()
{
	if (smallAsteroidTexture == nullptr)
	{
		smallAsteroidTexture = LoadTexture(spritePathSmall);
	}
	return smallAsteroidTexture;
}

sf::Texture* ResourceManager::GetLargeAsteroidTexture()
{
	if (largeAsteroidTexture == nullptr)
	{
		largeAsteroidTexture = LoadTexture(spritePathLarge);
	}
	return largeAsteroidTexture;
}

sf::Texture* ResourceManager::LoadTexture(std::string path)
{
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile(path))
	{
		return texture;
	}

	if (texture != nullptr)
	{
		delete texture;
		texture = nullptr;
	}
	std::cout << "DEBUG: Error!!!!!!!! LOADING " << path << "  TEXTURE" << std::endl;
	return nullptr;
}



