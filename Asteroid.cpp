#include "Asteroid.h"
#include "Playership.h"


Asteroid::Asteroid(unsigned int ScreenWidth, unsigned int ScreenHeight):_ScreenWidth{ScreenWidth},  _ScreenHeight {ScreenHeight}
{
		AsteroidObj.setFillColor(sf::Color(139,0,139));
		AsteroidObj.setRadius(20);
		AsteroidObj.setOrigin(AsteroidObj.getRadius(), AsteroidObj.getRadius());
	    AsteroidObj.setPosition(_ScreenWidth / 2.0f, _ScreenHeight / 2.0f);
	
}

void  Asteroid::MoveAsteroid()
{
   float AsteroidSpeed = 5;

   _DistToPlayer = sqrt((_LastXCoord- _ScreenWidth / 2.0f) * (_LastXCoord - _ScreenWidth / 2.0f) +(_LastYCoord - _ScreenHeight / 2.0f) * (_LastYCoord - _ScreenHeight / 2.0f));
   auto _xIncrement = AsteroidSpeed * (_LastXCoord- _ScreenWidth / 2.0f) / _DistToPlayer;
   auto _yIncrement = AsteroidSpeed * (_LastYCoord- _ScreenHeight / 2.0f) / _DistToPlayer;

    _CentreScreenX += _xIncrement;
    _CentreScreenY += _yIncrement;

    Coordinate_x = _CentreScreenX;
    Coordinate_y = _CentreScreenY;
	
	AsteroidObj.setPosition(Coordinate_x, Coordinate_y);

}

void Asteroid::DrawAsteroid(sf::RenderWindow &window){
	
	window.draw(AsteroidObj);

}

float Asteroid::XGetPos(){
		
    return AsteroidObj.getPosition().x;	
	
}
	
float Asteroid::YGetPos(){
		
  return AsteroidObj.getPosition().y;	
		
}

void Asteroid::setPlayerLastCoord(int X ,int Y){
	
	_LastXCoord = X;
	_LastYCoord = Y;
	
	
}
	
void Asteroid::ResetPos(){
	
	_CentreScreenX = _ScreenWidth/2.0f;
	_CentreScreenY = _ScreenHeight/2.0f;
	
	AsteroidObj.setPosition(_ScreenWidth / 2.0f, _ScreenHeight / 2.0f);
	
	
}