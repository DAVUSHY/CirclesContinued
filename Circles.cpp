#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circles.h"
#include "Framework.h"
#include <vector>

sf::Color Circles::getRandomColor()
{
	return sf::Color(rand() % 256, rand() % 256, rand() % 256); // Random RGB color
}

Circles::Circles(int gScreenWidth, int gScreenHeight)
{
	x = rand() % (gScreenWidth - Radius * 2); // Ensure circles stay within the screen bounds
	y = rand() % (gScreenHeight - Radius * 2);
	xMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving left (-1) or right (1)
	yMove = (rand() % 2 == 0) ? 1 : -1; // Randomly choose between moving up (-1) or down (1)
	colour = getRandomColor(); // Assign a random color to each circle
}

void Circles::Movement(int gScreenWidth, int gScreenHeight)
{
	x += xMove;
	y += yMove;

	if (x != x % (gScreenWidth - Radius * 2))
	{
		xMove = -xMove;
	}

	if (x < 0)
	{
		xMove = 10;
	}

	if (y != y % (gScreenHeight - Radius * 2))
	{
		yMove = -yMove;
	}

	if (y < 0)
	{
		yMove = 10;
	}

}

int Circles::GetXPos()
{
	return x;
}

int Circles::GetYPos()
{
	return y;
}

int Circles::GetRadius()
{
	return Radius;
}

sf::Color Circles::GetColour()
{
	return colour;
}
