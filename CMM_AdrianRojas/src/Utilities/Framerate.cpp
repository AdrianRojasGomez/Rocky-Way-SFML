#include <iostream>
#include "Framerate.h"

sf::Clock Framerate::clock;
sf::Time Framerate::beforeTime;
sf::Time Framerate::currentTime;
float Framerate::fps = 0.0f;
float Framerate::deltaTime = 0.0f;

void Framerate::OnFrameEnd()
{
	currentTime = clock.getElapsedTime();
	deltaTime = currentTime.asSeconds() - beforeTime.asSeconds();
	fps = 1.0f / deltaTime;
	beforeTime = currentTime;
}
