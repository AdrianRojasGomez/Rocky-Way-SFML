#pragma once
#include <SFML/Audio.hpp>


class AudioManager
{
public:
	static AudioManager& getInstance();
	void PlayMenuMusic();
	void PlayGameplayMusic();
	void PlayGameOverMusic();
	void SetMusicVolume(int volume);
	void MuteAll(bool isMuted);
	void PlayShootSound();
	void PlayEngineSound();
	void StopEngineSound();
	void PlayAsteroidDestroyedSound();
	void PauseGameplayMusic();
	void ResumeGameplayMusic();
	sf::Music* GetMenuMusic() { return menuMusic; }
	sf::Music* GetGameplayMusic() { return gameplayMusic; }
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
	sf::Sound shootSound;
	sf::Sound engineSound;
	sf::Sound asteroidDestroyedSound;

	const int defaultMusicVolume = 80;
	const int maxShootSoundVolume = 25;
	const int maxEngineSoundVolume = 50;
	const int maxAsteroidDestroyedSoundVolume = 20;
	bool isInMainMenu = false;
	bool engineSwitch = false;

	void SetGameMusic();
	void SetPlayerSounds();
	void SetDefaultVolumes();

};