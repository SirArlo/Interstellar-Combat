#ifndef  ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Playership.h"

class Asteroid 
{
public:

    Asteroid(unsigned int ScreenWidth, unsigned int ScreenHeight);
    void MoveAsteroid();
	void DrawAsteroid(sf::RenderWindow &window);
	float XGetPos();
	float YGetPos();
	void setPlayerLastCoord(int X ,int Y);
    void ResetPos();
	
private:

	sf::Sprite AsteroidObj;
	sf::Texture AsteroidTexture;
	float Coordinate_x;
	float Coordinate_y;
	unsigned int _ScreenWidth;
    unsigned int _ScreenHeight;
	int _DistToPlayer;
	int _CentreScreenX;
    int _CentreScreenY;
	int _LastXCoord;
	int _LastYCoord;

};

#endif
