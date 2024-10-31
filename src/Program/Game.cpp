#include <ctime>
#include "Game.h"
#include "Gameplay.h"
#include "../Utilities/ScreenResolution.h"


Game::Game()
{
	srand(time(0));
	Game::gameState = GameState::MainMenu;
	videoMode = new sf::VideoMode(ScreenResolution::SCREEN_WIDTH_720P, ScreenResolution::SCREEN_HEIGHT_720P);
	window = new sf::RenderWindow(*videoMode, "Rocky Ways");
	resourceManager = new ResourceManager();
	gameplay = new Gameplay();
	menu = new Menu();
}

Game::~Game()
{
	if (gameplay != nullptr)
	{
		delete gameplay;
		gameplay = nullptr;
	}

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
	switch (gameState)
	{
	case GameState::SplashScreen:
		//Splash with instructions
		break;
	case GameState::MainMenu:
		gameState = menu->Update(gameState);
		break;
	case GameState::Gameplay:
		gameState = gameplay->Update(gameState);
		break;
	case GameState::Pause:
		//Pause Menu
		break;
	case GameState::GameOver:
		gameState = gameplay->:
		break;
	case GameState::Stats:
		
		break;
	case GameState::Options:
		//Options Menu (Sound and Mute mostly)
		break;
	case GameState::ExitGame:
		window->close();
		break;
	case GameState::Error:
		break;
	default:
		break;
	}

	std::cout << (int)this->gameState << " = Game gameState\n";
}

void Game::Draw()
{
	window->clear(sf::Color::Black);

	switch (gameState)
	{
	case GameState::SplashScreen:
		break;
	case GameState::MainMenu:
		menu->Draw(*window);
		break;
	case GameState::Gameplay:
		gameplay->Draw(*window);
		break;
	case GameState::GameOver:
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