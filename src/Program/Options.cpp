#include <iostream>
#include "Options.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"
#include "../Audio/AudioManager.h"

Options::Options(GameState* gameState)
{
	this->gameState = gameState;
	font = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	optionsBackgroundTexture = ResourceManager::getInstance().GetMenuBackgroundTexture();
	musicOffTexture = ResourceManager::getInstance().GetMusicOffTexture();
	musicOnTexture = ResourceManager::getInstance().GetMusicOnTexture();
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
			if (event.key.code == sf::Keyboard::Right)
				IncreaseVolume();
			if (event.key.code == sf::Keyboard::Left)
				DecreaseVolume();
			if (event.key.code == sf::Keyboard::Enter)
			{
				isChangingVolume = false;
				selectedIndex = 2;
			}
			return;
		}


		if (event.key.code == sf::Keyboard::Enter)
			SelectButton();

		if (event.key.code == sf::Keyboard::Down)
		{
			selectedIndex++;
			if (selectedIndex > 2)
				selectedIndex = 0;



		}
		if (event.key.code == sf::Keyboard::Up)
			selectedIndex--;
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
	isMuted ? window.draw(musicOffSprite) : window.draw(musicOnSprite);
	window.draw(volumeText);

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
	if (musicOffTexture != nullptr && musicOnTexture != nullptr)
	{
		musicOffSprite.setTexture(*musicOffTexture);
		musicOnSprite.setTexture(*musicOnTexture);
		///TEST VALUES, CREATE VARIABLE
		musicOffSprite.setScale(SCALE_MUSIC_SPRITE, SCALE_MUSIC_SPRITE);
		musicOnSprite.setScale(SCALE_MUSIC_SPRITE, SCALE_MUSIC_SPRITE);
		sf::FloatRect bounds = musicOffSprite.getLocalBounds();
		musicOffSprite.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
		bounds = musicOnSprite.getLocalBounds();
		musicOnSprite.setOrigin(bounds.width * 0.5f, bounds.height * 0.5f);
		float posX = 0, posY = 0;
		posX = (ScreenResolution::SCREEN_WIDTH_720P * 0.62f);
		posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.32f);
		musicOnSprite.setPosition(posX, posY);
		musicOffSprite.setPosition(posX, posY);
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
	posY = (ScreenResolution::SCREEN_HEIGHT_720P * 0.51f);
	volumeText.setPosition(posX, posY);
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
	if (volumeNumber <= 100)
		volumeNumber++;

	if (volumeNumber > 100)
		volumeNumber = 100;
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

