#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Playership
{
	
public:

    Playership(int ScreenHeight, int ScreenWidth);
	void moveClockwise();
	void moveAntiClockwise();
    void DrawPlayer(sf::RenderWindow &window);
	float GetLastPositionX();
	float GetLastPositionY();
	void Playershoot();

private:

    int _DistToCentre;
   friend class CollisionHandler;
	int _ScreenHeight;
     int _ScreenWidth;
    float StartAngle;
    sf::CircleShape PlayerCraft;
	const int PlayerRadius = 280;
	int Coordinate_x;
	int Coordinate_y;
	int _CentreScreenX;
    int _CentreScreenY;
	
};

#endif
