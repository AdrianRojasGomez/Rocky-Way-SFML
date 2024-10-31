#include <iostream> //DEBUG ONLY 
#include "Gameplay.h"

Gameplay::Gameplay()
{
	ui = new UI();
	player = new Player(ui);
	wave = new Wave(ui);
	collisionManager = new CollisionManager();
	gameOver = new GameOver();
	background = new Background();
}

Gameplay::~Gameplay()
{
	if (ui != nullptr)
	{
		delete ui;
		ui = nullptr;
	}

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}

	if (wave != nullptr)
	{
		delete wave;
		wave = nullptr;
	}

	if (collisionManager != nullptr)
	{
		delete collisionManager;
		collisionManager = nullptr;
	}

	if (gameOver != nullptr)
	{
		delete gameOver;
		gameOver = nullptr;
	}

	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}	
	
}

GameState Gameplay::ResetGameplay()
{
	player->PlayerReset();
	wave->WaveReset();
	return gameState = GameState::Gameplay;
}


GameState Gameplay::Update(GameState gameState)
{
	this->gameState = player->Update(gameState);
	collisionManager->Update(*player, player->GetBullets(),  wave->GetLargeAsteroids(), wave->GetSmallAsteroids());
	wave->Update();
	ui->Update();
	std::cout << (int)this->gameState << " = Gameplay gameState\n";
	return this->gameState;
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background->Draw(window);
	wave->Draw(window);
	player->Draw(window);
	ui->Draw(window);
}

