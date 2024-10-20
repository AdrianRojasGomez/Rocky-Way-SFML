#pragma once
#include <SFML/Graphics.hpp>
#include "Gameplay.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ResourceManager.h"

class Game

{
public:
	Game();
	~Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Draw();

	ResourceManager* resourceManager;
	sf::VideoMode* videoMode;
	sf::RenderWindow* window;
	const int WIDTH = 1280;
	const int HEIGHT = 720;



};