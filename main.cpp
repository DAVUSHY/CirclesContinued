/*
	Start shape drawing file
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Framework.h"
#include <cstdlib>
#include <vector>

// Variables with global scope - do not rename them, feel free to change values though

struct Circle {
	int x;
	int y;
	int xMove = 10;
	int yMove = 10;
	int Radius = 10;
	sf::Color colour;
};

int MouseX = 0;
int MouseY = 0;

// Screen dimensions
int gScreenWidth{ 800 };
int gScreenHeight{ 600 };

// Delay to slow things down
int gTimeDelayMS{ 10 };

using namespace std;

float randomfloat(float min, float max) {

	return ((float)rand() / RAND_MAX) * (max - min) + min;
}

sf::Color getRandomColor()
{
	return sf::Color(rand() % 256, rand() % 256, rand() % 256); // Random RGB color
}

int main()
{
	cout << "Hello circles" << endl;

	srand(time(NULL));

	vector<Circle> circles;

	for (int i = 0; i < 100; ++i) {
		Circle c;
		c.x = rand() % (gScreenWidth - c.Radius * 2); // Ensure circles stay within the screen bounds
		c.y = rand() % (gScreenHeight - c.Radius * 2);
		c.xMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving left (-1) or right (1)
		c.yMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving up (-1) or down (1)
		c.Radius = (rand() % 20 + 10);
		c.colour = getRandomColor(); // Assign a random color to each circle
		circles.push_back(c);
	}


	while (UpdateFramework())
	{
		for (Circle& c : circles) {
			c.x += c.xMove;
			c.y += c.yMove;

			if (c.x != c.x % (gScreenWidth - c.Radius * 2))
			{
				c.xMove = -c.xMove;
			}

			if (c.x < 0)
			{
				c.xMove = 10;
			}

			if (c.y != c.y % (gScreenHeight - c.Radius * 2))
			{
				c.yMove = -c.yMove;
			}

			if (c.y < 0)
			{
				c.yMove = 10;
			}

			DrawCircle(c.x, c.y, c.Radius, c.colour);
		}

		if (IsButtonPressed(EButton::eLeft))
		{
			GetMousePosition(MouseX, MouseY);

			float delay = randomfloat(0.1, 0.2);

			for (Circle& c : circles) 
			{
				c.x = c.x + (MouseX - c.x) * delay;
				c.y = c.y + (MouseY - c.y) * delay;

				c.x = c.x + (rand() % 20 + 10);
				c.y = c.y + (rand() % 20 + 10);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (IsButtonPressed(EButton::eRight)))
		{
			Circle c;
			c.x = rand() % (gScreenWidth - c.Radius * 2); // Ensure circles stay within the screen bounds
			c.y = rand() % (gScreenHeight - c.Radius * 2);
			c.xMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving left (-1) or right (1)
			c.yMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving up (-1) or down (1)
			c.Radius = (rand() % 20 + 10);
			c.colour = getRandomColor(); // Assign a random color to each circle
			circles.push_back(c);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (circles.size() >= 1))
		{
			circles.erase(circles.begin());
		}

		// Draws a circle at 100,200 with radius 20
		//DrawCircle(c_xPos,c_yPos,20);
	}

	cout << "Bye bye" << endl;

	return 0;
}
