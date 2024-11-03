#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
public:
	~ResourceManager();
	static sf::Texture* GetMenuBackgroundTexture();
	static sf::Texture* GetBackgroundTexture();
	static sf::Texture* GetPlayerTexture();
	static sf::Texture* GetBulletTexture();
	static sf::Texture* GetLargeAsteroidTexture();
	static sf::Texture* GetSmallAsteroidTexture();
	static sf::Font* GetOxaniumSemiBoldFont();
	static sf::Music* GetMenuMusic();
	static sf::Music* GetGameplayMusic();

private:
	static sf::Texture* menuBackgroundTexture;
	static sf::Texture* gameBackgroundTexture;
	static sf::Texture* playerTexture;
	static sf::Texture* bulletTexture;
	static sf::Texture* largeAsteroidTexture;
	static sf::Texture* smallAsteroidTexture;
	static sf::Font* oxaniumSemiBoldFont;
	static sf::Music* menuMusic;
	static sf::Music* gameplayMusic;

	static const std::string spritePathMenuBG;
	static const std::string spritePathBG;
	static const std::string spritePathPlayer;
	static const std::string spritePathBullet;
	static const std::string spritePathLarge;
	static const std::string spritePathSmall;
	static const std::string fontPathOxaniumSemiBold;
	static const std::string MusicPathMenu;
	static const std::string MusicPathGameplay;

	static sf::Texture* LoadTexture(std::string path);
	static sf::Font* LoadFont(std::string path);
	static sf::Music* LoadMusic(std::string path);
};

