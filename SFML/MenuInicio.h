#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Inicio
{
public:
    Inicio();
    ~Inicio();
    void correr();

private:
    sf::RenderWindow* window;
    sf::RectangleShape* winNext;
    sf::Texture* image;
    sf::Sprite* sprite;
    sf::Vector2f mouse_cord;
    bool seguirJugando = true;

protected:
    void set_valores();
    void loop_events();
    void draw_all();
};
