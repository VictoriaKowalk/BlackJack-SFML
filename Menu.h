#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
private:
	int pos;
	bool pressed, theselect;
	sf::RenderWindow* window;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_cord;

	std::vector<const char*> opciones;
	std::vector<sf::Vector2f> coordenadas;
	std::vector<sf::Text> textos;
	std::vector<std::size_t> sizes;

protected:
	void set_valores();
	void loop_events();
	void draw_all();

public: 
	Menu();
	~Menu();
	void correr_menu();
	//void MostrarBienvenida();
	//void correr_Bienvenida();


};


