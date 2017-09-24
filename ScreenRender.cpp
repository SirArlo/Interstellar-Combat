#include "ScreenRender.h"



 ScreenRender::ScreenRender( int ScreenHeight, int ScreenWidth, sf::RenderWindow & window):_ScreenHeight{ScreenHeight},_ScreenWidth{ScreenWidth}
{
	
	window.setFramerateLimit(60);
	SetMenu( _window);

	SetControlMenu( _window);
	
}

void ScreenRender::SetControlMenu( sf::RenderWindow & _window)
{
	
	font.loadFromFile("resources/sansation.ttf");
	
	NebulaTexture.loadFromFile("resources/Nebula.jpg");
	
	
	RulesScreen.setSize(sf::Vector2f(_ScreenWidth, _ScreenHeight));
    RulesScreen.setTexture(&NebulaTexture);
    RulesScreen.setOrigin(0, 0);
	
	
    Controls.setFont(font);
    Controls.setCharacterSize(40);
    Controls.setPosition(310.f, 100.f);
    Controls.setColor(sf::Color(255, 255, 255));
    Controls.setString("Controls :");

    Shoot.setFont(font);
    Shoot.setCharacterSize(40);
    Shoot.setPosition(220.f, 200.f);
    Shoot.setColor(sf::Color(255, 255, 255));
    Shoot.setString("Press Space To Shoot");

    LeftArrow.setFont(font);
    LeftArrow.setCharacterSize(40);
    LeftArrow.setPosition(30.f, 300.f);
    LeftArrow.setColor(sf::Color(255, 255, 255));
    LeftArrow.setString("Press Left Arrow Key to move Clockwise");

    RightArrow.setFont(font);
    RightArrow.setCharacterSize(40);
    RightArrow.setPosition(100.f, 400.f);
    RightArrow.setColor(sf::Color(255, 255, 255));
    RightArrow.setString("Press Right Arrow Key to move");

    Anti_clockwise.setFont(font);
    Anti_clockwise.setCharacterSize(40);
    Anti_clockwise.setPosition(250.f, 450.f);
    Anti_clockwise.setColor(sf::Color(255, 255, 255));
    Anti_clockwise.setString("Anti-clockwise");

    GoodLuck.setFont(font);
    GoodLuck.setCharacterSize(40);
    GoodLuck.setPosition(200.f, 550.f);
    GoodLuck.setColor(sf::Color(255, 255, 255));
    GoodLuck.setString("Press Enter to Begin Play");

    return;
}

void ScreenRender::SetMenu( sf::RenderWindow & _window)
{


	font1.loadFromFile("resources/sansation.ttf");
	
	Startscreen.setOrigin(0, 0);	GalaxyTexture.loadFromFile("resources/Universe.jpg");
	
    Startscreen.setSize(sf::Vector2f(_ScreenWidth, _ScreenHeight));
    Startscreen.setTexture(&GalaxyTexture);

    Gyruss.setFont(font1);
    Gyruss.setCharacterSize(60);
    Gyruss.setPosition(280.f, 100.f);
    Gyruss.setColor(sf::Color(255, 255, 255));
    Gyruss.setString("GYRUSS");

    StartOption.setFont(font1);
    StartOption.setCharacterSize(60);
    StartOption.setPosition(120.f, 600.f);
    StartOption.setColor(sf::Color(255, 255, 255));
    StartOption.setString("Press Space To Start");

    return;
}

void ScreenRender::DrawMenu(sf::RenderWindow & window)
{

    window.draw(Startscreen);
    window.draw(Gyruss);
    window.draw(StartOption);

    return;
}

void ScreenRender::DrawControlMenu(sf::RenderWindow & window)
{

    window.draw(RulesScreen);
    window.draw(Controls);
    window.draw(Shoot);
    window.draw(LeftArrow);
    window.draw(RightArrow);
    window.draw(Anti_clockwise);
    window.draw(GoodLuck);

    return;
}

void ScreenRender::DrawBackGround (sf::RenderWindow & window){
	
	window.draw(RulesScreen);
	
	
}