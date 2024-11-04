#include <iostream>
#include "ResourceManager.h"

const std::string ResourceManager::pathTextureSplash = "res/assets/Background/Splash.png";
const std::string ResourceManager::pathTextureMenuBG = "res/assets/Background/Background00.png";
const std::string ResourceManager::pathTextureBG = "res/assets/Background/Background01.png";
const std::string ResourceManager::pathTexturePlayer = "res/assets/Player/PlayerSheet.png";
const std::string ResourceManager::pathTextureBullet = "res/assets/Player/BasicShot.png";
const std::string ResourceManager::pathTextureLarge = "res/assets/Enemies/MeteorLarge.png";
const std::string ResourceManager::pathTextureSmall = "res/assets/Enemies/MeteorSmall.png";
const std::string ResourceManager::pathTextureMusicOn = "res/assets/UI/musicOn.png";
const std::string ResourceManager::pathTextureMusicOff = "res/assets/UI/musicOff.png";
const std::string ResourceManager::pathFontOxaniumSemiBold = "res/assets/Fonts/Oxanium-SemiBold.ttf";
const std::string ResourceManager::pathMusicMenu = "res/assets/Audio/Music/Menu.wav";
const std::string ResourceManager::pathMusicGameplay = "res/assets/Audio/Music/Gameplay.wav";
const std::string ResourceManager::pathSoundShootBuffer = "res/assets/Audio/SFX/PulseShot.wav";

sf::Texture* ResourceManager::splashBackgroundTexture = nullptr;
sf::Texture* ResourceManager::menuBackgroundTexture = nullptr;
sf::Texture* ResourceManager::gameBackgroundTexture = nullptr;
sf::Texture* ResourceManager::playerTexture = nullptr;
sf::Texture* ResourceManager::bulletTexture = nullptr;
sf::Texture* ResourceManager::largeAsteroidTexture = nullptr;
sf::Texture* ResourceManager::smallAsteroidTexture = nullptr;
sf::Texture* ResourceManager::musicOnTexture = nullptr;
sf::Texture* ResourceManager::musicOffTexture = nullptr;
sf::Font* ResourceManager::oxaniumSemiBoldFont = nullptr;
sf::Music* ResourceManager::menuMusic = nullptr;
sf::Music* ResourceManager::gameplayMusic = nullptr;
sf::SoundBuffer* ResourceManager::shootSoundBuffer = nullptr;


