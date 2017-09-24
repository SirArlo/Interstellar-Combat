#include "EnemyBullet.h"
#include "Enemy.h"
#include "Playership.h"

EnemyBullet::EnemyBullet( Enemy & Alien, Playership & Player)
{
	_PlayerlastX = Player.GetLastPositionX();
	_PlayerlastY = Player.GetLastPositionY();
	_EnemylastX =Alien.XGetPos();
	_EnemylastY =Alien.YGetPos();

	    Bullet.setFillColor(sf::Color(0, 255, 0));
		Bullet.setRadius(20);
		Bullet.setOrigin(Bullet.getRadius(), Bullet.getRadius());
	    Bullet.setPosition(_EnemylastX, _EnemylastY);

}

void  EnemyBullet::Enemyshoot(){
	
	float EnemyBulletSpeed = 5;

    _DistToPlayer = sqrt((_PlayerlastX- _EnemylastX) * (_PlayerlastX- _EnemylastX) +
        ( _PlayerlastY - _EnemylastY) * (_PlayerlastY -_EnemylastY));
    auto _xIncrement = EnemyBulletSpeed * (_PlayerlastX- _EnemylastX) / _DistToPlayer;
    auto _yIncrement = EnemyBulletSpeed * (_PlayerlastY -_EnemylastY) / _DistToPlayer;

    _EnemylastX += _xIncrement;
    _EnemylastY += _yIncrement;

    Coordinate_x = _EnemylastX;
    Coordinate_y = _EnemylastY;

    Bullet.setPosition(Coordinate_x, Coordinate_y);
	
}

void EnemyBullet::DrawEnemyBullet(sf::RenderWindow & window){
	
	window.draw(Bullet);
	
}