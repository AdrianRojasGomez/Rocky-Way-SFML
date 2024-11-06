#include <iostream>
#include "Options.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"
#include "../SingletonManagers/AudioManager.h"

Options::Options(GameState* gameState)
{
	this->gameState = gameState;
	font = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	optionsBackgroundTexture = ResourceManager::getInstance().GetMenuBackgroundTexture();
	musicSwitchTexture = ResourceManager::getInstance().GetMusicSwitchTexture();
	musicSwitchIntRect = sf::IntRect(intRectPosX, 0, 100, 100);
	InitializeBackground();
	InitializeMusicSprites();
	InitializeTitle();
	InitializeButtons();
	InitializeVolumeText();
}

Options::~Options()
{
}

void Options::Input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (isChangingVolume)
		{
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
				IncreaseVolume();

			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
				DecreaseVolume();

			if (event.key.code == sf::Keyboard::Enter)
			{
				AudioManager::getInstance().PlayEnterUISound();
				isChangingVolume = false;
			}
			return;
		}

		if (event.key.code == sf::Keyboard::Enter)
		{
			AudioManager::getInstance().PlayEnterUISound();
			SelectButton();

			if (selectedIndex == 0)
				volumeNumber = 50;
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			AudioManager::getInstance().PlayMoveUISound();
			selectedIndex++;
			if (selectedIndex > 2)
				selectedIndex = 0;
		}
		if (event.key.code == sf::Keyboard::Up)
		{
			AudioManager::getInstance().PlayMoveUISound();
			selectedIndex--;
		}

		if (selectedIndex < 0)
			selectedIndex = 2;
	}
}

void Options::Update()
{
	UpdateSelectedButton();
	UpdateVolumeNumber();
}

void Options::Draw(sf::RenderWindow& window)
{
	window.draw(optionsBackgroundSprite);
	window.draw(optionTitle);
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		window.draw(optionButtons[i]);
	}
	window.draw(musicSwitchSprite);
	window.draw(volumeText);
	window.draw(maxVolumeText);

}

void Options::InitializeBackground()
{
	if (optionsBackgroundTexture != nullptr)
	{
		sf::Vector2u backgroundSize = optionsBackgroundTexture->getSize();
		float scaleX = (float)ScreenResolution::SCREEN_WIDTH_720P / backgroundSize.x;
		float scaleY = (float)ScreenResolution::SCREEN_HEIGHT_720P / backgroundSize.y;
		optionsBackgroundSprite.setTexture(*optionsBackgroundTexture);
		optionsBackgroundSprite.setScale(scaleX, scaleY);
	}
}

void Options::InitializeMusicSprites()
{
	if (musicSwitchTexture != nullptr)
	{
		musicSwitchSprite.setTexture(*musicSwitchTexture);
		musicSwitchSprite.setTextureRect(musicSwitchIntRect);
		///TEST VALUES, CREATE VARIABLE
		musicSwitchSprite.setScale(SCALE_MUSIC_SPRITE, SCALE_MUSIC_SPRITE);
		sf::FloatRect bounds = musicSwitchSprite.getLocalBounds();
		musicSwitchSprite.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
		float posX = 0, posY = 0;
		posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.62f);
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.32f);
		musicSwitchSprite.setPosition(posX, posY);
	}
}

void Options::InitializeTitle()
{
	optionTitle.setFont(*font);
	optionTitle.setString(OPTION_TITLE);
	optionTitle.setCharacterSize(70);
	optionTitle.setFillColor(sf::Color::White);
	optionTitle.setStyle(sf::Text::Bold);
	optionTitle.setOutlineThickness(3.0f);
	CenterTextOrigin(optionTitle);
	optionTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, 50);
}

void Options::InitializeButtons()
{
	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		optionButtons[i].setString(OPTION_BUTTON_LABELS[i]);
		ModifyTextProperties(optionButtons[i]);
		CenterTextOrigin(optionButtons[i]);
		float posX = 0, posY = 0;
		posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.40f);
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.30f) + (i * 150);
		optionButtons[i].setPosition(sf::Vector2f(posX, posY));

	}

	optionButtons[2].setPosition(sf::Vector2f(ScreenResolution::SCREEN_WIDTH_720P * 0.5f, 550));
}

void Options::InitializeVolumeText()
{
	volumeText.setString(volumeString);
	ModifyTextProperties(volumeText);
	CenterTextOrigin(volumeText);
	float posX = 0, posY = 0;
	posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.62f);
	posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.50f);
	volumeText.setPosition(posX, posY);

	std::string maxVolumeString = "/ " + volumeString;
	maxVolumeText.setString(maxVolumeString);
	ModifyTextProperties(maxVolumeText);
	CenterTextOrigin(maxVolumeText);
	posX = 0, posY = 0;
	posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.674f);
	posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.505f);
	maxVolumeText.setPosition(posX, posY);
}

void Options::UpdateSelectedButton()
{

	for (int i = 0; i < OPTIONS_AMOUNT; i++)
	{
		if (i == selectedIndex)
		{
			optionButtons[i].setFillColor(sf::Color::Yellow);
			optionButtons[i].setOutlineThickness(1.0f);
			optionButtons[i].setCharacterSize(45);
		}
		else
		{
			optionButtons[i].setCharacterSize(35);
			optionButtons[i].setFillColor(sf::Color::White);
			optionButtons[i].setOutlineThickness(0.5);
		}
	}

	if (isChangingVolume)
	{
		volumeText.setFillColor(sf::Color::Yellow);
		volumeText.setOutlineThickness(1.0f);
		volumeText.setCharacterSize(45);
		maxVolumeText.setFillColor(sf::Color::Yellow);
		maxVolumeText.setOutlineThickness(1.0f);
		maxVolumeText.setCharacterSize(45);
	}
	else
	{
		InitializeVolumeText();
	}


}

void Options::UpdateVolumeNumber()
{
	if (volumeString != std::to_string(volumeNumber))
	{
		volumeString = std::to_string(volumeNumber);
		volumeText.setString(volumeString);
		std::cout << "volume string: " << volumeString << "\n.";
	}
}

void Options::SelectButton()
{
	switch (selectedIndex)
	{
	case 0:
		AudioManager::getInstance().MuteAll(isMuted);
		isMuted = !isMuted;
		if (intRectPosX <= 0)
			intRectPosX += 100;
		else
			intRectPosX -= 100;

		musicSwitchIntRect = sf::IntRect(intRectPosX, 0, 100, 100);
		musicSwitchSprite.setTextureRect(musicSwitchIntRect);
		break;
	case 1:
		isChangingVolume = true;
		break;
	case 2:
		*gameState = GameState::MainMenu;
		break;
	default:
		break;
	}
}

void Options::IncreaseVolume()
{
	if (volumeNumber <= 50)
		volumeNumber++;

	if (volumeNumber > 50)
		volumeNumber = 50;
	AudioManager::getInstance().SetMusicVolume(volumeNumber);
}

void Options::DecreaseVolume()
{
	if (volumeNumber <= 0)
		volumeNumber = 0;

	if (volumeNumber > 0)
		volumeNumber--;
	AudioManager::getInstance().SetMusicVolume(volumeNumber);
}

void Options::CenterTextOrigin(sf::Text& textToCenter)
{
	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width * 0.5f, rc.height * 0.5f);
}

void Options::ModifyTextProperties(sf::Text& text)
{
	text.setFont(*font);
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::White);
	text.setOutlineThickness(0.5f);
	text.setOutlineColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);

}

