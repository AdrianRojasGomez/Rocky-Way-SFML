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

//Operator Overload << for debugging
//std::ostream& operator<<(std::ostream& os, const HighScoresValues& highscore);


class ScoreManager
{


public:
	static ScoreManager& getInstance();
	int GetScore();
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
	void LoadRankingFromFile();
	void SortDescending();
	void LimitListToSixRankings();

	ScoreManager& operator= (const ScoreManager&) = delete;
	const std::string filePath = "res/GameData/Highscores.dat";
	const int LARGE_ASTEROID_VALUE = 100;
	const int SMALL_ASTEROID_VALUE = 30;
	std::string name = "Player 01";
	int score;
	int maxWave;

};


