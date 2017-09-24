#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Vector>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////

using namespace std;

void moveClockwise(float & StartAngle, int &initial_x ,  int &initial_y, const int PlayerRadius );
void moveAntiClockwise(float & StartAngle, int &initial_x ,  int &initial_y, const int PlayerRadius );
void GenerateEnemyCoord(int & RandScreenSide, int &RandScreenXCoord, int &RandScreenYCoord, unsigned int ScreenWidth, unsigned int ScreenHeight);
void MoveEnemy(int &DistToScreenEdge,int &RandScreenXCoord,int &RandScreenYCoord,unsigned int ScreenWidth,unsigned int ScreenHeight, float EnemySpeed, int & xIncrement, int &yIncrement, int &CentreScreenX, int &CentreScreenY);
void DrawControlMenu(	sf::RectangleShape RulesScreen, sf::Text Controls,	sf::Text Shoot, sf::Text LeftArrow, sf::Text RightArrow, sf::Text Anti_clockwise, sf::Text GoodLuck,sf::RenderWindow &window);
void DrawStartMenu(	sf::RectangleShape Startscreen, sf::Text Gyruss,	sf::Text StartOption,sf::RenderWindow &window);
void PlayerEnemyCollide (unsigned int Collision,sf::CircleShape PlayerShip, sf::CircleShape Enemyship, sf::RenderWindow &window );
void SetStartMenu (sf::Font  &font, sf::Text &Gyruss,sf::Text &StartOption);
void SetControlMenu (sf::Font  &font, sf::Text &Controls,sf::Text &Shoot,sf::Text &LeftArrow,sf::Text &RightArrow,sf::Text &Anti_clockwise, sf::Text &GoodLuck);
	                            
