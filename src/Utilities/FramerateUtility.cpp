#include "FramerateUtility.h"

Framerate::Framerate()
{
	float fps = 0.0f;
	float deltaTime = 0.0f;
	beforeTime = clock.getElapsedTime();
}

void Framerate::OnFrameEnd()
{
	currentTime = clock.getElapsedTime();
	deltaTime = currentTime.asSeconds() - beforeTime.asSeconds();
	fps = 1.0f / deltaTime;
	beforeTime = currentTime;
}

