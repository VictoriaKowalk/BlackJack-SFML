#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bienvenida.h"
#include "Menu.h"
using namespace sf;

int main() {
    Bienvenida bienvenida;
    bienvenida.mostrar();
    Menu menu;
    menu.correr_menu();
   /* Menu* menu = new Menu();
    menu->MostrarBienvenida();
    menu->correr_menu();
    delete menu;
    menu = nullptr;*/
    return EXIT_SUCCESS;
}





/*
Para correr el paño
int main()
{
    Menu::MensajeBienvenida(sf::RenderWindow & window);

    sf::RenderWindow window(sf::VideoMode(1600, 800), "BlackJack!");
    
    Texture texture;
    texture.loadFromFile("./imagenes/pano.png");
       
    Sprite sprite1;
   sprite1.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite1);
        window.display();
    }

    return 0;
}*/