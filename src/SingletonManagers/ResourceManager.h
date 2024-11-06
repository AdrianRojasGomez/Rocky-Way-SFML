#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager
{
public:
	static ResourceManager& getInstance();
	sf::Image* GetIconImage();

	sf::Texture* GetSplashTexture();
	sf::Texture* GetMenuBackgroundTexture();
	sf::Texture* GetBackgroundTexture();
	sf::Texture* GetPauseBackgroundTexture();
	sf::Texture* GetPlayerTexture();
	sf::Texture* GetBulletTexture();
	sf::Texture* GetLargeAsteroidTexture();
	sf::Texture* GetSmallAsteroidTexture();
	sf::Texture* GetMusicSwitchTexture();
	sf::Texture* GetImpactTexture();

	sf::Texture* GetLifeUITexture();
	sf::Texture* GetLifeLostUITexture();
	sf::Texture* GetEnterUITexture();


	sf::Font* GetOxaniumSemiBoldFont();

	sf::SoundBuffer* GetShootSoundBuffer();
	sf::SoundBuffer* GetEngineSoundBuffer();
	sf::SoundBuffer* GetAsteroidDestroyedBuffer();
	sf::SoundBuffer* GetPlayerDestroyedBuffer();

	sf::SoundBuffer* GetEnterUIBuffer();
	sf::SoundBuffer* GetMoveUIBuffer();

	sf::Music* GetMenuMusic();
	sf::Music* GetGameplayMusic();
	sf::Music* GetGameOverMusic();


private:
	ResourceManager();
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator= (const ResourceManager&) = delete;
	~ResourceManager();

	sf::Image* iconImage = nullptr;

	sf::Texture* splashBackgroundTexture = nullptr;
	sf::Texture* menuBackgroundTexture = nullptr;
	sf::Texture* pauseBackgroundTexture = nullptr;
	sf::Texture* gameBackgroundTexture = nullptr;
	sf::Texture* playerTexture = nullptr;
	sf::Texture* bulletTexture = nullptr;
	sf::Texture* largeAsteroidTexture = nullptr;
	sf::Texture* smallAsteroidTexture = nullptr;
	sf::Texture* musicSwitchTexture = nullptr;
	sf::Texture* impactTexture = nullptr;

	sf::Texture* lifeUITexture = nullptr;
	sf::Texture* lifeLostUITexture = nullptr;
	sf::Texture* enterUITexture = nullptr;

	sf::Font* oxaniumSemiBoldFont = nullptr;

	sf::SoundBuffer* shootSoundBuffer = nullptr;
	sf::SoundBuffer* engineSoundBuffer = nullptr;
	sf::SoundBuffer* asteroidDestroyedSoundBuffer = nullptr;
	sf::SoundBuffer* playerDestroyedSoundBuffer = nullptr;

	sf::SoundBuffer* enterUISoundBuffer = nullptr;
	sf::SoundBuffer* moveUISoundBuffer = nullptr;

	sf::Music* menuMusic = nullptr;
	sf::Music* gameplayMusic = nullptr;
	sf::Music* gameOverMusic = nullptr;

	//Icon
	const std::string pathImageIcon = "res/assets/System/icon.png";

	//Gameplay
	const std::string pathTextureSplash = "res/assets/Background/Splash.png";
	const std::string pathTextureMenuBG = "res/assets/Background/Background00.png";
	const std::string pathTexturePauseBG = "res/assets/Background/PauseBackground.png";
	const std::string pathTextureBG = "res/assets/Background/Background01.png";
	const std::string pathTexturePlayer = "res/assets/Player/PlayerSheet.png";
	const std::string pathTextureBullet = "res/assets/Player/BasicShot.png";
	const std::string pathTextureLarge = "res/assets/Enemies/MeteorLarge.png";
	const std::string pathTextureSmall = "res/assets/Enemies/MeteorSmall.png";
	const std::string pathTextureMusicSwitch = "res/assets/UI/MusicMuteSwitch.png";
	const std::string pathTextureHitEffect = "res/assets/Effects/HitEffect.png";

	//UI
	const std::string pathTextureLifeUI = "res/assets/UI/LifeUI.png";
	const std::string pathTextureLifeLostUI = "res/assets/UI/LifelostUI.png";
	const std::string pathTextureEnterUI = "res/assets/Background/Enter.png";

	//UI Sounds
	const std::string pathSoundEnterUI = "res/assets/Audio/UI/EnterSci-fi.wav";
	const std::string pathSoundMoveUI = "res/assets/Audio/UI/NavigateHoverSoftC.wav";

	//Fonts
	const std::string pathFontOxaniumSemiBold = "res/assets/Fonts/Oxanium-SemiBold.ttf";

	//Sounds
	const std::string pathSoundShootBuffer = "res/assets/Audio/SFX/PulseShot.wav";
	const std::string pathSoundEngineBuffer = "res/assets/Audio/SFX/spaceEngineLow_001.ogg";
	const std::string pathAsteroidDestroyedBuffer = "res/assets/Audio/SFX/bong_001.ogg";
	const std::string pathPlayerDestroyedBuffer = "res/assets/Audio/SFX/explosionCrunch_004.ogg";

	//Musics
	const std::string pathMusicMenu = "res/assets/Audio/Music/MenuElectronicChilledCut60.wav";
	const std::string pathMusicGameplay = "res/assets/Audio/Music/GameplayElectronicRoutinecut60.wav";
	const std::string pathMusicGameOver = "res/assets/Audio/Music/GameOverElectronicDefeatcut60.wav";
	
	sf::Image* LoadImage(std::string path);
	sf::Texture* LoadTexture(std::string path);
	sf::Font* LoadFont(std::string path);
	sf::SoundBuffer* LoadSoundBuffer(std::string path);
	sf::Music* LoadMusic(std::string path);

	void LoadAllTextures();
	void LoadAllSoundBuffers();
	void LoadAllMusics();
};

