#include "PlayerBullet.h"
#include "Playership.h"

PlayerBullet::PlayerBullet( Playership & Player, unsigned int ScreenWidth, unsigned int ScreenHeight):_ScreenWidth{ScreenWidth},  _ScreenHeight {ScreenHeight}
{
	_lastX = Player.GetLastPositionX();
	_lastY = Player.GetLastPositionY();
	_CentreScreenX = _lastX;
	_CentreScreenY = _lastY;
	    Bullet.setFillColor(sf::Color(255, 0, 0));
		Bullet.setRadius(20);
		Bullet.setOrigin(Bullet.getRadius(), Bullet.getRadius());
	    Bullet.setPosition(_lastX, _lastY);

}


void  PlayerBullet::Playershoot(){
	
	float PlayerBulletSpeed = 5;

    _DistToCentre = sqrt((_ScreenWidth / 2.0f - _lastX) * ( _ScreenWidth / 2.0f - _lastX) +
        ( _ScreenHeight / 2.0f- _lastY) * (_ScreenHeight / 2.0f -_lastY));
    auto _xIncrement = PlayerBulletSpeed * (_ScreenWidth / 2.0f - _lastX) / _DistToCentre;
    auto _yIncrement = PlayerBulletSpeed * (_ScreenHeight / 2.0f -_lastY) / _DistToCentre;

    _CentreScreenX += _xIncrement;
    _CentreScreenY += _yIncrement;

    Coordinate_x = _CentreScreenX;
    Coordinate_y = _CentreScreenY;

    Bullet.setPosition(Coordinate_x, Coordinate_y);
	
	
}

void PlayerBullet::DrawPlayerBullet(sf::RenderWindow & window){
	
	window.draw(Bullet);
	
}