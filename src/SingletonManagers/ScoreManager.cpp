#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ScoreManager.h"

ScoreManager& ScoreManager::getInstance()
{
	static ScoreManager instance;
	return instance;
}

ScoreManager::ScoreManager()
{
	LoadRankingFromFile();
	SortDescending();
	LimitListToSixRankings();
}

void ScoreManager::LoadRankingFromFile()
{
	std::ifstream HighscoresFileRead(filePath);
	std::string line;

	if (!HighscoresFileRead.is_open())
		std::cout << "Error en apertura de file de Highscores!!!\n";

	while (std::getline(HighscoresFileRead, line))
	{
		std::stringstream ss(line);
		std::string rankedName;
		int rankedScore, rankedMaxWave;

		if (std::getline(ss, rankedName, ',') && (ss >> rankedScore) && ss.ignore() && (ss >> rankedMaxWave))
			highScoresList.push_back({ rankedName, rankedScore, rankedMaxWave });
	}

	HighscoresFileRead.close();
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
}

void ScoreManager::LimitListToSixRankings()
{
	if (highScoresList.size() > 6)
		highScoresList.resize(6);
}


int ScoreManager::GetScore()
{
	return score;
}

std::vector<HighScoresValues>& ScoreManager::GetHighScoresList()
{
	return highScoresList;
}

void ScoreManager::SetWave(int waveCounter)
{
	maxWave = waveCounter;
}

void ScoreManager::AddScoreLarge()
{
	score += LARGE_ASTEROID_VALUE * multiplier;
}

void ScoreManager::AddScoreSmall()
{
	score += SMALL_ASTEROID_VALUE * multiplier;
}

void ScoreManager::ResetScore()
{
	score = 0;
}

void ScoreManager::CompareHighScore()
{
	bool itClasifies = false;
	for (int i = 0; i < highScoresList.size(); i++)
	{
	if (score > highScoresList[i].score)
		{
			itClasifies = true;
			highScoresList.push_back(HighScoresValues {name, score, maxWave});
			break;
		}
	}
	if (!itClasifies)
		return;

	SortDescending();
	LimitListToSixRankings();

	std::ofstream HighScoreFileWrite(filePath);

	if (!HighScoreFileWrite.is_open())
		std::cout << "Error en apertura de file de Highscores!!!\n";

	for (int i = 0; i < highScoresList.size(); i++)
	{
		HighScoreFileWrite << highScoresList[i].name << ","
			<< highScoresList[i].score << ","
			<< highScoresList[i].maxWave << "\n";
	}

	HighScoreFileWrite.close();
}

void ScoreManager::EnableDobleScore()
{
	multiplier = 2;
}

void ScoreManager::DisableMutiplier()
{
	multiplier = 1;

}
