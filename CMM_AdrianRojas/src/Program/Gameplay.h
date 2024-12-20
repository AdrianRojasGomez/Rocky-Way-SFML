#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "CollisionManager.h"
#include "GameState.h"
#include "Pause.h"
#include "UI.h"
#include "Wave.h"
#include "../Utilities/ScreenShakeUtility.h"

class Gameplay
{
public:
	Gameplay(GameState* gameState, ScreenShake* screenshake);
	~Gameplay();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);
	void ResetGameplay(bool isMenu);

private:

	ScreenShake* screenShake;
	GameState* gameState;
	Background* background;
	UI* ui;
	Player* player;
	Wave* wave;
	CollisionManager* collisionManager;
	Pause* pause;

	void InitializeGameOnReturn();

};