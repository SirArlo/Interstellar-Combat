#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Playership.h"
#include "ScreenRender.h"
#include "Asteroid.h"
#include "CollisionHandler.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{

    unsigned int ScreenHeight = 800;
    unsigned int ScreenWidth = 800;
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Gyruss");;
	ScreenRender Screens(ScreenHeight, ScreenWidth ,window);
	Playership Player(ScreenHeight, ScreenWidth);
     vector<EnemyBullet> EnemyLaserVec;
	 
	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 /////////////////////////////Make the enemy vector//////////////////////////////////////////////
	 
     vector<Enemy> EnemyVec;
	 
	 for(int j = 0; j<10; j++){
		 
		 Enemy Alien(ScreenWidth, ScreenHeight);
		 EnemyVec.push_back(Alien);
		 
	 }
	 
	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 
	Asteroid Destroyer(ScreenWidth, ScreenHeight);
	CollisionHandler CheckCol;
	
	vector <PlayerBullet> LaserVec;

    bool isPlaying = false;

	vector<bool> IsEnemyOnScreen;
	
	for(int i =0; i<10; i++){
		
		IsEnemyOnScreen.push_back(false);
		
	}
	
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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        
		PlayerBullet laser(Player,ScreenWidth, ScreenHeight);
        LaserVec.push_back(laser);
		
	}

  Screens.DrawBackGround(window);

	if(isPlaying) {

		
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////Flying the Enemy/////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int j = 0; j<10; j ++){
		
	    if(IsEnemyOnScreen[j] == false) {
			
		EnemyVec[j].GenerateEnemyCoord();
		
		IsEnemyOnScreen[j] = true;
		
	    }
		
	}
	
	for (int i =0; i<10; i++){
		
		EnemyVec[i].MoveEnemy();
		
		
	}
			
		
	for (int i =0; i<10; i++){
				
	if(((EnemyVec[i].XGetPos()<= ScreenWidth) && (EnemyVec[i].XGetPos() >= 0)) &&
	        ((EnemyVec[i].YGetPos() <= ScreenHeight) && (EnemyVec[i].YGetPos() >= 0))) {
	
			EnemyVec[i].MoveEnemy();
			
	    } else {

		IsEnemyOnScreen[i] = false;
		
	    }
}


	for (int j = 0; j<10; j ++){
		
		if(IsEnemyOnScreen[j] == true) {
			
		EnemyBullet Enemylaser(EnemyVec[j], Player);
        EnemyLaserVec.push_back(Enemylaser);
		
		}
		
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
		/////////////////////////////////////////////////////////Shoot Player Bullets////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		for (unsigned int t = 0; t < LaserVec.size(); t ++){
			
			LaserVec[t].Playershoot();
			
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////Shoot enemy bullets /////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			for (unsigned int t = 0; t < EnemyLaserVec.size(); t ++){
			
			EnemyLaserVec[t].Enemyshoot();
			
		}
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Player.DrawPlayer(window);

			for (int i =0; i<10; i++){
				
				EnemyVec[i].DrawEnemy(window);
			   CheckCol.PlayerEnemyCollide(window, Player, EnemyVec[i]);
			   
			}
			
		for (unsigned int t = 0; t < LaserVec.size(); t ++){
		
		LaserVec[t].DrawPlayerBullet(window);
		
	     }
		 
		 for (unsigned int t = 0; t < EnemyLaserVec.size(); t ++){
		
		EnemyLaserVec[t].DrawEnemyBullet(window);
		
	     }
			
		Destroyer.DrawAsteroid(window);

       CheckCol.PlayerAsteroidCollide(window, Player, Destroyer);
	   
	} else if(isRulesMenu == false) {
	
		Screens.DrawMenu(window);

	} else {

		Screens.DrawControlMenu(window);
	}

	window.display();
    }

    return 0;
}






