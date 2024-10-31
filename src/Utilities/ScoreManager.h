#pragma once
class ScoreManager
{
public:
	static ScoreManager& getInstance();
    int GetScore();
    void AddScoreLarge();
    void AddScoreSmall();
    void ResetScore();


private:
    ScoreManager();
    ScoreManager(const ScoreManager&) = delete;
    ScoreManager& operator= (const ScoreManager&) = delete;

    const int LARGE_ASTEROID_VALUE = 100;
    const int SMALL_ASTEROID_VALUE = 50;
    int score;
};
