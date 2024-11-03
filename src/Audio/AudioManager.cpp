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

}

void AudioManager::PlayMenuMusic()
{
	if (isInMenu)
		return;

	isInMenu = true;
	gameplayMusic->stop();
	menuMusic->play();
}

void AudioManager::PlayGameplayMusic()
{
	if (!isInMenu)
		return;

	isInMenu = false;
	menuMusic->stop();
	gameplayMusic->play();
}