int main (){


	unsigned int ScreenHeight = 800;
	unsigned int ScreenWidth = 800;
	
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Gyruss");
	
	window.setFramerateLimit(60);   // set fram rate to 60 fps to stop the game from being jumpy
	
	 sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
	return EXIT_FAILURE;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //	 set up the splash screen pause menu
	sf::Text Gyruss;
	sf::Text StartOption;
   SetStartMenu (font,Gyruss, StartOption);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Text Controls;
	sf::Text Shoot;
	sf::Text LeftArrow;
	sf::Text RightArrow;
	sf::Text Anti_clockwise;
	sf::Text GoodLuck;
    SetControlMenu ( font,  Controls, Shoot, LeftArrow, RightArrow,Anti_clockwise, GoodLuck);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	sf::Texture GalaxyTexture;
	GalaxyTexture.loadFromFile("resources/Galaxy.jpg");
	
	sf::Texture NebulaTexture;
	NebulaTexture.loadFromFile("resources/Nebula.jpg");

	sf::RectangleShape Startscreen;
    Startscreen.setSize( sf::Vector2f(ScreenWidth, ScreenWidth));
    Startscreen.setTexture( & GalaxyTexture);
    Startscreen.setOrigin(0,0);
	
	sf::RectangleShape RulesScreen;
    RulesScreen.setSize( sf::Vector2f(ScreenWidth, ScreenWidth));
    RulesScreen.setTexture( & NebulaTexture);
    RulesScreen.setOrigin(0,0);
	
	// draw a basic crcle for movement 
	sf::CircleShape PlayerShip(50);
	PlayerShip.setFillColor(sf::Color(137, 207, 240));
 
	sf::CircleShape Enemyship(25);
	Enemyship.setFillColor(sf::Color(255, 255, 0));
	
	sf::CircleShape PlayerLaser(15);
	PlayerLaser.setFillColor(sf::Color(255, 255, 255));

	bool isPlaying = false;
	bool IsEnemyOnScreen =  false;
	
      //Starting position of player on screen
   const int PlayerRadius = 280;
   float StartAngle = 89.44;
   int initial_x = ScreenWidth/2.0f;
   int initial_y = 580;

   int CentreScreenX =ScreenWidth/2.0f;
   int CentreScreenY = ScreenHeight/2.0f;
   
	srand(time(NULL));
	
	int RandScreenSide=0;
	int RandScreenXCoord=0;
	int RandScreenYCoord=0;
	int xIncrement=0;
	int yIncrement=0;
	float EnemySpeed = 2;
	int DistToScreenEdge=0;
   unsigned int Collision = 0;
   bool isRulesMenu = false;
   
   
   ///////////////////////////////////////////////////////////////////////////////////////////////
   int  Lasertocntr =0;
   int xIncLaser = 0;
   int LaserSeed = 3;
   int yIncLaser  = 0;
    int LaserTargetx = ScreenWidth/2.0f;
	int LaserTargety  = ScreenHeight/2.0f;
	
	int lastX  = 0;
	int lastY = 0;
	
	//////////////////////////////////////////////////////////////////////////////////////////////// 
	 while (window.isOpen()){
	
		sf::Event event;
		
        while (window.pollEvent(event))
        {
			
            if ((event.type == sf::Event::Closed) ||((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
			
			 if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {        isRulesMenu = true;
			
			}

				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)){
					
				window.clear(sf::Color(0, 0, 0));
				
				if(!isPlaying){
					
			      isPlaying = true;
				  
		   // set the centre of the shape, the radius of the shape and the starting positiong to be 6 O'clock
		   PlayerShip.setOrigin(PlayerShip.getRadius(), PlayerShip.getRadius());
		   PlayerShip.setRadius(50);
		   PlayerShip.setPosition(404, 679);

		   Enemyship.setOrigin(Enemyship.getRadius(), Enemyship.getRadius());
		   Enemyship.setRadius(20);
		   Enemyship.setPosition(ScreenWidth/2.0f,ScreenHeight/2.0f);
		
	
				}
				}

	}
	
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				
			 //clear the window and change the new position of the shape
		   window.clear(sf::Color::Black);
           moveClockwise(StartAngle,  initial_x , initial_y, PlayerRadius) ;
		   PlayerShip.setPosition(initial_x + ScreenWidth/2.0f , initial_y +ScreenHeight/2.0f);

	       }
		   
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				
			window.clear(sf::Color::Black);
			moveAntiClockwise(StartAngle,  initial_x , initial_y, PlayerRadius) ;
			PlayerShip.setPosition(initial_x + ScreenWidth/2.0f , initial_y +ScreenHeight/2.0f);

	       }
		   
		      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				
			window.clear(sf::Color::Black);
			
			PlayerLaser.setOrigin(PlayerLaser.getRadius(), PlayerLaser.getRadius());
		   PlayerLaser.setRadius(20);
		   PlayerLaser.setPosition(PlayerShip.getPosition().x,PlayerShip.getPosition().y);
			lastX  = PlayerShip.getPosition().x;
            lastY = PlayerShip.getPosition().y;
			
			
			Lasertocntr = sqrt((ScreenWidth/2.0f - lastX)*(ScreenWidth/2.0f - lastX) + (ScreenHeight/2.0f - lastY)*(ScreenHeight/2.0f - lastY));
			xIncLaser = LaserSeed*(ScreenWidth/2.0f - lastX)/Lasertocntr;
			yIncLaser = LaserSeed*(ScreenHeight/2.0f - lastY)/Lasertocntr;
		 

		 
			 
	       }
		   
		   
          window.clear(sf::Color(0, 0, 0));

        if (isPlaying)
        {
			
            if (IsEnemyOnScreen == false) 
                {
                    Enemyship.setPosition(ScreenWidth/2.0f,ScreenHeight/2.0f);
					
					GenerateEnemyCoord(RandScreenSide, RandScreenXCoord,RandScreenYCoord, ScreenWidth, ScreenHeight);

					CentreScreenX = ScreenWidth/2.0f;
					CentreScreenY = ScreenHeight/2.0f;
	
		          IsEnemyOnScreen = true;
		   
                }
				


				
				
			MoveEnemy(DistToScreenEdge,RandScreenXCoord,RandScreenYCoord,ScreenWidth,ScreenHeight, EnemySpeed, xIncrement,yIncrement,CentreScreenX,CentreScreenY);

				
			if (((Enemyship.getPosition().x <= ScreenWidth) && (Enemyship.getPosition().x  >= 0)) && ((Enemyship.getPosition().y<= ScreenWidth) && (Enemyship.getPosition().y >= 0))){
	
			Enemyship.setPosition(CentreScreenX,CentreScreenY);
			 
		 }else{
			 			
		IsEnemyOnScreen = false;
			 
		 }
		 
		 

//		 if ((PlayerLaser.getPosition().x != ScreenWidth/2.0f)  && (PlayerLaser.getPosition().y!= ScreenWidth/2.0f)){
	
	if ((PlayerLaser.getPosition().x != ScreenWidth/2.0f)  && (PlayerLaser.getPosition().y!= ScreenHeight/2.0f)){
	
		LaserTargetx += xIncLaser;
		 LaserTargety += yIncLaser;
			 
			PlayerLaser.setPosition(LaserTargetx,LaserTargety);
			
	}else{

			 
			 PlayerLaser.setPosition(PlayerShip.getPosition().x,PlayerShip.getPosition().y);
	 
	 }
	 

			
	   window.draw(PlayerShip);
       window.draw(Enemyship);
	   window.draw(PlayerLaser);
	   
	PlayerEnemyCollide (Collision,PlayerShip,  Enemyship, window );
	   

// to track the player as extra functionality
	
//	       float Speed = 3;
//          int distance = sqrt((PlayerShip.getPosition().x-Enemyship.getPosition().x)*(PlayerShip.getPosition().x-Enemyship.getPosition().x) + (PlayerShip.getPosition().y-Enemyship.getPosition().y)*(PlayerShip.getPosition().y-Enemyship.getPosition().y) );
//
//           int vX = Speed*(PlayerShip.getPosition().x-Enemyship.getPosition().x)/distance;
//		   int vY = Speed*(PlayerShip.getPosition().y-Enemyship.getPosition().y)/distance;
//		    x += vX;
//		     y += vY;
//       Enemyship.setPosition(x,y);
//
//
//	   
//			//redraw the shape 
//	       window.draw(PlayerShip);
//        window.draw(Enemyship);
 }
	else if (isRulesMenu == false){

     DrawStartMenu(Startscreen, Gyruss,StartOption,window);

        }
		else{
			
     DrawControlMenu(RulesScreen,Controls,Shoot, LeftArrow, RightArrow,  Anti_clockwise,  GoodLuck, window);

			}
		
		window.display();
	
	}
	
	return 0;
	
	}
	
	
	
