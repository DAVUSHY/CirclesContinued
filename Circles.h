#pragma once

class Circles
{
private:
	int x{ 0 };
	int y{ 0 };
	int xMove = 10;
	int yMove = 10;
	int Radius{ 20 };
	sf::Color colour;

public:
	sf::Color getRandomColor();

	Circles(int gScreenWidth, int gScreenHeight);

	void Movement(int gScreenWidth, int gScreenHeight);

	int GetXPos();

	int GetYPos();

	int GetRadius();

	sf::Color GetColour();
};