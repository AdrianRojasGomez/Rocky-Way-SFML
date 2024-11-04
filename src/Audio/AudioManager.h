#pragma once
#include <SFML/Audio.hpp>


class AudioManager
{
public:
	static AudioManager& getInstance();
	void PlayMenuMusic();
	void PlayGameplayMusic();
	void SetMusicVolume(int volume);
	void MuteAll(bool isMuted);
	void PlayShootSound();
	void PlayEngineSound();
	void StopEngineSound();
	sf::Music* GetMenuMusic() { return menuMusic; }
	sf::Music* GetGameplayMusic() { return gameplayMusic; }
private:
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator= (const AudioManager&) = delete;

	sf::Music* menuMusic = nullptr;
	sf::Music* gameplayMusic = nullptr;
	sf::SoundBuffer* shootSoundBuffer = nullptr;
	sf::SoundBuffer* engineSoundBuffer = nullptr;
	sf::Sound shootSound;
	sf::Sound engineSound;

	const int defaultMusicVolume = 80;
	const int maxShootSoundVolume = defaultMusicVolume * 0.5;
	const int maxEngineSoundVolume = maxShootSoundVolume;
	bool isInMainMenu = false;
	bool engineSwitch = false;

	void SetGameMusic();
	void SetPlayerSounds();

};