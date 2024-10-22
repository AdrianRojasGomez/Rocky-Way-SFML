#pragma once
#include <SFML/Graphics.hpp>

enum class GameState
{
	Off = 0,
	MainMenu = 1,
	Gameplay = 2,
	Stats = 3,
	ExitGame = 4
};

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