#pragma once
#include <SFML/Graphics.hpp>


class Background
{
public:
	Background();
	~Background();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture* backgroundTexture;
	sf::Sprite backgroundSprite;


	void InitializeBackground();
};