ResourceManager::~ResourceManager()
{
	if (splashBackgroundTexture != nullptr)
	{
		delete splashBackgroundTexture;
		splashBackgroundTexture = nullptr;
	}

	if (menuBackgroundTexture != nullptr)
	{
		delete menuBackgroundTexture;
		menuBackgroundTexture = nullptr;
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

	if (musicOnTexture != nullptr)
	{
		delete musicOnTexture;
		musicOnTexture = nullptr;
	}

	if (musicOffTexture != nullptr)
	{
		delete musicOffTexture;
		musicOffTexture = nullptr;
	}

	if (oxaniumSemiBoldFont != nullptr)
	{
		delete oxaniumSemiBoldFont;
		oxaniumSemiBoldFont = nullptr;
	}

	if (menuMusic != nullptr)
	{
		menuMusic->stop();
		delete menuMusic;
		menuMusic = nullptr;
	}

	if (gameplayMusic != nullptr)
	{
		gameplayMusic->stop();
		delete gameplayMusic;
		gameplayMusic = nullptr;
	}
}

sf::Texture* ResourceManager::GetSplashTexture()
{
	if (splashBackgroundTexture == nullptr)
	{
		splashBackgroundTexture = new sf::Texture;
		splashBackgroundTexture = LoadTexture(pathTextureSplash);
	}
	return splashBackgroundTexture;
}

sf::Texture* ResourceManager::GetMenuBackgroundTexture()
{
	if (menuBackgroundTexture == nullptr)
	{
		menuBackgroundTexture = new sf::Texture();
		menuBackgroundTexture = LoadTexture(pathTextureMenuBG);
	}
	return menuBackgroundTexture;
}

sf::Texture* ResourceManager::GetBackgroundTexture()
{
	if (gameBackgroundTexture == nullptr)
	{
		gameBackgroundTexture = new sf::Texture;
		gameBackgroundTexture = LoadTexture(pathTextureBG);
	}
	return gameBackgroundTexture;
}

sf::Texture* ResourceManager::GetPlayerTexture()
{
	if (playerTexture == nullptr)
	{
		playerTexture = new sf::Texture;
		playerTexture = LoadTexture(pathTexturePlayer);
	}
	return playerTexture;
}

sf::Texture* ResourceManager::GetBulletTexture()
{
	if (bulletTexture == nullptr)
	{
		bulletTexture = new sf::Texture;
		bulletTexture = LoadTexture(pathTextureBullet);
	}
	return bulletTexture;
}

sf::Texture* ResourceManager::GetLargeAsteroidTexture()
{
	if (largeAsteroidTexture == nullptr)
	{
		largeAsteroidTexture = new sf::Texture;
		largeAsteroidTexture = LoadTexture(pathTextureLarge);
	}
	return largeAsteroidTexture;
}

sf::Texture* ResourceManager::GetSmallAsteroidTexture()
{
	if (smallAsteroidTexture == nullptr)
	{
		smallAsteroidTexture = new sf::Texture;
		smallAsteroidTexture = LoadTexture(pathTextureSmall);
	}
	return smallAsteroidTexture;
}

sf::Texture* ResourceManager::GetMusicOffTexture()
{
	if (musicOffTexture == nullptr)
	{
		musicOffTexture = new sf::Texture;
		musicOffTexture = LoadTexture(pathTextureMusicOff);
	}
	
	return musicOffTexture;
}

sf::Texture* ResourceManager::GetMusicOnTexture()
{
	if (musicOnTexture == nullptr)
	{
		musicOnTexture = new sf::Texture;
		musicOnTexture = LoadTexture(pathTextureMusicOn);
	}

	return musicOnTexture;
}

sf::Font* ResourceManager::GetOxaniumSemiBoldFont()
{
	if (oxaniumSemiBoldFont == nullptr)
	{
		oxaniumSemiBoldFont = new sf::Font;
		oxaniumSemiBoldFont = LoadFont(pathFontOxaniumSemiBold);
	}
	return oxaniumSemiBoldFont;
}

sf::SoundBuffer* ResourceManager::GetShootSoundBuffer()
{
	if (shootSoundBuffer == nullptr)
	{
		shootSoundBuffer = new sf::SoundBuffer;
		shootSoundBuffer = LoadSoundBuffer(pathSoundShootBuffer);
	}
	return shootSoundBuffer;
}

sf::Music* ResourceManager::GetMenuMusic()
{
	if (menuMusic == nullptr)
	{
		menuMusic = new sf::Music();
		menuMusic = LoadMusic(pathMusicMenu);
	}
	return menuMusic;
}

sf::Music* ResourceManager::GetGameplayMusic()
{
	if (gameplayMusic == nullptr)
	{
		gameplayMusic = new sf::Music();
		gameplayMusic = LoadMusic(pathMusicGameplay);
	}
	return gameplayMusic;
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

sf::Font* ResourceManager::LoadFont(std::string path)
{
	sf::Font* font = new sf::Font();
	if (font->loadFromFile(path))
	{
		return font;
	}

	if (font != nullptr)
	{
		delete font;
		font = nullptr;
	}
	std::cout << "DEBUG: Error!!!!!!!! LOADING " << path << "  FONT" << std::endl;
	return nullptr;
}


sf::SoundBuffer* ResourceManager::LoadSoundBuffer(std::string path)
{
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	if (buffer->loadFromFile(path))
	{
		return buffer;
	}
}

sf::Music* ResourceManager::LoadMusic(std::string path)
{
	sf::Music* music = new sf::Music();

	if (music->openFromFile(path))
	{
		return music;
	}

	if (music != nullptr)
	{
		delete music;
		music = nullptr;
	}
	std::cout << "DEBUG: Error!!!!!!!! LOADING " << path << "  MUSIC" << std::endl;
	return nullptr;
}
