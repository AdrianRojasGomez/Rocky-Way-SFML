#pragma once
#include <SFML/Audio.hpp>


class AudioManager
{
public:
	static AudioManager& getInstance();
	void PlayMenuMusic();
	void PlayGameplayMusic();

private:
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator= (const AudioManager&) = delete;

	sf::Music* menuMusic;
	sf::Music* gameplayMusic;

	bool isInMenu = false;

};