////////////////////////////////////////////////////////////Function Declarations///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	


	void moveClockwise(float &StartAngle, int &initial_x , int &initial_y, const int PlayerRadius ){
		
			initial_x = PlayerRadius*cos(StartAngle);
			initial_y = PlayerRadius*sin(StartAngle);
			StartAngle+=0.05;

		return;
		
	}
	
	void moveAntiClockwise(float & StartAngle, int &initial_x ,  int &initial_y, const int PlayerRadius ){
		
			initial_x = PlayerRadius*cos(StartAngle);
			initial_y = PlayerRadius*sin(StartAngle);
			StartAngle-=0.05;
	
		return;
	}
	
void GenerateEnemyCoord(int & RandScreenSide, int &RandScreenXCoord, int &RandScreenYCoord, unsigned int ScreenWidth, unsigned int ScreenHeight){

		RandScreenSide= rand()%4 +1;
		
		if(RandScreenSide == 1){
			
			RandScreenXCoord= rand()%(ScreenWidth+1);
			RandScreenYCoord = 0;
		}else if (RandScreenSide == 2){
			
			RandScreenYCoord = rand()%(ScreenHeight+1);
			RandScreenXCoord = ScreenWidth;
		}else if (RandScreenSide == 3){
			
			RandScreenXCoord= rand()%(ScreenWidth+1);
			RandScreenYCoord = ScreenHeight;
		}else{
			
			RandScreenYCoord= rand()%(ScreenHeight+1);
			RandScreenXCoord= 0;
		}

	return;
}

void MoveEnemy(int &DistToScreenEdge,int &RandScreenXCoord,int &RandScreenYCoord,unsigned int ScreenWidth,unsigned int ScreenHeight, float EnemySpeed, int & xIncrement, int &yIncrement, int &CentreScreenX, int &CentreScreenY){
	
	
	DistToScreenEdge = sqrt((RandScreenXCoord-ScreenWidth/2.0f)*(RandScreenXCoord-ScreenWidth/2.0f) + (RandScreenYCoord-ScreenHeight/2.0f )*(RandScreenYCoord-ScreenHeight/2.0f));
	xIncrement = EnemySpeed*(RandScreenXCoord-ScreenWidth/2.0f)/DistToScreenEdge;
	yIncrement = EnemySpeed*(RandScreenYCoord-ScreenHeight/2.0f )/DistToScreenEdge;
	 
	CentreScreenX += xIncrement;
	CentreScreenY += yIncrement;
	
	
	
	return;
}

