#pragma once
#include <SFML/Graphics.hpp>

class Impact
{
public:
	Impact();
	~Impact();
	void Update();
	void Draw(sf::RenderWindow& window);



private:
	sf::Texture* impactTexture;
	sf::Sprite impactSprite;

	bool hasImpacted = false;
	float scaleImpactX = 0.3f;
	float scaleImpactY = 0.3f;
	int intRectPosX = 0;
	sf::IntRect textureRect;
	sf::Clock animationClock;

	void SetTextureValues();
	void UpdateFrameAnimation();
	void ImpactAnimation();
};