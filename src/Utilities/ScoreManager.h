#pragma once
#include <iostream>
#include <string>
#include <vector>

struct HighScores
{
	std::string name;
	int score;
	int maxWave;

	//Lo mismo que vimos con el ostream pero con el boolean ==
	//bool operator==(const HighScores& other) const {
	//    return name == other.name && score == other.score && maxWave == other.maxWave;
	//}
};

//Operator Overload << for debugging
std::ostream& operator<<(std::ostream& os, const HighScores& highscore);


class ScoreManager
{


public:
	static ScoreManager& getInstance();
	int GetScore();
	void SetWave(int waveCounter);
	void AddScoreLarge();
	void AddScoreSmall();
	void ResetScore();
	void CompareHighScore();


private:
	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;
	void LoadRankingFromFile();
	void SortDescending();
	void LimitListToSixRankings();

	ScoreManager& operator= (const ScoreManager&) = delete;
	const std::string filePath = "res/GameData/Highscores.dat";
	std::vector<HighScores> highScoresList;
	const int LARGE_ASTEROID_VALUE = 100;
	const int SMALL_ASTEROID_VALUE = 30;
	std::string name = "Test5";
	int score;
	int maxWave;

};


