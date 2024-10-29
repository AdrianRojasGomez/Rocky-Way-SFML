#include "GameOver.h"
#include "../Utilities/ResourceManager.h"

GameOver::GameOver()
{
	backgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	menuFont = ResourceManager::GetOxaniumSemiBoldFont();
}

void GameOver::Update()
{

}

void GameOver::Draw(sf::RenderWindow& window)
{
	
}
