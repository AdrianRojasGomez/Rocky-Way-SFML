#include "AudioManager.h"
#include "../SingletonManagers/ResourceManager.h"


AudioManager& AudioManager::getInstance()
{
	static AudioManager instance;
	return instance;
}

AudioManager::AudioManager()
{
	SetGameSounds();
	SetGameMusic();
	SetDefaultVolumes();
}

void AudioManager::SetGameMusic()
{
	menuMusic = ResourceManager::getInstance().GetMenuMusic();
	gameplayMusic = ResourceManager::getInstance().GetGameplayMusic();
	gameOverMusic = ResourceManager::getInstance().GetGameOverMusic();
	menuMusic->setLoop(true);
	gameplayMusic->setLoop(true);
	gameOverMusic->setLoop(true);
	engineSound.setLoop(true);

}

void AudioManager::SetGameSounds()
{
	shootSoundBuffer = ResourceManager::getInstance().GetShootSoundBuffer();
	shootSound.setBuffer(*shootSoundBuffer);
	engineSoundBuffer = ResourceManager::getInstance().GetEngineSoundBuffer();
	engineSound.setBuffer(*engineSoundBuffer);
	asteroidDestroyedBuffer = ResourceManager::getInstance().GetAsteroidDestroyedBuffer();
	asteroidDestroyedSound.setBuffer(*asteroidDestroyedBuffer);
	playerDestroyedBuffer = ResourceManager::getInstance().GetPlayerDestroyedBuffer();
	playerDestroyedSound.setBuffer(*playerDestroyedBuffer);
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
	StopAllMusic();
	menuMusic->play();
}

void AudioManager::PlayGameplayMusic()
{
	if (!isInMainMenu)
		return;

	isInMainMenu = false;
	StopAllMusic();
	gameplayMusic->play();
}

void AudioManager::StopAllMusic()
{
	gameplayMusic->stop();
	menuMusic->stop();
	gameOverMusic->stop();
}

void AudioManager::PlayGameOverMusic()
{
	StopAllMusic();
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
		asteroidDestroyedSound.setVolume(maxAsteroidDestroyedSoundVolume);
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
	if (engineSound.getStatus() == sf::SoundSource::Playing)
		return;

	engineSound.play();
}

void AudioManager::StopEngineSound()
{
	engineSound.stop();
}

void AudioManager::PlayAsteroidDestroyedSound()
{
	asteroidDestroyedSound.play();
}

void AudioManager::PlayPlayerDestroyedSound()
{
	playerDestroyedSound.play();
}

void AudioManager::PauseGameplayMusic()
{
	gameplayMusic->pause();
}

void AudioManager::ResumeGameplayMusic()
{
	if (gameplayMusic->getStatus() == sf::SoundSource::Paused)
		gameplayMusic->play();
}
