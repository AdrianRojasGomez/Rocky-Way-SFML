#pragma once
#include <iostream>
#include <string>
#include <vector>

struct HighScoresValues
{
	std::string name;
	int score;
	int maxWave;
};


class ScoreManager
{
public:
	static ScoreManager& getInstance();
	int GetScore();
	std::string GetName() { return name; }
	std::vector<HighScoresValues>& const GetHighScoresList();
	void SetWave(int waveCounter);
	void AddScoreLarge();
	void AddScoreSmall();
	void ResetScore();
	void CompareHighScore();
	std::vector<HighScoresValues> highScoresList;


private:
	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator= (const ScoreManager&) = delete;

	const std::string filePath = "res/data/Highscores.dat";
	const int LARGE_ASTEROID_VALUE = 100;
	const int SMALL_ASTEROID_VALUE = 30;
	std::string name = "Pilot 01";
	int score = 0;
	int maxWave = 0;

	void LoadRankingFromFile();
	void SortDescending();
	void LimitListToSixRankings();
};


