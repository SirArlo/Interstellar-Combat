#ifndef SCREENRENDER_H
#define SCREENRENDER_H

#include <SFML/Graphics.hpp>


class ScreenRender
{
	
public:

ScreenRender( int ScreenHeight, int ScreenWidth ,sf::RenderWindow & window);

void DrawControlMenu(sf::RenderWindow & window);
	
void DrawMenu(sf::RenderWindow & window);

void SetMenu( sf::RenderWindow & _window);

void SetControlMenu( sf::RenderWindow & _window);

void DrawBackGround (sf::RenderWindow & window);
	
private:

int _ScreenHeight;
int _ScreenWidth;
sf::RenderWindow _window;
sf::Text Gyruss;
sf::Text StartOption;
sf::Texture GalaxyTexture;
sf::RectangleShape Startscreen;
sf::Font font1;
sf::Text Controls;
sf::Text Shoot;
sf::Text LeftArrow;
sf::Text RightArrow;
sf::Text Anti_clockwise;
sf::Text GoodLuck;
sf::Texture NebulaTexture;
sf::RectangleShape RulesScreen;
sf::Font font;

};

#endif