#include <ctime>
#include "Game.h"

#include "Gameplay.h"
#include "../Utilities/ScreenResolution.h"


Game::Game()
{
	srand(time(0));
	videoMode = new sf::VideoMode(ScreenResolution::SCREEN_WIDTH_720P, ScreenResolution::SCREEN_HEIGHT_720P);
	window = new sf::RenderWindow(*videoMode, "Rocky Ways");
	resourceManager = new ResourceManager();
	gameState = new GameState(GameState::MainMenu);
	menu = new Menu();
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

	if (gameState != nullptr)
	{
		delete gameState;
		gameState = nullptr;
	}

	if (menu != nullptr)
	{
		delete menu;
		menu = nullptr;
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
	switch (*gameState)
	{
	case GameState::SplashScreen:
		break;
	case GameState::MainMenu:
		menu->Update();
		break;
	case GameState::Gameplay:
		Gameplay::getInstance().Update();
		break;
	case GameState::Stats:
		break;
	case GameState::ExitGame:
		break;
	case GameState::Error:
		break;
	default:
		break;
	}


}

void Game::Draw()
{
	window->clear(sf::Color::Black);

	switch (*gameState)
	{
	case GameState::SplashScreen:
		break;
	case GameState::MainMenu:
		menu->Draw(*window);
		break;
	case GameState::Gameplay:
		Gameplay::getInstance().Draw(*window);
		break;
	case GameState::Stats:
		break;
	case GameState::ExitGame:
		break;
	case GameState::Error:
		break;
	default:
		break;
	}

	window->display();
}