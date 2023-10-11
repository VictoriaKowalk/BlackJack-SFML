#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

    class Bienvenida {
    public:
        Bienvenida();
        ~Bienvenida();
        void mostrar();

    private:
        int pos;
        bool pressed, theselect;
        sf::RenderWindow* window;
        sf::RectangleShape* winclose;
        sf::Texture* image;
        sf::Sprite* sprite;
        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_cord;
    protected:
        void set_valores();
        void loop_events();
        void draw_all();
    };