void DrawControlMenu(	sf::RectangleShape RulesScreen,sf::Text Controls,	sf::Text Shoot,  sf::Text LeftArrow, sf::Text RightArrow, sf::Text Anti_clockwise, sf::Text GoodLuck,sf::RenderWindow &window){
	
		window.draw(RulesScreen);
	    window.draw(Controls);
		window.draw(Shoot);
		window.draw(LeftArrow);
		window.draw(RightArrow);
		window.draw(Anti_clockwise);
		window.draw(GoodLuck);
	
	
	return;
}

void DrawStartMenu(	sf::RectangleShape Startscreen, sf::Text Gyruss,	sf::Text StartOption,sf::RenderWindow &window){
	
			window.draw(Startscreen);
			window.draw(Gyruss);
			window.draw(StartOption);
			
	return;
}

void PlayerEnemyCollide (unsigned int Collision,sf::CircleShape PlayerShip, sf::CircleShape Enemyship, sf::RenderWindow &window ){
	
Collision = abs(PlayerShip.getPosition().x - Enemyship.getPosition().x)+ abs(PlayerShip.getPosition().y - Enemyship.getPosition().y);
	
     if (Collision <=75)
        {
			
		  PlayerShip.setFillColor(sf::Color(255, 255, 255));
          window.draw(PlayerShip);
          return;
		  
        }else{
			
			PlayerShip.setFillColor(sf::Color(137, 207, 240));
			window.draw(PlayerShip);
			return;
			
		}
	
}

void SetStartMenu(sf::Font &font,sf::Text &Gyruss,sf::Text &StartOption){
	
    Gyruss.setFont(font);
    Gyruss.setCharacterSize(60);
    Gyruss.setPosition(280.f, 100.f);
    Gyruss.setColor(sf::Color(255,255,255));
    Gyruss.setString("GYRUSS");

    StartOption.setFont(font);
    StartOption.setCharacterSize(60);
    StartOption.setPosition(120.f, 600.f);
    StartOption.setColor(sf::Color(255,255,255));
    StartOption.setString("Press Space To Start");
	
	return;
}

void SetControlMenu (sf::Font  &font, sf::Text &Controls,sf::Text &Shoot,sf::Text &LeftArrow,sf::Text &RightArrow,sf::Text &Anti_clockwise, sf::Text &GoodLuck){

    Controls.setFont(font);
    Controls.setCharacterSize(40);
    Controls.setPosition(310.f, 100.f);
    Controls.setColor(sf::Color(255,255,255));
    Controls.setString("Controls :");
	
    Shoot.setFont(font);
    Shoot.setCharacterSize(40);
    Shoot.setPosition(220.f, 200.f);
    Shoot.setColor(sf::Color(255,255,255));
    Shoot.setString("Press Space To Shoot");
	
    LeftArrow.setFont(font);
    LeftArrow.setCharacterSize(40);
    LeftArrow.setPosition(30.f, 300.f);
    LeftArrow.setColor(sf::Color(255,255,255));
    LeftArrow.setString("Press Left Arrow Key to move Clockwise");

    RightArrow.setFont(font);
    RightArrow.setCharacterSize(40);
    RightArrow.setPosition(100.f, 400.f);
    RightArrow.setColor(sf::Color(255,255,255));
    RightArrow.setString("Press Right Arrow Key to move");

    Anti_clockwise.setFont(font);
    Anti_clockwise.setCharacterSize(40);
    Anti_clockwise.setPosition(250.f, 450.f);
    Anti_clockwise.setColor(sf::Color(255,255,255));
    Anti_clockwise.setString("Anti-clockwise");

    GoodLuck.setFont(font);
    GoodLuck.setCharacterSize(40);
    GoodLuck.setPosition(40.f, 550.f);
    GoodLuck.setColor(sf::Color(255,255,255));
    GoodLuck.setString("Press The Down Arrow Key to Begin Play");
	
	return;
}