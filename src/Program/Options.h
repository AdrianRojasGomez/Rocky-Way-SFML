#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Options
{


public:
	Options(GameState* gameState);
	~Options();
	void Input(sf::Event event);
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	GameState* gameState;

	sf::Font* font = nullptr;
	sf::Texture* optionsBackgroundTexture = nullptr;
	sf::Texture* musicSwitchTexture = nullptr;
	sf::Sprite optionsBackgroundSprite;
	sf::Sprite musicSwitchSprite;

	int selectedIndex = 0;

	const float SCALE_MUSIC_SPRITE = 0.7f;
	static constexpr int OPTIONS_AMOUNT = 3;
	const std::string OPTION_TITLE = "SETTINGS";
	const std::string OPTION_BUTTON_LABELS[OPTIONS_AMOUNT] = {"MUTE ALL", "VOLUME", "Main Menu"};
	sf::Text optionTitle;
	sf::Text optionButtons[OPTIONS_AMOUNT];
	sf::Text volumeText;
	sf::Text maxVolumeText;
	bool isMuted = false;
	bool isChangingVolume = false;
	//const int maxVolumeNumber = 50;
	int volumeNumber = 50;
	std::string volumeString = std::to_string(volumeNumber);
	sf::IntRect musicSwitchIntRect;
	int intRectPosX = 0;


	void InitializeBackground();
	void InitializeMusicSprites();
	void InitializeTitle();
	void InitializeButtons();
	void InitializeVolumeText();
	void UpdateSelectedButton();
	void UpdateVolumeNumber();
	void SelectButton();
	void IncreaseVolume();
	void DecreaseVolume();
	void CenterTextOrigin(sf::Text& textToCenter);
	void ModifyTextProperties(sf::Text& text);
};
