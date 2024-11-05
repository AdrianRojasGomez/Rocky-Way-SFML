#include "ScreenShakeUtility.h"
#include "RandomUtility.h"

ScreenShake::ScreenShake(sf::View* viewCenter)
{
	this->viewCenter = *viewCenter;
	this->view = *viewCenter;
	generator = std::mt19937(rd());
	distribution = std::uniform_real_distribution<float>(-1.0f, 1.0f);

}

ScreenShake::~ScreenShake()
{
}

void ScreenShake::Update()
{
	if (!isShaking)
		return;

	if (shakeClock.getElapsedTime().asSeconds() > shakeDuration)
	{
		isShaking = false;
		view = viewCenter;
		return;
	}

	float offsetX = distribution(generator) * shakeIntensity;
	float offsetY = distribution(generator) * shakeIntensity;

	view.move(viewCenter.getCenter().x + offsetX, viewCenter.getCenter().y + offsetY);
}

void ScreenShake::Draw(sf::RenderWindow& window)
{
	if (isShaking)
		window.setView(view);
	else
		window.setView(viewCenter);
}

void ScreenShake::StartShake(float shakeDuration, float shakeIntensity)
{
	this->shakeDuration = shakeDuration;
	this->shakeIntensity = shakeIntensity;
	isShaking = true;
	shakeClock.restart();
	view = viewCenter;

}
