#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <SFML/Graphics.hpp>
#include "Playership.h"

class PlayerBullet
{
public:

PlayerBullet( Playership & Player, unsigned int ScreenWidth, unsigned int ScreenHeight);
void  Playershoot();
void DrawPlayerBullet(sf::RenderWindow & window);

private:

	float _lastX ;
	float _lastY ;
	sf::CircleShape Bullet;
    float _DistToCentre;
	unsigned int _ScreenHeight;
     unsigned int _ScreenWidth;
	float Coordinate_x;
	float Coordinate_y;
	float  _CentreScreenX;
    float  _CentreScreenY;

};

#endif
