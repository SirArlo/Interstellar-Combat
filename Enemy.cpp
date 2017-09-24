#include "Enemy.h"

Enemy::Enemy(unsigned int ScreenWidth, unsigned int ScreenHeight):_ScreenWidth{ScreenWidth},  _ScreenHeight {ScreenHeight}
{
	    
	    EnemyCraft.setFillColor(sf::Color(255, 255, 0));
		EnemyCraft.setRadius(20);
		EnemyCraft.setOrigin(EnemyCraft.getRadius(), EnemyCraft.getRadius());
	    EnemyCraft.setPosition(_ScreenWidth / 2.0f, _ScreenHeight / 2.0f);
	
}


void Enemy::MoveEnemy()
{
       float EnemySpeed = 2;
    _DistToScreenEdge = sqrt((_RandScreenXCoord - _ScreenWidth / 2.0f) * (_RandScreenXCoord - _ScreenWidth / 2.0f) +
        (_RandScreenYCoord - _ScreenHeight / 2.0f) * (_RandScreenYCoord - _ScreenHeight / 2.0f));
    auto _xIncrement = EnemySpeed * (_RandScreenXCoord - _ScreenWidth / 2.0f) / _DistToScreenEdge;
    auto _yIncrement = EnemySpeed * (_RandScreenYCoord - _ScreenHeight / 2.0f) / _DistToScreenEdge;

    _CentreScreenX += _xIncrement;
    _CentreScreenY += _yIncrement;

    Coordinate_x = _CentreScreenX;
    Coordinate_y = _CentreScreenY;
	
    EnemyCraft.setPosition(Coordinate_x, Coordinate_y);
	
}


void Enemy::GenerateEnemyCoord()
{
    int RandScreenSide = rand() % 4 + 1;

    if(RandScreenSide == 1) {

	_RandScreenXCoord = rand() % (_ScreenWidth + 1);
	_RandScreenYCoord = 0;
    } else if(RandScreenSide == 2) {

	_RandScreenYCoord = rand() % (_ScreenHeight + 1);
	_RandScreenXCoord = _ScreenWidth;
    } else if(RandScreenSide == 3) {

	_RandScreenXCoord = rand() % (_ScreenWidth + 1);
	_RandScreenYCoord = _ScreenHeight;
    } else {

	_RandScreenYCoord = rand() % (_ScreenHeight + 1);
	_RandScreenXCoord = 0;
    }
	
	_CentreScreenX = _ScreenWidth/2.0f;
	_CentreScreenY = _ScreenHeight/2.0f;
	

    return;
}

void Enemy::DrawEnemy(sf::RenderWindow &window){
	
	  window.draw(EnemyCraft);
	  
}

void Enemy::ResetEnemy(){
		
	
     Coordinate_x =0;
	 Coordinate_y= 0;
	 EnemyCraft.setPosition(_ScreenWidth/2.0f,_ScreenHeight/2.0f );
		
}

float Enemy::XGetPos(){
	
	return EnemyCraft.getPosition().x;
	
}

float Enemy::YGetPos(){
	
 return EnemyCraft.getPosition().y;
	
}