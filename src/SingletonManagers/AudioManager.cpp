#include "AudioManager.h"
#include "../SingletonManagers/ResourceManager.h"


AudioManager& AudioManager::getInstance()
{
	static AudioManager instance;
	return instance;
}

AudioManager::AudioManager()
{
	SetPlayerSounds();
	SetGameMusic();

}

void AudioManager::SetGameMusic()
{
	menuMusic = ResourceManager::getInstance().GetMenuMusic();
	gameplayMusic = ResourceManager::getInstance().GetGameplayMusic();
	gameOverMusic = ResourceManager::getInstance().GetGameOverMusic();
	menuMusic->setLoop(true);
	gameplayMusic->setLoop(true);
	gameOverMusic->setLoop(true);
	SetDefaultVolumes();
	menuMusic->setVolume(defaultMusicVolume);
	gameplayMusic->setVolume(defaultMusicVolume);

}

void AudioManager::SetPlayerSounds()
{
	shootSoundBuffer = ResourceManager::getInstance().GetShootSoundBuffer();
	shootSound.setBuffer(*shootSoundBuffer);
	shootSound.setVolume(maxShootSoundVolume);
	engineSoundBuffer = ResourceManager::getInstance().GetEngineSoundBuffer();
	engineSound.setBuffer(*engineSoundBuffer);
	engineSound.setVolume(maxEngineSoundVolume);
}

void AudioManager::SetDefaultVolumes()
{
	menuMusic->setVolume(defaultMusicVolume);
	gameplayMusic->setVolume(defaultMusicVolume);
	gameOverMusic->setVolume(defaultMusicVolume);
	shootSound.setVolume(maxShootSoundVolume);
	engineSound.setVolume(maxEngineSoundVolume);
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

void AudioManager::PlayGameOverMusic()
{
	gameOverMusic->play();
}

void AudioManager::SetMusicVolume(int volume)
{
	menuMusic->setVolume(volume);
	gameplayMusic->setVolume(volume);
	shootSound.setVolume(volume);
	if (volume > maxShootSoundVolume)
	{
		shootSound.setVolume(maxShootSoundVolume);
		engineSound.setVolume(maxEngineSoundVolume);
	}

}

void AudioManager::MuteAll(bool isMuted)
{
	if (!isMuted)
	{
		shootSound.setVolume(0);
		engineSound.setVolume(0);
		menuMusic->setVolume(0);
		gameplayMusic->setVolume(0);
		gameOverMusic->setVolume(0);
	}
	else
	{
		shootSound.setVolume(100);
		engineSound.setVolume(100);
		menuMusic->setVolume(100);
		gameplayMusic->setVolume(100);
		gameOverMusic->setVolume(100);
	}
}

void AudioManager::PlayShootSound()
{
	shootSound.play();
}

void AudioManager::PlayEngineSound()
{
	engineSound.play();
}

void AudioManager::StopEngineSound()
{
	engineSound.stop();
}
