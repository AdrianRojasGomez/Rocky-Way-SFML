#pragma once
#include <SFML/Graphics.hpp>



class Menu
{
public:
	Menu();
	~Menu();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture* menuBackgroundTexture;
	sf::Sprite menuBackgroundSprite;
	sf::Font* titleFont;
	sf::Text* gameTitle;

	const std::string TITLE = "ROCKY WAY";
	void InitializeBackground();
	void CreateTitle();
	
};