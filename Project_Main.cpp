#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Playership.h"
#include "ScreenRender.h"
#include "Asteroid.h"
#include "CollisionHandler.h"
#include <iostream>

using namespace std;


int main()
{

    unsigned int ScreenHeight = 800;
    unsigned int ScreenWidth = 800;
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Gyruss");;
	ScreenRender Screens(ScreenHeight, ScreenWidth ,window);
	Playership Player(ScreenHeight, ScreenWidth);
	Enemy NewEnemy(ScreenWidth, ScreenHeight);
	Asteroid Destroyer(ScreenWidth, ScreenHeight);
	CollisionHandler CheckCol;

    bool isPlaying = false;
    bool IsEnemyOnScreen = false; 
	bool IsAsteroidOnScreen = false;
    srand(time(NULL));
    bool isRulesMenu = false;

    while(window.isOpen()) {

	sf::Event event;

	while(window.pollEvent(event)) {

	    if((event.type == sf::Event::Closed) ||
	        ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
		window.close();
		break;
	    }

	    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) {
		isRulesMenu = true;
	    }

	    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return)) {

		window.clear(sf::Color(0, 0, 0));

		if(!isPlaying) {

		    isPlaying = true;
		}
	    }
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

	   Player.moveClockwise();
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        Player.moveAntiClockwise();
	}

  Screens.DrawBackGround(window);

	if(isPlaying) {

		
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////Flying the Enemy/////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	    if(IsEnemyOnScreen == false) {
		NewEnemy.GenerateEnemyCoord();
		IsEnemyOnScreen = true;
	    }
		
        NewEnemy.MoveEnemy();
		
	    if(((NewEnemy.XGetPos()<= ScreenWidth) && (NewEnemy.XGetPos() >= 0)) &&
	        ((NewEnemy.YGetPos() <= ScreenHeight) && (NewEnemy.YGetPos() >= 0))) {
				
        NewEnemy.MoveEnemy();

	    } else {

		IsEnemyOnScreen = false;
		
	    }
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////Flying the asteroid////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if(IsAsteroidOnScreen == false) {
		
	    Destroyer.setPlayerLastCoord(Player.GetLastPositionX(),Player.GetLastPositionY());

		IsAsteroidOnScreen = true;
	    }


	    if(((Destroyer.XGetPos()<= ScreenWidth) && (Destroyer.XGetPos() >= 0)) && ((Destroyer.YGetPos() <= ScreenHeight) && (Destroyer.YGetPos() >= 0))) {

      Destroyer.MoveAsteroid();

	    } else{
			
			Destroyer.ResetPos();
			IsAsteroidOnScreen = false;
		}
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Player.DrawPlayer(window);
	    NewEnemy.DrawEnemy(window);
		Destroyer.DrawAsteroid(window);

       CheckCol.PlayerAsteroidCollide(window, Player, Destroyer);
       CheckCol.PlayerEnemyCollide(window, Player, NewEnemy);
	   
	} else if(isRulesMenu == false) {
		
		Screens.DrawMenu(window);

	} else {

		Screens.DrawControlMenu(window);
	}

	window.display();
    }

    return 0;
}






