#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 

class MenuNombres
{
public:
	MenuNombres(int aux);
	~MenuNombres();
	void correr();
	bool camposLlenos();
	std::vector<std::string> getUsuarios();

private:
	sf::RenderWindow* window;
	sf::RectangleShape* winclose;
	sf::RectangleShape* playbutton;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	sf::RectangleShape* campoUsuario1;
	sf::RectangleShape* campoUsuario2;
	sf::RectangleShape* campoUsuario3;
	int cantUsuarios;
	int usuarioSeleccionado;
	bool pressedEnter;
	bool pressedFlechaArriba;
	bool pressedFlechaAbajo;
	bool seguirJugando = true;
	sf::Vector2f mouse_cord;
	std::vector<const char*> textOptions;
	std::vector<sf::Vector2f> textOptionsCoord;
	std::vector<std::size_t> textSizes;
	std::vector<sf::Text> textVector;
	std::vector<sf::Vector2f> nombresCoord;
	std::vector<sf::Text> nombres; // Recibe los string modificados para dibujar
	std::vector<std::string> nombreString; // Almacena los string modificados

protected:
	void set_valores();
	void loop_events();
	void draw_all();
};