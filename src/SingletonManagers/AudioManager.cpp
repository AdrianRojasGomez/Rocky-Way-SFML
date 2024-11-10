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

	enterBuffer = ResourceManager::getInstance().GetEnterUIBuffer();
	enterSound.setBuffer(*enterBuffer);

	uiMoveBuffer = ResourceManager::getInstance().GetMoveUIBuffer();
	moveUISound.setBuffer(*uiMoveBuffer);

	playerShieldBuffer = ResourceManager::getInstance().GetShieldBuffer();
	playerShieldSound.setBuffer(*playerShieldBuffer);

	playerShotgunBuffer = ResourceManager::getInstance().GetShotgunBuffer();
	playerShotgunSound.setBuffer(*playerShotgunBuffer);

	player2XBuffer = ResourceManager::getInstance().Get2XBuffer();
	player2XSound.setBuffer(*player2XBuffer);
}

void AudioManager::SetDefaultVolumes()
{
	//Music
	menuMusic->setVolume(defaultMusicVolume);
	gameplayMusic->setVolume(defaultMusicVolume);
	gameOverMusic->setVolume(defaultMusicVolume);

	//Sound
	shootSound.setVolume(maxShootSoundVolume);
	engineSound.setVolume(maxEngineSoundVolume);
	playerDestroyedSound.setVolume(maxPlayerDestroyedSoundVolume);
	asteroidDestroyedSound.setVolume(100);
	enterSound.setVolume(100);
	moveUISound.setVolume(100);
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

	//MUSIC
	if (volume > defaultMusicVolume)
	{
		menuMusic->setVolume(defaultMusicVolume);
		gameplayMusic->setVolume(defaultMusicVolume);
	}
	else
	{
		menuMusic->setVolume(volume);
		gameplayMusic->setVolume(volume);
	}

	//SOUND
	if (volume > maxShootSoundVolume)
	{
		shootSound.setVolume(maxShootSoundVolume);
		engineSound.setVolume(maxEngineSoundVolume);
		playerDestroyedSound.setVolume(maxPlayerDestroyedSoundVolume);
		asteroidDestroyedSound.setVolume(100);
		enterSound.setVolume(100);
		moveUISound.setVolume(100);
	}
	else
	{
		shootSound.setVolume(volume);
		engineSound.setVolume(volume);
		playerDestroyedSound.setVolume(volume);
		asteroidDestroyedSound.setVolume(volume);
		enterSound.setVolume(volume);
		moveUISound.setVolume(volume);
	}
}

void AudioManager::MuteAll(bool isMuted)
{
	if (!isMuted)
	{
		//Sounds
		shootSound.setVolume(0);
		engineSound.setVolume(0);
		asteroidDestroyedSound.setVolume(0);
		playerDestroyedSound.setVolume(0);
		enterSound.setVolume(0);
		moveUISound.setVolume(0);

		//Music
		menuMusic->setVolume(0);
		gameplayMusic->setVolume(0);
		gameOverMusic->setVolume(0);
	}
	else
	{
		SetDefaultVolumes();
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

void AudioManager::PlayEnterUISound()
{
	enterSound.play();
}

void AudioManager::PlayMoveUISound()
{
	moveUISound.play();
}

void AudioManager::PlayShieldOnSound()
{
	playerShieldSound.play();
}

void AudioManager::PlayShotgunOnSound()
{
	playerShotgunSound.play();
}

void AudioManager::Play2XOnSound()
{
	player2XSound.play();
}
