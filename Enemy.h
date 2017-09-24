#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>


class Enemy
{
public:


    Enemy(unsigned int ScreenWidth, unsigned int ScreenHeight);
    void GenerateEnemyCoord();
    void MoveEnemy();
	void DrawEnemy(sf::RenderWindow &window);
	void ResetEnemy();
	float XGetPos();
	float YGetPos();
	

private:

	 int Coordinate_x ;
     int Coordinate_y ;   
    float EnemySpeed;  
    sf::CircleShape EnemyCraft;
    int _RandScreenXCoord;
    int _RandScreenYCoord;
    unsigned int _ScreenWidth;
    unsigned int _ScreenHeight;
    int _CentreScreenX;
    int _CentreScreenY;
    int _DistToScreenEdge;
};

#endif
