#include <iostream>
#include "ScoreManager.h"


ScoreManager::ScoreManager()
{
	score = 0;
}

ScoreManager& ScoreManager::getInstance()
{
	static ScoreManager instance;
	return instance;
}

int ScoreManager::GetScore() 
{
	return score;
}

void ScoreManager::AddScoreLarge()
{
	this->score += LARGE_ASTEROID_VALUE;
	std::cout << "score: " << score << " points.\n";
}

void ScoreManager::AddScoreSmall()
{
	this->score += SMALL_ASTEROID_VALUE;
	std::cout << "score: " << score << " points.\n";
}

void ScoreManager::ResetScore()
{
	score = 0;
}







