#pragma once
#include <SFML/Graphics.hpp>



class Menu
{
public:
	Menu();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture* menuBackgroundTexture;
	sf::Sprite menuBackgroundSrpite;

	void InitializeBackground();
};