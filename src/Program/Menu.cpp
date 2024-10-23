#include <iostream>
#include "Menu.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Menu::Menu()
{
	this->menuBackgroundTexture = ResourceManager::GetMenuBackgroundTexture();
	InitializeBackground();
	std::cout << "Menu created \n";

}

void Menu::InitializeBackground()
{
	if (menuBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = menuBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		menuBackgroundSrpite.setTexture(*menuBackgroundTexture);
		menuBackgroundSrpite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Menu::Update()
{
	//system("cls");
	//std::cout << "Menu showing up! \n";
}

void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(menuBackgroundSrpite);
}
