#pragma once
#include <SFML/System.hpp>

class Framerate
{
public:

	static float getCurrentFPS() { return fps; }
	static float getDeltaTime() { return deltaTime; }
	static void OnFrameEnd();

private:
	static sf::Clock clock;
	static sf::Time beforeTime;
	static sf::Time currentTime;
	static float fps;
	static float deltaTime;

	Framerate();

};
