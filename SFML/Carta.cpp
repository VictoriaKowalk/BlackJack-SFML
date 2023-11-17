#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Carta.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// No recibe argumentos.
Carta::Carta() {
    tipo = 0;
    
}

// Recibe dos argumentos: tipo (el valor dibujado en la carta), y el palo
Carta::Carta(int _tipo, std::string _palo){
    tipo = _tipo;
    palo = _palo;
    // Se carga imagen
    image = new sf::Texture();
    spriteCarta = new sf::Sprite();
    image->loadFromFile("./cartas/" + std::to_string(_tipo) + "_" + _palo + ".png");
    spriteCarta->setTexture(*image);
}

Carta::~Carta(){
    // Destructor
}

int Carta::getTipo(){
    // Devuelve el valor dibujado en la carta
    // Necesario para comprobar si hay cartas del mismo valor a la hora de dividir,
    // y a la hora de dibujar la carta
    return tipo;
}

sf::Sprite * Carta::getSprite() {
    return spriteCarta;
}

int Carta::getValor() {
    // Devuelve el valor de la carta, en términos del juego
    if (tipo > 9) {
        // Las figuras valen 10.
        return 10;
    }
    else {
        return tipo;
    }
}

std::string Carta::getPalo() {
    return palo;
}