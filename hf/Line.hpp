#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>


namespace LC
{
	class LineCreate
	{
		public:
			float x;
			float y;
			float width = 10;
			float height = 10;
			float screenDist;
			float rotation = 0.0;
			sf::Vector2f position = {x,y};
			sf::Color color = sf::Color::White;
			float get_screen_dist(sf::RenderWindow* screen)
			{
				return sqrt(pow(screen->getSize().x, 2) + pow(screen->getSize().y, 2));
			}
			void draw(sf::RenderWindow* screen)
			{
				
				sf::RectangleShape square(sf::Vector2f(width, height));
				square.setPosition(x, y);
				square.setOrigin(width/2.f, height/2.f);
				square.setFillColor(color);
				square.rotate(rotation);
				screen->draw(square);
				
				
			}
	};
}