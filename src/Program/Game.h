#pragma once
#include <SFML/Graphics.hpp>
#include "Gameplay.h"

class Game

{
public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Draw();

	sf::VideoMode videoMode;
	sf::RenderWindow window;
	const int WIDTH = 1280;
	const int HEIGHT = 720;



};