#pragma once
#include <SFML/System.hpp>
class Framerate
{
public:

	Framerate();
	void OnFrameEnd();
	float getCurrentFPS() { return fps; }
	float getDeltaTime() { return deltaTime; }

private:
	sf::Clock clock;
	sf::Time beforeTime;
	sf::Time currentTime;
	float fps;
	float deltaTime;

	/// Can this be a singleton or a static class?
	/// how the fuck do I do a good static class on c++???
};