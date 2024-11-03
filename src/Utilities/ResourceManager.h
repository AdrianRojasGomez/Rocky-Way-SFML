#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
public:
	~ResourceManager();
	static sf::Texture* GetSplashTexture();
	static sf::Texture* GetMenuBackgroundTexture();
	static sf::Texture* GetBackgroundTexture();
	static sf::Texture* GetPlayerTexture();
	static sf::Texture* GetBulletTexture();
	static sf::Texture* GetLargeAsteroidTexture();
	static sf::Texture* GetSmallAsteroidTexture();
	static sf::Texture* GetMusicOffTexture();
	static sf::Texture* GetMusicOnTexture();
	static sf::Font* GetOxaniumSemiBoldFont();
	static sf::Music* GetMenuMusic();
	static sf::Music* GetGameplayMusic();

private:
	static sf::Texture* splashBackgroundTexture;
	static sf::Texture* menuBackgroundTexture;
	static sf::Texture* gameBackgroundTexture;
	static sf::Texture* playerTexture;
	static sf::Texture* bulletTexture;
	static sf::Texture* largeAsteroidTexture;
	static sf::Texture* smallAsteroidTexture;
	static sf::Texture* musicOnTexture;
	static sf::Texture* musicOffTexture;
	static sf::Font* oxaniumSemiBoldFont;
	static sf::Music* menuMusic;
	static sf::Music* gameplayMusic;

	static const std::string pathTextureSplash;
	static const std::string pathTextureMenuBG;
	static const std::string pathTextureBG;
	static const std::string pathTexturePlayer;
	static const std::string pathTextureBullet;
	static const std::string pathTextureLarge;
	static const std::string pathTextureSmall;
	static const std::string pathTextureMusicOn;
	static const std::string pathTextureMusicOff;
	static const std::string pathFontOxaniumSemiBold;
	static const std::string pathMusicMenu;
	static const std::string pathMusicGameplay;

	static sf::Texture* LoadTexture(std::string path);
	static sf::Font* LoadFont(std::string path);
	static sf::Music* LoadMusic(std::string path);
};

