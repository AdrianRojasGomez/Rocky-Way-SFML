#include <ctime>
#include "Game.h"
#include "Gameplay.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"
#include "../Audio/AudioManager.h"


Game::Game()
{
	srand(time(0));
	Game::gameState = GameState::SplashScreen;
	videoMode = new sf::VideoMode(ScreenResolution::SCREEN_WIDTH_720P, ScreenResolution::SCREEN_HEIGHT_720P);
	window = new sf::RenderWindow(*videoMode, "Rocky Ways");
	//resourceManager = new ResourceManager();
	splash = new SplashScreen(&gameState);
	gameplay = new Gameplay(&gameState);
	menu = new Menu(&gameState);
	gameOver = new GameOver(&gameState);
	highScore = new HighScore(&gameState);
	options = new Options(&gameState);
	SetIcon();
}

Game::~Game()
{
	if (gameplay != nullptr)
	{
		delete gameplay;
		gameplay = nullptr;
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

	if (gameOver != nullptr)
	{
		delete gameOver;
		gameOver = nullptr;
	}

	if (highScore != nullptr)
	{
		delete highScore;
		highScore = nullptr;
	}

	if (splash != nullptr)
	{
		delete splash;
		splash = nullptr;
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

		switch (gameState)
		{
		case GameState::SplashScreen:
			splash->Input(event);
			break;
		case GameState::MainMenu:
			AudioManager::getInstance().PlayMenuMusic();
			menu->Input(event);
			break;
		case GameState::Gameplay:
			AudioManager::getInstance().PlayGameplayMusic();
			gameplay->Input(event);
			break;
		case GameState::Pause:
			gameplay->Input(event);
			break;
		case GameState::GameOver:
			gameOver->Input(event);
			break;
		case GameState::HighScores:
			highScore->Input(event);
			break;
		case GameState::Options:
			options->Input(event);
			break;
		case GameState::Replay:
			break;
		case GameState::ExitGame:
			break;
		case GameState::Error:
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	switch (gameState)
	{
	case GameState::SplashScreen:
		splash->Update();
		break;
	case GameState::MainMenu:
		menu->Update();
		break;
	case GameState::Gameplay:
		gameplay->Update();
		break;
	case GameState::Pause:
		gameplay->Update();
		break;
	case GameState::GameOver:
		gameOver->Update();
		break;
	case GameState::HighScores:
		highScore->Update();
		break;
	case GameState::Options:
		options->Update();
		break;
	case GameState::Replay:
		gameplay->ResetGameplay();
		break;
	case GameState::ExitGame:
		window->close();
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
	switch (gameState)
	{
	case GameState::SplashScreen:
		splash->Draw(*window);
		break;
	case GameState::MainMenu:
		menu->Draw(*window);
		break;
	case GameState::Gameplay:
		gameplay->Draw(*window);
		break;
	case GameState::Pause:
		gameplay->Draw(*window);
		break;
	case GameState::GameOver:
		gameOver->Draw(*window);
		break;
	case GameState::HighScores:
		highScore->Draw(*window);
		break;
	case GameState::Options:
		options->Draw(*window);
		break;
	case GameState::Replay:
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

void Game::SetIcon()
{
	iconImage = ResourceManager::getInstance().GetIconImage();
	window->setIcon(iconImage->getSize().x, iconImage->getSize().y, iconImage->getPixelsPtr());
}
