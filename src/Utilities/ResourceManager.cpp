#include "ResourceManager.h"
#include <iostream>

const std::string ResourceManager::spritePathLarge = "res/assets/Enemies/MeteorLarge.png";
const std::string ResourceManager::spritePathSmall = "res/assets/Enemies/MeteorSmall.png";
sf::Texture* ResourceManager::largeAsteroidTexture = nullptr;
sf::Texture* ResourceManager::smallAsteroidTexture = nullptr;

ResourceManager::~ResourceManager()
{
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

sf::Texture* ResourceManager::GetLargeAsteroidTexture()
{
	if (largeAsteroidTexture == nullptr)
	{
		largeAsteroidTexture = LoadTexture(spritePathLarge);
	}
	return largeAsteroidTexture;
}

sf::Texture* ResourceManager::GetSmallAsteroidTexture()
{
	if (smallAsteroidTexture == nullptr)
	{
		smallAsteroidTexture = LoadTexture(spritePathSmall);
	}
	return smallAsteroidTexture;
}

sf::Texture* ResourceManager::LoadTexture(std::string path)
{
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile(spritePathLarge))
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



