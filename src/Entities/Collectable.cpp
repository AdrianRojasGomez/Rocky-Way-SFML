#include <iostream>
#include "Collectable.h"
#include "../Utilities/RandomUtility.h"
#include "../Utilities/ScreenResolution.h"

Collectable::Collectable(int collectableType)
{
	AssignCollectableTypeVisual(collectableType);
}

Collectable::~Collectable()
{

}

void Collectable::Update()
{
}

void Collectable::Draw(sf::RenderWindow& window)
{
	window.draw(collectableShape);
}

void Collectable::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int Collectable::GetARandomPosX()
{
	int selected = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_WIDTH_720P - 50, 50);
	return selected;
}

int Collectable::GetARandomPosY()
{
	int selected = RandomUtility::GetRandomInt(ScreenResolution::SCREEN_HEIGHT_720P - 50, 50);
	return selected;
}

void Collectable::SetPosition(sf::Vector2f pos)
{
	//Set sprite position here
	collectableShape.setPosition(pos);
	collectableHitZone = collectableShape.getGlobalBounds();
}

void Collectable::AssignCollectableTypeVisual(int collectableType)
{
	type = (CollectableType)collectableType;
	switch (type)
	{
	case CollectableType::Unassigned:
		std::cout << "Error, UNASSIGNED value selected on CollectableType\n";
		break;
	case CollectableType::Shotgun:
		//load shotgun resource pointer
		//set sprite
		collectableShape.setRadius(20);
		collectableShape.setPointCount(4);
		collectableShape.setFillColor(sf::Color::Red);
		break;
	case CollectableType::Shield:
		//load shotgun resource pointer
		//set sprite
		collectableShape.setRadius(20);
		collectableShape.setPointCount(10);
		collectableShape.setFillColor(sf::Color::Blue);
		break;
	case CollectableType::DoubleScore:
		//load shotgun resource pointer
		//set sprite
		collectableShape.setRadius(20);
		collectableShape.setPointCount(3);
		collectableShape.setFillColor(sf::Color::Green);
		break;
	default:
		std::cout << "Error, DEFAULT value selected on CollectableType\n";
		break;
	}

}

