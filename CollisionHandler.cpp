#include "CollisionHandler.h"
#include "Playership.h"
#include "Enemy.h"
#include "Asteroid.h"
#include <iostream>

using namespace std;

void CollisionHandler::PlayerEnemyCollide(sf::RenderWindow& window, Playership &Player, Enemy & NewEnemy)
{

	float Collision = abs(Player.GetLastPositionX()- NewEnemy.XGetPos()) +abs(Player.GetLastPositionY() - NewEnemy.YGetPos());

    if(Collision <= 75) {
    
		cout << "Player was hit by enemy ship!!!" << endl;
//	AcessColour.PlayerCraft.setFillColor(sf::Color(255,165,0));
//	Player.DrawPlayer(window);
	return;

    } else {

//	PlayerCraft.setFillColor(sf::Color(137, 207, 240));
//	Player.DrawPlayer(window);
	return;
    }
	
}

void CollisionHandler::PlayerAsteroidCollide(sf::RenderWindow& window, Playership &Player, Asteroid & Destroyer){
	
	float Collision = abs(Player.GetLastPositionX()- Destroyer.XGetPos()) +abs(Player.GetLastPositionY() - Destroyer.YGetPos());

    if(Collision <= 75) {
     cout << "Player was hit by Asteroid!!!" << endl;
//	PlayerCraft.setFillColor(sf::Color(0, 100, 0));
//	Player.DrawPlayer(window);
	return;

    } else {

//	PlayerCraft.setFillColor(sf::Color(137, 207, 240));
//	Player.DrawPlayer(window);
	return;
    }
	
}