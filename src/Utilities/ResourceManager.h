#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:

	~ResourceManager();
	static sf::Texture* GetLargeAsteroidTexture();
	static sf::Texture* GetSmallAsteroidTexture();

private:

	static sf::Texture* largeAsteroidTexture;
	static sf::Texture* smallAsteroidTexture;

	static const std::string spritePathLarge;
	static const std::string spritePathSmall;
	static sf::Texture* LoadTexture(std::string path);
	

};

