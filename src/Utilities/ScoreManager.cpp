#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ScoreManager.h"


ScoreManager::ScoreManager()
{
	score = 0;
	LoadRankingFromFile();
	SortDescending();
	LimitListToSixRankings();



}

void ScoreManager::LoadRankingFromFile()
{
	std::ifstream HighscoresFile(filePath);
	std::string line;

	if (HighscoresFile.is_open())
	{
		while (std::getline(HighscoresFile, line))
		{
			std::stringstream ss(line);
			std::string rankedName;
			int rankedScore, rankedMaxWave;

			if (std::getline(ss, rankedName, ',') && (ss >> rankedScore) && ss.ignore() && (ss >> rankedMaxWave))
				highScoresList.push_back({ rankedName, rankedScore, rankedMaxWave });
		}
	}
	else
	{
		std::cout << "Error en apertura de file de Highscores!!!\n";
	}

	HighscoresFile.close();
}

void ScoreManager::SortDescending()
{
	int n = highScoresList.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (highScoresList[j].score < highScoresList[j + 1].score) {
				std::swap(highScoresList[j], highScoresList[j + 1]);
			}
		}
	}

	//DEBUG PURPOSES
	for (int i = 0; i < highScoresList.size(); i++)
	{
		std::cout << i + 1 << "\n";
		std::cout << highScoresList[i];
		std::cout << "\n\n\n";

	}
}

void ScoreManager::LimitListToSixRankings()
{
	if (highScoresList.size() > 6)
		highScoresList.resize(6);
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

//DEBUG PURPOSES
std::ostream& operator<<(std::ostream& os, const HighScores& highscore)
{
	{
		os << highscore.name << "\n"
			<< highscore.score << "\n"
			<< highscore.maxWave;

		return os;
	}
}
