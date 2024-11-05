#include "Gameplay.h"

Gameplay::Gameplay(GameState* gameState, ScreenShake* screenshacke)
{
	this->gameState = gameState;
	this->screenShake = screenshacke;
	ui = new UI();
	player = new Player(ui, gameState, screenShake);
	wave = new Wave(ui);
	collisionManager = new CollisionManager();
	background = new Background();
	pause = new Pause(gameState);
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

	if (pause != nullptr)
	{
		delete pause;
		pause = nullptr;
	}

}

void Gameplay::Input(sf::Event event)
{
	if (*gameState == GameState::Pause)
	{
		pause->Input(event);
		return;
	}

	player->Input(event);
}


void Gameplay::Update()
{
	if (*gameState == GameState::Pause)
	{
		pause->Update();
		return;
	}

	if (pause->GetIsReset())
	{
		pause->SetIsReset(false);
		InitializeGameOnReturn();
		return;
	}

	player->Update();
	collisionManager->Update(*player, player->GetBullets(), wave->GetLargeAsteroids(), wave->GetSmallAsteroids());
	wave->Update();
	ui->Update();
}

void Gameplay::Draw(sf::RenderWindow& window)
{
	background->Draw(window);
	player->Draw(window);
	wave->Draw(window);
	ui->Draw(window);
	if (*gameState == GameState::Pause)
	{
		pause->Draw(window);
		return;
	}
}

void Gameplay::ResetGameplay(bool isMenu)
{
	wave->WaveReset();
	if (!isMenu)
		*gameState = GameState::Gameplay;
	else
		*gameState = GameState::MainMenu;
}

void Gameplay::InitializeGameOnReturn()
{
	wave->WaveReset();
	player->ResetFromPause();
}
