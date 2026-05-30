#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <random>

namespace sq
{
    class Player{
        public:
            float x;
            float y;
            float raduis = 10;
            sf::Color color = sf::Color::Red;
			sf::Vector2f position;
            void draw(sf::RenderWindow* window)
            {
                sf::RenderWindow &screen = *window;
                sf::CircleShape circle1(raduis);
                circle1.setFillColor(color);
                circle1.setOrigin(raduis, raduis);
                circle1.setPosition(x,y);
                screen.draw(circle1);
				position = {x, y};
            }

    };
}