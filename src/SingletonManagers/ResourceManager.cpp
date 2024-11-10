#include <iostream>
#include "ResourceManager.h"

ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}

ResourceManager::ResourceManager()
{
	iconImage = LoadImage(pathImageIcon);
	oxaniumSemiBoldFont = LoadFont(pathFontOxaniumSemiBold);
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

	if (enterUITexture != nullptr)
	{
		delete enterUITexture;
		enterUITexture = nullptr;
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

	if (enterUISoundBuffer != nullptr)
	{
		delete enterUISoundBuffer;
		enterUISoundBuffer = nullptr;
	}

	if (moveUISoundBuffer != nullptr)
	{
		delete moveUISoundBuffer;
		moveUISoundBuffer = nullptr;
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

	if (shieldSoundBuffer != nullptr)
	{
		delete shieldSoundBuffer;
		shieldSoundBuffer = nullptr;
	}
	if (shotgunShoundBuffer != nullptr)
	{
		delete shotgunShoundBuffer;
		shotgunShoundBuffer = nullptr;
	}
	if (dobleScoreSoundBuffer != nullptr)
	{
		delete dobleScoreSoundBuffer;
		dobleScoreSoundBuffer = nullptr;
	}

	if (collectableShotgun != nullptr)
	{
		delete collectableShotgun;
		collectableShotgun = nullptr;
	}


	if (collectableShield != nullptr)
	{
		delete collectableShield;
		collectableShield = nullptr;
	}

	if (collectableX2 != nullptr)
	{
		delete collectableX2;
		collectableX2 = nullptr;
	}

	if (powerBulletTexture != nullptr)
	{
		delete powerBulletTexture;
		powerBulletTexture = nullptr;
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

sf::Texture* ResourceManager::GetPlayerShieldTexture()
{
	if (playerShieldTexture == nullptr)
	{
		playerShieldTexture = new sf::Texture;
		playerShieldTexture = LoadTexture(pathTexturePlayerShield);
	}
	return playerShieldTexture;
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

sf::Texture* ResourceManager::GetPowerBulletTexture()
{
	if (powerBulletTexture == nullptr)
	{
		powerBulletTexture = new sf::Texture;
		powerBulletTexture = LoadTexture(pathTexturePowerBullet);
	}
	return powerBulletTexture;
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

sf::Texture* ResourceManager::GetShotgunTexture()
{
	if (collectableShotgun == nullptr)
	{
		collectableShotgun = new sf::Texture;
		collectableShotgun = LoadTexture(pathTextureShotgun);
	}

	return collectableShotgun;
}

sf::Texture* ResourceManager::GetShieldTexture()
{
	if (collectableShield == nullptr)
	{
		collectableShield = new sf::Texture;
		collectableShield = LoadTexture(pathTextureShield);
	}

	return collectableShield;
}

sf::Texture* ResourceManager::Get2XTexture()
{
	if (collectableX2 == nullptr)
	{
		collectableX2 = new sf::Texture;
		collectableX2 = LoadTexture(pathTexture2X);
	}

	return collectableX2;
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

sf::Texture* ResourceManager::GetEnterUITexture()
{
	if (enterUITexture == nullptr)
	{
		enterUITexture = new sf::Texture;
		enterUITexture = LoadTexture(pathTextureEnterUI);
	}

	return enterUITexture;
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
		asteroidDestroyedSoundBuffer = LoadSoundBuffer(pathSoundAsteroidDestroyedBuffer);
	}
	return asteroidDestroyedSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetPlayerDestroyedBuffer()
{
	if (playerDestroyedSoundBuffer == nullptr)
	{
		playerDestroyedSoundBuffer = new sf::SoundBuffer;
		playerDestroyedSoundBuffer = LoadSoundBuffer(pathSoundPlayerDestroyedBuffer);
	}
	return playerDestroyedSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetShieldBuffer()
{
	//update
	if (shieldSoundBuffer == nullptr)
	{
		shieldSoundBuffer = new sf::SoundBuffer;
		shieldSoundBuffer = LoadSoundBuffer(pathSoundShieldOn);
	}
	return shieldSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetShotgunBuffer()
{
	//update
	if (shotgunShoundBuffer == nullptr)
	{
		shotgunShoundBuffer = new sf::SoundBuffer;
		shotgunShoundBuffer = LoadSoundBuffer(pathSoundShotgunOn);
	}
	return shotgunShoundBuffer;
}

sf::SoundBuffer* ResourceManager::Get2XBuffer()
{
	//update
	if (dobleScoreSoundBuffer == nullptr)
	{
		dobleScoreSoundBuffer = new sf::SoundBuffer;
		dobleScoreSoundBuffer = LoadSoundBuffer(pathSound2XOn);
	}
	return dobleScoreSoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetEnterUIBuffer()
{
	if (enterUISoundBuffer == nullptr)
	{
		enterUISoundBuffer = new sf::SoundBuffer;
		enterUISoundBuffer = LoadSoundBuffer(pathSoundEnterUI);
	}
	return enterUISoundBuffer;
}

sf::SoundBuffer* ResourceManager::GetMoveUIBuffer()
{
	if (moveUISoundBuffer == nullptr)
	{
		moveUISoundBuffer = new sf::SoundBuffer;
		moveUISoundBuffer = LoadSoundBuffer(pathSoundMoveUI);
	}
	return moveUISoundBuffer;
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
	splashBackgroundTexture = LoadTexture(pathTextureSplash);
	menuBackgroundTexture = LoadTexture(pathTextureMenuBG);
	pauseBackgroundTexture = LoadTexture(pathTexturePauseBG);
	gameBackgroundTexture = LoadTexture(pathTextureBG);

	playerTexture = LoadTexture(pathTexturePlayer);
	playerShieldTexture = LoadTexture(pathTexturePlayerShield);

	bulletTexture = LoadTexture(pathTextureBullet);
	powerBulletTexture = LoadTexture(pathTexturePowerBullet);

	largeAsteroidTexture = LoadTexture(pathTextureLarge);
	smallAsteroidTexture = LoadTexture(pathTextureSmall);

	musicSwitchTexture = LoadTexture(pathTextureMusicSwitch);

	impactTexture = LoadTexture(pathTextureHitEffect);

	collectableShotgun = LoadTexture(pathTextureShotgun);
	collectableX2 = LoadTexture(pathTexture2X);
	collectableShield = LoadTexture(pathTextureShield);

	lifeUITexture = LoadTexture(pathTextureLifeUI);
	lifeLostUITexture = LoadTexture(pathTextureLifeLostUI);
	enterUITexture = LoadTexture(pathTextureEnterUI);
}

void ResourceManager::LoadAllSoundBuffers()
{
	shootSoundBuffer = LoadSoundBuffer(pathSoundShootBuffer);
	engineSoundBuffer = LoadSoundBuffer(pathSoundEngineBuffer);
	asteroidDestroyedSoundBuffer = LoadSoundBuffer(pathSoundAsteroidDestroyedBuffer);
	playerDestroyedSoundBuffer = LoadSoundBuffer(pathSoundPlayerDestroyedBuffer);
	enterUISoundBuffer = LoadSoundBuffer(pathSoundEnterUI);
	moveUISoundBuffer = LoadSoundBuffer(pathSoundMoveUI);
	shieldSoundBuffer = LoadSoundBuffer(pathSoundShieldOn);
	shotgunShoundBuffer = LoadSoundBuffer(pathSoundShotgunOn);
	dobleScoreSoundBuffer = LoadSoundBuffer(pathSound2XOn);
}

void ResourceManager::LoadAllMusics()
{
	menuMusic = LoadMusic(pathMusicMenu);
	gameplayMusic = LoadMusic(pathMusicGameplay);
	gameOverMusic = LoadMusic(pathMusicGameOver);
}