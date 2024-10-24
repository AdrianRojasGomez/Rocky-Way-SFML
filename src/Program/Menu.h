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
	sf::Texture* menuBackgroundTexture = nullptr;
	//sf::Texture* buttonPlayTexture;
	//sf::Texture* buttonOptionsTexture;
	//sf::Texture* buttonHighscoreTexture;
	//sf::Texture* buttonQuitTexture;
	sf::Sprite menuBackgroundSprite;
	sf::Font* titleFont = nullptr;
	sf::Text gameTitle;

	const std::string TITLE = "ROCKY WAY";
	void InitializeBackground();
	void CreateTitle();
	
};