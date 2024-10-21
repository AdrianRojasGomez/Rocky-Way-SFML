#pragma once
#include <SFML/Graphics.hpp>
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




};