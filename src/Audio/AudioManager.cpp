#include "AudioManager.h"
#include "../Utilities/ResourceManager.h"


AudioManager& AudioManager::getInstance()
{
	static AudioManager instance;
	return instance;
}

AudioManager::AudioManager()
{
	SetPlayerShootSound();
	SetGameMusic();
	
}

void AudioManager::SetGameMusic()
{
	menuMusic = ResourceManager::getInstance().GetMenuMusic();
	gameplayMusic = ResourceManager::getInstance().GetGameplayMusic();
	menuMusic->setLoop(true);
	gameplayMusic->setLoop(true);
	menuMusic->setVolume(80);
	gameplayMusic->setVolume(80);
}

void AudioManager::SetPlayerShootSound()
{
	shootSoundBuffer = ResourceManager::getInstance().GetShootSoundBuffer();
	shootSound.setBuffer(*shootSoundBuffer);
	shootSound.setVolume(40);
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
	shootSound.setVolume(volume);
	menuMusic->setVolume(volume);
	gameplayMusic->setVolume(volume);
	
}

void AudioManager::MuteAll(bool isMuted)
{
	if (!isMuted)
	{
		shootSound.setVolume(0);
		menuMusic->setVolume(0);
		gameplayMusic->setVolume(0);
		
	}
	else
	{
		shootSound.setVolume(100);
		menuMusic->setVolume(100);
		gameplayMusic->setVolume(100);	
	}
}

void AudioManager::PlayShootSound()
{
	shootSound.play();
}
