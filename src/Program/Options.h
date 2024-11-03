#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Options
{
	enum class OptionsSelected
	{
		MuteAll = 0,
		SetVolume = 1,
		ExitToMenu = 2
	};


public:
	Options(GameState* gameState);
	~Options();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);


private:
	OptionsSelected options;
	GameState* gameState;

	sf::Texture* optionsBackgroundTexture = nullptr;
	sf::Texture* musicOffTexture = nullptr;
	sf::Texture* musicOnTexture = nullptr;
	sf::Sprite optionsBackgroundSprite;
	sf::Sprite musicOffSprite;
	sf::Sprite musicOnSprite;


	static constexpr int OPTIONS_AMOUNT = 3;
	const std::string OPTION_TITLE = "SETTINGS";
	const std::string OPTION_BUTTON_LABELS[OPTIONS_AMOUNT] = {"MUTE ALL", "VOLUME", "Main Menu"};
	sf::Text optionTitle;


	void InitializeBackground();
	void InitializeMusicSprites();
	void InitializeTitle();
	void CenterTextOrigin(sf::Text& textToCenter);



};
