#pragma once
#include <SFML/System/Vector2.hpp>
class ScreenResolution
{
public:
	static constexpr int SCREEN_WIDTH_720P = 1280;
	static constexpr int SCREEN_HEIGHT_720P = 720;	
	static constexpr int SCREEN_WIDTH_1080P = 1920;
	static constexpr int SCREEN_HEIGHT_1080P = 1080;

	static sf::Vector2f GetScreenCenter720()
	{
		return sf::Vector2f(SCREEN_WIDTH_720P / 2.0f, SCREEN_HEIGHT_720P / 2.0f);
	}

	static sf::Vector2f GetScreenCenter1080()
	{
		return sf::Vector2f(SCREEN_WIDTH_1080P / 2.0f, SCREEN_HEIGHT_1080P / 2.0f);
	}
};