#include "FramerateUtility.h"



Framerate::Framerate()
{
	fps = 0.0f;
	deltaTime = 0.0f;
	beforeTime = clock.getElapsedTime();
}

void Framerate::OnFrameEnd()
{
	currentTime = clock.getElapsedTime();
	deltaTime = currentTime.asSeconds() - beforeTime.asSeconds();
	fps = 1.0f / deltaTime;
	beforeTime = currentTime;
}

