#include <ctime>
#include "Game.h"
#include "Gameplay.h"


Game::Game()
{
	srand(time(0));
	videoMode = new sf::VideoMode(WIDTH, HEIGHT);
	window = new sf::RenderWindow(*videoMode, "Rocky Ways");
	resourceManager = new ResourceManager();
}

Game::~Game()
{
	if (resourceManager != nullptr)
	{
		delete resourceManager;
		resourceManager = nullptr;
	}

	if (videoMode != nullptr)
	{
		delete videoMode;
		videoMode = nullptr;
	}

	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}

}

void Game::Run()
{
	while (window->isOpen())
	{
		ProcessEvents();
		Update();
		Draw();
		Framerate::OnFrameEnd();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::Update()
{
	Gameplay::getInstance().Update();
}

void Game::Draw()
{
	window->clear(sf::Color::Black);
	Gameplay::getInstance().Draw(*window);
	window->display();
}