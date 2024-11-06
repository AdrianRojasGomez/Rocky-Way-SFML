#include <iostream>
#include "ResourceManager.h"

ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}

ResourceManager::ResourceManager()
{
	LoadImage(pathImageIcon);
	LoadFont(pathFontOxaniumSemiBold);
	LoadAllTextures();
	LoadAllSoundBuffers();
	LoadAllMusics();
}

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

	if (pauseBackgroundTexture != nullptr)
	{
		delete pauseBackgroundTexture;
		pauseBackgroundTexture = nullptr;
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

	if (musicSwitchTexture != nullptr)
	{
		delete musicSwitchTexture;
		musicSwitchTexture = nullptr;
	}

	if (oxaniumSemiBoldFont != nullptr)
	{
		delete oxaniumSemiBoldFont;
		oxaniumSemiBoldFont = nullptr;
	}

	if (shootSoundBuffer != nullptr)
	{
		delete shootSoundBuffer;
		shootSoundBuffer = nullptr;
	}
	
	if (engineSoundBuffer != nullptr)
	{
		delete engineSoundBuffer;
		engineSoundBuffer = nullptr;
	}
	
	if (asteroidDestroyedSoundBuffer != nullptr)
	{
		delete asteroidDestroyedSoundBuffer;
		asteroidDestroyedSoundBuffer = nullptr;
	}

	if (playerDestroyedSoundBuffer != nullptr)
	{
		delete playerDestroyedSoundBuffer;
		playerDestroyedSoundBuffer = nullptr;
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

sf::Image* ResourceManager::GetIconImage()
{
	if (iconImage == nullptr)
	{
		iconImage = new sf::Image;
		iconImage = LoadImage(pathImageIcon);
	}
	return iconImage;
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

sf::Texture* ResourceManager::GetPauseBackgroundTexture()
{
	if (pauseBackgroundTexture == nullptr)
	{
		pauseBackgroundTexture = new sf::Texture;
		pauseBackgroundTexture = LoadTexture(pathTexturePauseBG);
	}
	return pauseBackgroundTexture;
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

sf::Texture* ResourceManager::GetMusicSwitchTexture()
{
	if (musicSwitchTexture == nullptr)
	{
		musicSwitchTexture = new sf::Texture;
		musicSwitchTexture = LoadTexture(pathTextureMusicSwitch);
	}

	return musicSwitchTexture;
}

sf::Texture* ResourceManager::GetImpactTexture()
{
	if (impactTexture == nullptr)
	{
		impactTexture = new sf::Texture;
		impactTexture = LoadTexture(pathTextureHitEffect);
	}

	return impactTexture;
}

sf::Texture* ResourceManager::GetLifeUITexture()
{
	if (lifeUITexture == nullptr)
	{
		lifeUITexture = new sf::Texture;
		lifeUITexture = LoadTexture(pathTextureLifeUI);
	}

	return lifeUITexture;
}

sf::Texture* ResourceManager::GetLifeLostUITexture()
{
	if (lifeLostUITexture == nullptr)
	{
		lifeLostUITexture = new sf::Texture;
		lifeLostUITexture = LoadTexture(pathTextureLifeLostUI);
	}

	return lifeLostUITexture;
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

sf::SoundBuffer* ResourceManager::GetEngineSoundBuffer()
{
	if (engineSoundBuffer == nullptr)
	{
		engineSoundBuffer = new sf::SoundBuffer;
		engineSoundBuffer = LoadSoundBuffer(pathSoundEngineBuffer);
	}
	return engineSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetAsteroidDestroyedBuffer()
{
	if (asteroidDestroyedSoundBuffer == nullptr)
	{
		asteroidDestroyedSoundBuffer = new sf::SoundBuffer;
		asteroidDestroyedSoundBuffer = LoadSoundBuffer(pathAsteroidDestroyedBuffer);
	}
	return asteroidDestroyedSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetPlayerDestroyedBuffer()
{
	if (playerDestroyedSoundBuffer == nullptr)
	{
		playerDestroyedSoundBuffer = new sf::SoundBuffer;
		playerDestroyedSoundBuffer = LoadSoundBuffer(pathPlayerDestroyedBuffer);
	}
	return playerDestroyedSoundBuffer;
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

sf::Music* ResourceManager::GetGameOverMusic()
{
	if (gameOverMusic == nullptr)
	{
		gameOverMusic = new sf::Music();
		gameOverMusic = LoadMusic(pathMusicGameOver);
	}
	return gameOverMusic;
}

sf::Image* ResourceManager::LoadImage(std::string path)
{
	sf::Image* image = new sf::Image();
	if (image->loadFromFile(path))
	{
		return image;
	}

	if (image != nullptr)
	{
		delete image;
		image = nullptr;
	}
	std::cout << "DEBUG: Error!!!!!!!! LOADING " << path << "  IMAGE" << std::endl;
	return nullptr;
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

void ResourceManager::LoadAllTextures()
{
	LoadTexture(pathTextureSplash);
	LoadTexture(pathTextureMenuBG);
	LoadTexture(pathTextureBG);
	LoadTexture(pathTexturePauseBG);
	LoadTexture(pathTexturePlayer);
	LoadTexture(pathTextureBullet);
	LoadTexture(pathTextureLarge);
	LoadTexture(pathTextureSmall);
	LoadTexture(pathTextureMusicSwitch);
	LoadTexture(pathTextureHitEffect);
	LoadTexture(pathTextureLifeUI);
	LoadTexture(pathTextureLifeLostUI);
}

void ResourceManager::LoadAllSoundBuffers()
{
	LoadSoundBuffer(pathSoundShootBuffer);
	LoadSoundBuffer(pathSoundEngineBuffer);
	LoadSoundBuffer(pathAsteroidDestroyedBuffer);
	LoadSoundBuffer(pathPlayerDestroyedBuffer);
}

void ResourceManager::LoadAllMusics()
{
	LoadMusic(pathMusicMenu);
	LoadMusic(pathMusicGameplay);
	LoadMusic(pathMusicGameOver);
}