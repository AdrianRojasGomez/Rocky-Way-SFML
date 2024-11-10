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
	void PlayShieldOnSound();
	void PlayShotgunOnSound();
	void Play2XOnSound();

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

	sf::SoundBuffer* playerShieldBuffer = nullptr;
	sf::SoundBuffer* playerShotgunBuffer = nullptr;
	sf::SoundBuffer* player2XBuffer = nullptr;

	sf::Sound shootSound;
	sf::Sound engineSound;
	sf::Sound asteroidDestroyedSound;
	sf::Sound playerDestroyedSound;

	sf::Sound playerShieldSound;
	sf::Sound playerShotgunSound;
	sf::Sound player2XSound;

	sf::Sound enterSound;
	sf::Sound moveUISound;

	const int defaultMusicVolume = 30;
	const int maxShootSoundVolume = 13;
	const int maxEngineSoundVolume = 25;
	const int maxPlayerDestroyedSoundVolume = 30;
	const int maxDefaultSoundVolume = 35;
	bool isInMainMenu = false;
	bool engineSwitch = false;
	static constexpr int TOTAL_MUSICS = 3;
	int musics[TOTAL_MUSICS] = {};

	void SetGameMusic();
	void SetGameSounds();
	void SetDefaultVolumes();

};