#include <iostream>
#include <list>
#include "UI.h"
#include "../Utilities/ScreenResolution.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../SingletonManagers/ScoreManager.h"


UI::UI()
{
	uiFont = ResourceManager::getInstance().GetOxaniumSemiBoldFont();
	lifeUITexture = ResourceManager::getInstance().GetLifeUITexture();
	lifeLostUITexture = ResourceManager::getInstance().GetLifeLostUITexture();
	InitializeUI();
	animationClock.restart();
}

UI::~UI()
{
}

void UI::Update()
{
	UpdateScore();
	UpdateUIScore();
	UpdateUIAnimation();
}

void UI::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < lifeUISprites.size(); i++)
	{
		window.draw(lifeUISprites[i]);
	}
	window.draw(waveTitle);
	window.draw(waveNumber);
	window.draw(scoreTitle);
	window.draw(scoreShown);
}

void UI::SetUIHP(int playerHP)
{
	HP = playerHP;
	UpdateHP();
}

void UI::SetUIWave(int wave)
{
	this->waveNumberString = std::to_string(wave);
	waveNumber.setString(waveNumberString);
}

void UI::ChangeColorToDoble()
{
	sf::Color color(121, 49, 255, 255);
	scoreShown.setFillColor(color);
	scoreShown.setCharacterSize(30);
	scoreShown.setOutlineThickness(2.0);
	scoreShown.setOutlineColor(sf::Color::Black);
}

void UI::Defaultcolor()
{
	scoreShown.setFillColor(sf::Color::White);
	scoreShown.setCharacterSize(26);
	scoreShown.setOutlineThickness(0);

}

void UI::InitializeHealthAndWaveUI()
{

	for (int i = 0; i < maxHP; i++)
	{
		sf::Sprite currentHP;
		currentHP.setTexture(*lifeLostUITexture);
		lifeLostIntRect = sf::IntRect(0, 0, 129, 132);
		currentHP.setTextureRect(lifeLostIntRect);
		currentHP.setScale(SCALE, SCALE);
		currentHP.setPosition(27 + (i * 33), 80);
		lifeUISprites.push_back(currentHP);
	}

	waveTitle.setFont(*uiFont);
	waveTitle.setString(WAVE_TITLE_STRING);
	waveTitle.setCharacterSize(28);
	waveTitle.setPosition(30, 30);
	waveTitle.setLetterSpacing(1.0f);

	waveNumber.setFont(*uiFont);
	waveNumber.setString(waveNumberString);
	waveNumber.setCharacterSize(28);
	waveNumber.setPosition(120, 30);
}

void UI::InitializeScoreUI()
{
	scoreTitle.setFont(*uiFont);
	scoreTitle.setString(SCORE_TITLE_STRING);
	scoreTitle.setCharacterSize(26);
	scoreTitle.setPosition(ScreenResolution::SCREEN_WIDTH_720P - 143, 20);
	scoreTitle.setLetterSpacing(1.0f);

	scoreShown.setFont(*uiFont);
	scoreShown.setString(scoreString);
	scoreShown.setCharacterSize(26);
	scoreShown.setStyle(sf::Text::Italic);
	scoreShown.setPosition(ScreenResolution::SCREEN_WIDTH_720P - 150, 50);
	score = newScore;
}

void UI::InitializeUI()
{
	HP = maxHP;
	InitializeHealthAndWaveUI();
	InitializeScoreUI();
}

void UI::UpdateUIScore()
{
	if (!(UIAnimationClock.getElapsedTime().asMilliseconds() > 5))
		return;

	if (score < newScore)
		score++;

	scoreString = std::to_string(score);
	while (scoreString.length() < 6)
	{
		scoreString = '0' + scoreString;
	}
	scoreShown.setString(scoreString);

	UIAnimationClock.restart();
}

void UI::UpdateScore()
{
	newScore = ScoreManager::getInstance().GetScore();
}

void UI::UpdateHP()
{
	for (int i = 0; i < lifeUISprites.size(); i++)
	{
		if (i < HP)
			lifeUISprites[i].setTexture(*lifeUITexture);
		else
			lifeUISprites[i].setTexture(*lifeLostUITexture);
	}
}

void UI::UpdateUIAnimation()
{
	if (!(animationClock.getElapsedTime().asMilliseconds() > 80))
		return;

	animationClock.restart();

	for (int i = 0; i < lifeUISprites.size(); i++)
	{
		if (lifeUISprites[i].getTexture() == lifeUITexture)
		{
			const int limitPixel = 512; 
			int intRectX = lifeUISprites[i].getTextureRect().left;

			if (intRectX >= limitPixel)
				intRectX = 0; 
			else
				intRectX += 128; 
			sf::IntRect lifeIntRect(intRectX, 0, 128, 128);
			lifeUISprites[i].setTextureRect(lifeIntRect);
		}
	}

	for (int i = 0; i < lifeUISprites.size(); i++)
	{
		const int limitPixel = 512;
		int intRectX = lifeUISprites[i].getTextureRect().left;
		if (lifeUISprites[i].getTexture() == lifeLostUITexture)
		{
			if (intRectX >= limitPixel)
				continue;

			intRectX += 128;
			lifeLostIntRect = sf::IntRect(intRectX, 0, 128, 128);
			lifeUISprites[i].setTextureRect(lifeLostIntRect);
		}
	}


}






