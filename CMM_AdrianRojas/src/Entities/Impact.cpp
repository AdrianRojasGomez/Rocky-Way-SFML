#include <iostream>
#include "Impact.h"
#include "../SingletonManagers/ResourceManager.h"

Impact::Impact()
{
	impactTexture = ResourceManager::getInstance().GetImpactTexture();
	SetTextureValues();
}

Impact::~Impact()
{
}

void Impact::Update()
{
	UpdateFrameAnimation();
}

void Impact::Draw(sf::RenderWindow& window)
{
	window.draw(impactSprite);
}

void Impact::SetTextureValues()
{
	textureRect = sf::IntRect(-160, 0, 160, 172);
	if (impactTexture != nullptr)
	{

		impactSprite.setTexture(*impactTexture);
		impactSprite.setTextureRect(textureRect);
		impactSprite.setScale(scaleImpactX, scaleImpactY);
		sf::FloatRect bounds = impactSprite.getLocalBounds();
		impactSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
	}
	else
		std::cout << "DEBUG: Error!!!!!!!! LOADING IMPACT TEXTURE" << std::endl;
}

void Impact::UpdateFrameAnimation()
{
	if (!hasImpacted || animationClock.getElapsedTime().asMilliseconds() > 30)
		return;

	ImpactAnimation();
	animationClock.restart();
}

void Impact::ImpactAnimation()
{
	if (intRectPosX >= 860)
	{
		hasImpacted = false;
		intRectPosX = -172;
		return;
	}

	intRectPosX += 172;
	textureRect = textureRect = sf::IntRect(intRectPosX, 0, 172, 320);
	impactSprite.setTextureRect(textureRect);
}

