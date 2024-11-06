#pragma once
#include <SFML/Audio.hpp>


class AudioManager
{
public:
	static AudioManager& getInstance();
	void PlayMenuMusic();
	void PlayGameplayMusic();
	void StopAllMusic();
	void PlayGameOverMusic();
	void SetMusicVolume(int volume);
	void MuteAll(bool isMuted);
	void PlayShootSound();
	void PlayEngineSound();
	void StopEngineSound();
	void PlayAsteroidDestroyedSound();
	void PlayPlayerDestroyedSound();
	void PauseGameplayMusic();
	void ResumeGameplayMusic();
	void PlayEnterUISound();
	void PlayMoveUISound();

	sf::Music* GetMenuMusic() { return menuMusic; }
	sf::Music* GetGameplayMusic() { return gameplayMusic; }
	sf::Music* GetGameOverMusic() { return gameOverMusic; }
private:
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator= (const AudioManager&) = delete;

	sf::Music* menuMusic = nullptr;
	sf::Music* gameplayMusic = nullptr;
	sf::Music* gameOverMusic = nullptr;
	sf::SoundBuffer* shootSoundBuffer = nullptr;
	sf::SoundBuffer* engineSoundBuffer = nullptr;
	sf::SoundBuffer* asteroidDestroyedBuffer = nullptr;
	sf::SoundBuffer* playerDestroyedBuffer = nullptr;
	sf::SoundBuffer* enterBuffer = nullptr;
	sf::SoundBuffer* uiMoveBuffer = nullptr;
	sf::Sound shootSound;
	sf::Sound engineSound;
	sf::Sound asteroidDestroyedSound;
	sf::Sound playerDestroyedSound;
	sf::Sound enterSound;
	sf::Sound moveUISound;

	const int defaultMusicVolume = 50;
	const int maxShootSoundVolume = 20;
	const int maxEngineSoundVolume = 50;
	const int maxAsteroidDestroyedSoundVolume = 20;
	bool isInMainMenu = false;
	bool engineSwitch = false;

	void SetGameMusic();
	void SetGameSounds();
	void SetDefaultVolumes();

};