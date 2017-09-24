#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <SFML/Graphics.hpp>
#include "Playership.h"
#include "Enemy.h"

class EnemyBullet
{
public:

EnemyBullet( Enemy & Alien, Playership & Player);
void  Enemyshoot();
void DrawEnemyBullet(sf::RenderWindow & window);

private:

	float _PlayerlastX ;
	float _PlayerlastY ;
	float _EnemylastX ;
	float _EnemylastY ;
	sf::CircleShape Bullet;
    float _DistToPlayer;
	float Coordinate_x;
	float Coordinate_y;

};

#endif