#include "AudioManager.h"
#include "../Utilities/ResourceManager.h"


AudioManager& AudioManager::getInstance()
{
	static AudioManager instance;
	return instance;
}

AudioManager::AudioManager()
{
	menuMusic = ResourceManager::GetMenuMusic();
	gameplayMusic = ResourceManager::GetGameplayMusic();
	menuMusic->setLoop(true);
	gameplayMusic->setLoop(true);
	menuMusic->setVolume(80);
	gameplayMusic->setVolume(80);
}

void AudioManager::PlayMenuMusic()
{
	if (isInMainMenu)
		return;

	isInMainMenu = true;
	gameplayMusic->stop();
	menuMusic->play();
}

void AudioManager::PlayGameplayMusic()
{
	if (!isInMainMenu)
		return;

	isInMainMenu = false;
	menuMusic->stop();
	gameplayMusic->play();
}

void AudioManager::SetMusicVolume(int volume)
{
	menuMusic->setVolume(volume);
	gameplayMusic->setVolume(volume);
}

void AudioManager::MuteAll(bool isMuted)
{
	if (!isMuted)
	{
		menuMusic->setVolume(0);
		gameplayMusic->setVolume(0);
	}
	else
	{
		menuMusic->setVolume(100);
		gameplayMusic->setVolume(100);
	}
}
