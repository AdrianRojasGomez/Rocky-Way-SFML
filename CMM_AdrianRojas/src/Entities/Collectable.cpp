#include <iostream>
#include "Collectable.h"
#include "../SingletonManagers/ResourceManager.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/RandomUtility.h"
#include "../Utilities/ScreenResolution.h"

Collectable::Collectable(int collectableType)
{
	shotgunTexture = ResourceManager::getInstance().GetShotgunTexture();
	shieldTexture = ResourceManager::getInstance().GetShieldTexture();
	dobleScoreTexture = ResourceManager::getInstance().Get2XTexture();
	AssignCollectableTypeVisual(collectableType);
	animationClock.restart();
}

Collectable::~Collectable()
{

}

void Collectable::Update()
{
	UpdateAnimation();
	UpdateBounce();
}

void Collectable::Draw(sf::RenderWindow& window)
{
	window.draw(collectableSprite);
}

void Collectable::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int Collectable::GetARandomPosX()
{
	int selected = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_WIDTH_720P / 1.5, 100);
	return selected;
}

int Collectable::GetARandomPosY()
{
	int selected = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_HEIGHT_720P / 1.5, 100);
	return selected;
}

void Collectable::SetPosition(sf::Vector2f pos)
{
	collectableSprite.setPosition(pos);
	collectableHitZone = collectableSprite.getGlobalBounds();
	initPos = pos;
}

void Collectable::UpdateAnimation()
{
	if (animationClock.getElapsedTime().asSeconds() > 0.1f)
	{
		intRectX = (intRectX == 0) ? fileSize : 0;

		collectableSprite.setTextureRect(sf::IntRect(intRectX, 0, fileSize, fileSize));
		animationClock.restart();
	}
}

void Collectable::UpdateBounce()
{
	int speed = 50;
	static int direction = 1;
	float upperLimit = initPos.y;
	float lowerLimit = initPos.y + 15;

	if (collectableSprite.getPosition().y >= lowerLimit)
		direction = -1;
	else if (collectableSprite.getPosition().y <= upperLimit)
		direction = 1;

	collectableSprite.move(sf::Vector2f(0, direction * speed * Framerate::getDeltaTime()));
}

void Collectable::AssignSprite(sf::Texture* assignedTexture, float sizeX, float sizeY, float scale)
{
	collectableSprite.setTexture(*assignedTexture);
	collectableSprite.setTextureRect(sf::IntRect(intRectX, 0, sizeX, sizeY));
	collectableSprite.setScale(scale, scale);
}

void Collectable::AssignCollectableTypeVisual(int collectableType)
{
	float size = 0.5f;
	type = (CollectableType)collectableType;
	switch (type)
	{

	case CollectableType::Shotgun:
		AssignSprite(shotgunTexture, fileSize, fileSize, size);
		break;

	case CollectableType::Shield:
		AssignSprite(shieldTexture, fileSize, fileSize, size);
		break;

	case CollectableType::DoubleScore:
		AssignSprite(dobleScoreTexture, fileSize, fileSize, size);
		break;

	case CollectableType::Unassigned:
		std::cout << "Error, UNASSIGNED value selected on CollectableType\n";
		break;

	default:
		std::cout << "Error, DEFAULT value selected on CollectableType\n";
		break;
	}

}


