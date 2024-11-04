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
	sf::Music* GetMenuMusic() { return menuMusic; }
	sf::Music* GetGameplayMusic() { return gameplayMusic; }

private:
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator= (const AudioManager&) = delete;

	sf::Music* menuMusic = nullptr;
	sf::Music* gameplayMusic = nullptr;
	sf::SoundBuffer* shootSoundBuffer = nullptr;
	sf::Sound shootSound;

	bool isInMainMenu = false;
	
	void SetGameMusic();
	void SetPlayerShootSound();

};