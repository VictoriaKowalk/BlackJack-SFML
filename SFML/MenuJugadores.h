#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuJugadores
{
public:
	MenuJugadores();
	~MenuJugadores();
	void correr();
	void setCantUsuarios(int);
	int getCantUsuarios();

private:
	sf::RenderWindow* window;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	int pos;
	sf::Vector2f mouse_cord;
	bool pressedFlechaArriba;
	bool pressedFlechaAbajo;
	int cantUsuarios;
	bool seguirJugando = true;
	std::vector<const char*> textOptions;
	std::vector<sf::Vector2f> textCoord;
	std::vector<sf::Text> textVector;
	std::vector<std::size_t> textSizes;

protected:
	void set_valores();
	void loop_events();
	void draw_all();
};


