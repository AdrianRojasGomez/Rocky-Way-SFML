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
	int selected = RandomUtility::GetRandomInt(4, 0);
	return possiblePosX[selected];
}

int Collectable::GetARandomPosY()
{
	int selected = RandomUtility::GetRandomInt(4, 0);
	return possiblePosY[selected];
}

void Collectable::SetPosition(sf::Vector2f pos)
{
	//Set sprite position here
	collectableShape.setPosition(pos);
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

