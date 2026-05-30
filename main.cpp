// g++ main.cpp -o app -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./app.exe
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <random>
#include <string>
#include <iomanip>
#include "hf/S.hpp"
#include "hf/collisions.hpp"
#include "hf/Line.hpp"
using namespace Collision;
using namespace sq;
using namespace LC;
using namespace std;

int randint(int min, int max) {
    static random_device rd;
    static mt19937 rng(rd());

    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
float get_avg(vector<float> vec)
{
	float total = 0.0f;
	for(float t: vec)
	{
		total +=t;
	}
	return total / vec.size();
}
int main()
{
	bool show_avg = false;
	sf::Font font;
	if (!font.loadFromFile("fonts/RS.ttf"))
	{
		return 1;
	}
	sf::Font font1;
	if (!font1.loadFromFile("fonts/RS.ttf"))
	{
		return 1;
	}
	sf::Text text;
	text.setFont(font);
	
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setOrigin(25, 25);
	text.setPosition(450, 30);

	sf::Text text1;
	text1.setFont(font1);
	text1.setCharacterSize(100);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setOrigin(25, 25);
	text1.setPosition(50, 30);

	sf::Text text2;
	text2.setFont(font1);
	text2.setCharacterSize(100);
	text2.setFillColor(sf::Color::Green);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setOrigin(25, 25);
	text2.setPosition(625, 30);
	
	sf::Clock clock;
    int frames = 0;
    float elapsed = 0.0f;
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");
	window.setFramerateLimit(60);
    sf::RenderWindow* windowPointer = &window;

    Player h;
    h.x = window.getSize().x/2;
    h.y = window.getSize().y/2;
	h.color = sf::Color::Blue;
	int speed = 10;
	Player* playerPointer = &h;
	bool c;
	bool d;
	float average;
	LineCreate l1;
	l1.x = 200;
	l1.y = 300;
	l1.color = sf::Color::Green;
	l1.width = 50;
	LineCreate* linePointer = &l1;
	std::ostringstream stream;
	
	vector<float> times = {};
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
    		{
        		if (event.key.code == sf::Keyboard::Up)
        		{
            		speed++;
        		}
				if (event.key.code == sf::Keyboard::Down)
				{
					speed--;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					show_avg = !show_avg;
				}
    		}
		}
		c = isOutside(playerPointer, windowPointer);
		d = isTouching(playerPointer, linePointer);
		elapsed = clock.getElapsedTime().asSeconds();
		//cout << elapsed << endl;
		if (d)
		{
			times.push_back(elapsed);
			clock.restart();
			l1.x = randint(0, windowPointer->getSize().x);
			l1.y = randint(0,windowPointer->getSize().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !c)
		{
			h.y -= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !c)
		{
			h.y+= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !c)
		{
			h.x-= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !c)
		{
			h.x+= speed;
		}
        window.clear();
		stream.str("");
		if(show_avg)
		{
			stream.str("");
			average = get_avg(times);
			stream << std::fixed << std::setprecision(3) << average;
			string a = stream.str();
			text2.setString(a);
			window.draw(text2);
			
		}
		stream.str("");
		text1.setString("speed: "+to_string(speed));
		stream << std::fixed << std::setprecision(1) << elapsed;
		string pres = stream.str();
		text.setString(pres);
		window.draw(text);
		window.draw(text1);
		
		stream.clear();
		l1.draw(windowPointer);
        h.draw(windowPointer);
		
        window.display();
        
    }
       
	cout << "your average time was : " << get_avg(times) << endl;
    return 0;
}