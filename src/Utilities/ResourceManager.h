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
	sf::Texture* GetPlayerTexture();
	sf::Texture* GetBulletTexture();
	sf::Texture* GetLargeAsteroidTexture();
	sf::Texture* GetSmallAsteroidTexture();
	sf::Texture* GetMusicOffTexture();
	sf::Texture* GetMusicOnTexture();
	sf::Font* GetOxaniumSemiBoldFont();
	sf::SoundBuffer* GetShootSoundBuffer();
	sf::Music* GetMenuMusic();
	sf::Music* GetGameplayMusic();


private:
	ResourceManager();
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator= (const ResourceManager&) = delete;
	~ResourceManager();

	sf::Image* iconImage = nullptr;
	sf::Texture* splashBackgroundTexture = nullptr;
	sf::Texture* menuBackgroundTexture = nullptr;
	sf::Texture* gameBackgroundTexture = nullptr;
	sf::Texture* playerTexture = nullptr;
	sf::Texture* bulletTexture = nullptr;
	sf::Texture* largeAsteroidTexture = nullptr;
	sf::Texture* smallAsteroidTexture = nullptr;
	sf::Texture* musicOnTexture = nullptr;
	sf::Texture* musicOffTexture = nullptr;
	sf::Font* oxaniumSemiBoldFont = nullptr;
	sf::Music* menuMusic = nullptr;
	sf::Music* gameplayMusic = nullptr;
	sf::SoundBuffer* shootSoundBuffer = nullptr;

	const std::string pathImageIcon = "res/assets/System/iconBlack2.png";

	const std::string pathTextureSplash = "res/assets/Background/Splash.png";
	const std::string pathTextureMenuBG = "res/assets/Background/Background00.png";
	const std::string pathTextureBG = "res/assets/Background/Background01.png";
	const std::string pathTexturePlayer = "res/assets/Player/PlayerSheet.png";
	const std::string pathTextureBullet = "res/assets/Player/BasicShot.png";
	const std::string pathTextureLarge = "res/assets/Enemies/MeteorLarge.png";
	const std::string pathTextureSmall = "res/assets/Enemies/MeteorSmall.png";
	const std::string pathTextureMusicOn = "res/assets/UI/musicOn.png";
	const std::string pathTextureMusicOff = "res/assets/UI/musicOff.png";

	const std::string pathFontOxaniumSemiBold = "res/assets/Fonts/Oxanium-SemiBold.ttf";

	const std::string pathSoundShootBuffer = "res/assets/Audio/SFX/PulseShot.wav";
	
	const std::string pathMusicMenu = "res/assets/Audio/Music/MenuElectronicChilledCut60.wav";
	const std::string pathMusicGameplay = "res/assets/Audio/Music/GameplayElectronicRoutinecut60.wav";
	
	sf::Image* LoadImage(std::string path);
	sf::Texture* LoadTexture(std::string path);
	sf::Font* LoadFont(std::string path);
	sf::SoundBuffer* LoadSoundBuffer(std::string path);
	sf::Music* LoadMusic(std::string path);

	void LoadAllTextures();
	void LoadAllSoundBuffers();
	void LoadAllMusics();
};

