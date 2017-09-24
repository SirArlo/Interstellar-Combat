#include "Playership.h"
#include <iostream>

using namespace std;

Playership::Playership(int ScreenHeight, int ScreenWidth):_ScreenHeight{ScreenHeight},_ScreenWidth{ScreenWidth}
{
       float StartAngle = 89.44;
       PlayerCraft.setFillColor(sf::Color(137, 207, 240));
		PlayerCraft.setRadius(50);
	   PlayerCraft.setOrigin(PlayerCraft.getRadius(), PlayerCraft.getRadius());
	   PlayerCraft.setPosition(404, 679);
	
}


void Playership::moveClockwise(){

    Coordinate_x = PlayerRadius*cos(StartAngle);
    Coordinate_y = PlayerRadius*sin(StartAngle);
    StartAngle+=0.05;
	PlayerCraft.setPosition(Coordinate_x + _ScreenWidth / 2.0f, Coordinate_y + _ScreenHeight / 2.0f);

}
	
void Playership::moveAntiClockwise(){
	
	Coordinate_x = PlayerRadius*cos(StartAngle);
    Coordinate_y = PlayerRadius*sin(StartAngle);
    StartAngle-=0.05;
	PlayerCraft.setPosition(Coordinate_x + _ScreenWidth / 2.0f, Coordinate_y + _ScreenHeight / 2.0f);

	
}


void Playership::DrawPlayer(sf::RenderWindow &window){

	window.draw(PlayerCraft);
	
}

float Playership::GetLastPositionX(){
	
	return PlayerCraft.getPosition().x;
}


float Playership::GetLastPositionY(){
	
    return PlayerCraft.getPosition().y;
	
}