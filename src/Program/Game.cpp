#include <ctime>
#include "Game.h"


Game::Game()
{
	srand(time(0));
	videoMode = sf::VideoMode(WIDTH, HEIGHT);
	window.create(videoMode, "Rocky Way");
}

void Game::Run()
{
	while (window.isOpen())
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
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::Update()
{
	Gameplay::getInstance().Update();
}

void Game::Draw()
{
	window.clear(sf::Color::Black);
	Gameplay::getInstance().Draw(window);
	window.display();
}