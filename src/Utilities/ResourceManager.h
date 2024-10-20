#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:

	~ResourceManager();
	static sf::Texture* GetLargeAsteroidTexture();
	static sf::Texture* GetSmallAsteroidTexture();
	static sf::Texture* GetPlayerTexture();
	static sf::Texture* GetBulletTexture();

private:

	static sf::Texture* playerTexture;
	static sf::Texture* bulletTexture;
	static sf::Texture* largeAsteroidTexture;
	static sf::Texture* smallAsteroidTexture;

	static const std::string spritePathPlayer;
	static const std::string spritePathBullet;
	static const std::string spritePathLarge;
	static const std::string spritePathSmall;
	static sf::Texture* LoadTexture(std::string path);
	

};

