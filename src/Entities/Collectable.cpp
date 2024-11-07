#include <iostream>
#include "Collectable.h"
#include "../Utilities/RandomUtility.h"

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

void Collectable::Draw()
{
}

void Collectable::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

int Collectable::GetAPosX()
{
	int selected = RandomUtility::GetRandomInt(4, 0);
	return possiblePosX[selected];
}

int Collectable::GetAPosY()
{
	int selected = RandomUtility::GetRandomInt(4, 0);
	return possiblePosY[selected];
}

void Collectable::SetPosition(sf::Vector2f pos)
{
	//Set sprite position here
	collectable.setPosition(pos);
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
		collectable.setRadius(10);
		collectable.setPointCount(4);
		collectable.setFillColor(sf::Color::Red);
		break;
	case CollectableType::Shield:
		//load shotgun resource pointer
		//set sprite
		collectable.setRadius(10);
		collectable.setPointCount(10);
		collectable.setFillColor(sf::Color::Blue);
		break;
	case CollectableType::DoubleScore:
		//load shotgun resource pointer
		//set sprite
		collectable.setRadius(10);
		collectable.setPointCount(3);
		collectable.setFillColor(sf::Color::Green);
		break;
	default:
		std::cout << "Error, DEFAULT value selected on CollectableType\n";
		break;
	}

}

