#include <iostream> //DEBUG ONLY 
#include "Gameplay.h"

Gameplay::Gameplay(GameState* gameState)
{
	this->gameState = gameState;
	ui = new UI();
	player = new Player(ui);
	wave = new Wave(ui);
	collisionManager = new CollisionManager();
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

	if (background != nullptr)
	{
		delete background;
		background = nullptr;
	}	
	
}

void Gameplay::ResetGameplay()
{
	player->PlayerReset();
	wave->WaveReset();

	*gameState = GameState::Gameplay;
}


void Gameplay::Update()
{
	collisionManager->Update(*player, player->GetBullets(),  wave->GetLargeAsteroids(), wave->GetSmallAsteroids());
	wave->Update();
	ui->Update();;
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background->Draw(window);
	wave->Draw(window);
	player->Draw(window);
	ui->Draw(window);
}

