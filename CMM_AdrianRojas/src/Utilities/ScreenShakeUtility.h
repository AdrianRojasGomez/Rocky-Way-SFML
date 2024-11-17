#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class ScreenShake
{
public:
	ScreenShake(sf::View* viewCenter);
	~ScreenShake();
	void Update();
	void Draw(sf::RenderWindow& window);
	void StartShake(float shakeDuration, float shakeIntensity);
	bool GetIsShaking() { return isShaking; }


private:
	sf::View viewCenter;
	sf::View view;
	float shakeDuration = 0;
	float shakeIntensity = 0;
	bool isShaking = false;
	sf::Clock shakeClock;

	std::uniform_real_distribution<float> distribution;
	std::mt19937 generator;
	std::random_device rd;
};