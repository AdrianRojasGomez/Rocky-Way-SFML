#include <iostream>
#include <list>
#include "UI.h"
#include "../Utilities/ScreenResolution.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/ScoreManager.h"


UI::UI()
{
	uiFont = ResourceManager::GetOxaniumSemiBoldFont();
}

UI::~UI()
{
	for (int i = 0; i < hpUI.size(); i++)
	{
		if (hpUI[i] != nullptr)
		{
			delete hpUI[i];
			hpUI[i] = nullptr;
		}
	}
	hpUI.clear();
}

void UI::InitializeHealthAndWaveUI()
{
	this->maxHP = HP;
	this->HP = maxHP;
	for (int i = 0; i < maxHP; i++)
	{
		sf::CircleShape* currentHP = new sf::CircleShape();
		currentHP->setRadius(10);
		currentHP->setOutlineThickness(2);
		currentHP->setOutlineColor(sf::Color::White);
		currentHP->setFillColor(sf::Color::Black);
		currentHP->setPosition(35 + i * 30, 80);
		hpUI.push_back(currentHP);
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


void UI::InitializeUI(int HP)
{
	this->maxHP = HP;
	this->HP = maxHP;
	InitializeHealthAndWaveUI();
	InitializeScoreUI();

}

void UI::UpdateUIHealth()
{

	if (!isInitialized)
	{
		std::cout << " Initialized\n";
		isInitialized = true;
		InitializeUI(HP);
		return;
	}

	for (int i = 0; i < hpUI.size(); i++)
	{
		if (i < HP)
			hpUI[i]->setFillColor(sf::Color::Red);
		else
			hpUI[i]->setFillColor(sf::Color::Black);
	}
}



void UI::SetUIHP(int HP)
{
	this->HP = HP;
}

void UI::SetUIWave(int wave)
{
	this->waveNumberString = std::to_string(wave);
	waveNumber.setString(waveNumberString);
}

void UI::UpdateUIScore()
{
	scoreString = std::to_string(newScore);
	while (scoreString.length() < 6)
	{
		scoreString = '0' + scoreString;
	}
	scoreShown.setString(scoreString);
	scoreClock.restart();
}

void UI::UpdateScore()
{
	newScore = ScoreManager::getInstance().GetScore();
	scoreClock.restart();
}




void UI::Update()
{
	UpdateScore();
	UpdateUIHealth();
	UpdateUIScore();
}



void UI::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < hpUI.size(); i++)
	{
		window.draw(*hpUI[i]);
	}
	window.draw(waveTitle);
	window.draw(waveNumber);
	window.draw(scoreTitle);
	window.draw(scoreShown);
}

