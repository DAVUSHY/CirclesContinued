#include <SFML/Graphics.hpp>
#include <iostream>
#include "Framework.h"
#include "Circles.h"
#include <cstdlib>
#include <vector>

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

Circles circles(gScreenWidth, gScreenHeight);

using namespace std;

int main()
{
	cout << "Hello circles" << endl;

	vector<Circles> circle;

	for (int i = 0; i < 100; ++i) {
		circle.emplace_back(gScreenWidth, gScreenHeight);
	}


	while(UpdateFramework())
	{
		for (Circles& c : circle) {
			
			c.Movement(gScreenWidth, gScreenHeight);

			DrawCircle(c.GetXPos(), c.GetYPos(), c.GetRadius(), c.GetColour());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (IsButtonPressed(EButton::eRight)))
		{
			circle.emplace_back(gScreenWidth, gScreenHeight);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (circle.size() >= 1))
		{
			circle.erase(circle.begin());
		}

		// Draws a circle at 100,200 with radius 20
		//DrawCircle(c_xPos,c_yPos,20);
	}

	cout << "Bye bye" << endl;

	return 0;
}
