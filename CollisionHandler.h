#ifndef  COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <SFML/Graphics.hpp>
#include "Playership.h"
#include "Enemy.h"
#include "Asteroid.h"

class CollisionHandler 
{
	
public:


void PlayerEnemyCollide(sf::RenderWindow& window, Playership &Player, Enemy & NewEnemy);
void PlayerAsteroidCollide(sf::RenderWindow& window, Playership &Player, Asteroid & Destroyer);

	
private:



};

#endif
