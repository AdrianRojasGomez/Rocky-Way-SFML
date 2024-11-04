#include "Pause.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScreenResolution.h"

Pause::Pause(GameState* gameState)
{
	this->gameState = gameState;
	menuFont = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	InitializeTitle();


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
	}
}

void Pause::Update()
{
}

void Pause::Draw(sf::RenderWindow& window)
{
	window.draw(pauseTitleText);
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

void Pause::CenterTextOrigin(sf::Text& textToCenter)
{

	sf::FloatRect rc = textToCenter.getLocalBounds();
	textToCenter.setOrigin(rc.width / 2, rc.height / 2);

}
