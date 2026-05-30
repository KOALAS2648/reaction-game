#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "S.hpp"
#include "Line.hpp"
using namespace sq;
using namespace std;
using namespace LC;

namespace Collision
{
	bool isOutside(Player* obj, sf::RenderWindow* s)
	{
		sf::RenderWindow &screen = *s;
		Player &check = *obj;
		float windowWidth = screen.getSize().x;
		float windowHeight = screen.getSize().y;
		if(check.x + check.raduis > windowWidth)
		{
			check.x = windowWidth-check.raduis;
			return true;
			
		}
		if(check.x - check.raduis < 0)
		{
			check.x = check.raduis;
			return true;
			
		}
		if(check.y + check.raduis > windowHeight)
		{
			check.y = windowHeight-check.raduis;
			return true;
		}
		if(check.y-check.raduis < 0)
		{
			check.y = check.raduis;
			return true;
		}
		return false;
	}
	
	bool isTouching(Player* obj, LineCreate* obj2)
	{
			float angle = -obj2->rotation * 3.14159265f / 180.f;
			float cosA = cos(angle);
			float sinA = sin(angle);
			float dx = obj->x - obj2->x;
			float dy = obj->y - obj2->y;
			float localX = dx * cosA - dy * sinA;
			float localY = dx * sinA + dy * cosA;
			float halfWidth = obj2->width / 2.f;
			float halfHeight = obj2->height / 2.f;
			float closestX = clamp(localX, -halfWidth, halfWidth);
			float closestY = clamp(localY, -halfHeight, halfHeight);
			float distanceX = localX - closestX;
			float distanceY = localY - closestY;
			return distanceX * distanceX + distanceY * distanceY <= obj->raduis * obj->raduis;
	}
}