#include <iostream>
#include "Pause.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Pause::Pause(GameState* gameState)
{
	this->gameState = gameState;
	menuFont = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	backgroundTexture = ResourceManager::getInstance().GetPauseBackgroundTexture();
	InitializeBackground();
	InitializeTitle();
	InitializeButtons();
}

Pause::~Pause()
{
}

void Pause::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::Escape)
			*gameState = GameState::Gameplay;

		if (event.key.code == sf::Keyboard::Enter)
		{
			SelectButton();
		}

		CheckForDirectionalInput(event);
	}
}

void Pause::Update()
{
	UpdateSelectedButton();
}

void Pause::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pauseTitleText);
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		window.draw(menuButtons[i]);
	}

}

void Pause::InitializeTitle()
{
	pauseTitleText.setFont(*menuFont);
	pauseTitleText.setString(pauseTitleString);
	pauseTitleText.setCharacterSize(130);
	pauseTitleText.setFillColor(sf::Color::White);
	pauseTitleText.setStyle(sf::Text::Bold);
	pauseTitleText.setOutlineThickness(3.0f);
	CenterTextOrigin(pauseTitleText);
	pauseTitleText.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, ScreenResolution::SCREEN_HEIGHT_720P * 0.4f);
}

void Pause::InitializeBackground()
{
	if (backgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = backgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		backgroundSprite.setTexture(*backgroundTexture);
		backgroundSprite.setScale(scaleX, scaleY);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING BACKGROUND TEXTURE" << std::endl;
}

void Pause::InitializeButtons()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		menuButtons[i].setFont(*menuFont);
		menuButtons[i].setString(PAUSE_BUTTONS_LABELS[i]);
		menuButtons[i].setCharacterSize(i == 0 ? playButtonSize : otherButtonsSize);
		menuButtons[i].setFillColor(sf::Color::White);

		float posX = 0, posY = 0;
		posX = ScreenResolution::SCREEN_WIDTH_720P * 0.5f;
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.75f) + i * 90;
		CenterTextOrigin(menuButtons[i]);
		menuButtons[i].setPosition(sf::Vector2f(posX, posY));
	}
}

void Pause::UpdateSelectedButton()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		if (i == selectedIndex)
		{
			menuButtons[i].setFillColor(sf::Color::Yellow);
			menuButtons[i].setOutlineColor(sf::Color::Black);
			menuButtons[i].setOutlineThickness(0.5f);
			menuButtons[i].setCharacterSize(i == 0 ? playButtonSize + 10 : otherButtonsSize + 5);
			CenterTextOrigin(menuButtons[i]);
		}
		else
		{
			menuButtons[i].setCharacterSize(i == 0 ? playButtonSize : otherButtonsSize);
			CenterTextOrigin(menuButtons[i]);
			menuButtons[i].setFillColor(sf::Color::White);
			menuButtons[i].setOutlineThickness(0);
			menuButtons[i].setOutlineColor(sf::Color::Transparent);
		}
	}
}

void Pause::SelectButton()
{
	switch (selectedIndex)
	{
	case 0:
		*gameState = GameState::Gameplay;
		break;
	case 1:
		isReset = true;
		*gameState = GameState::MainMenu;
		break;
	default:
		break;
	}
}

void Pause::CheckForDirectionalInput(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Up ||
		event.key.code == sf::Keyboard::W ||
		event.key.code == sf::Keyboard::Down ||
		event.key.code == sf::Keyboard::S)
	{
		selectedIndex = 1 - selectedIndex;
	}
}

void Pause::CenterTextOrigin(sf::Text& textToCenter)
{
	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width / 2, rc.height / 2);
}
