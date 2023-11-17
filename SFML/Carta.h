#pragma once
#include <map>
#include <cstring>
#include <string>
#include <SFML/Graphics.hpp>
#ifndef CARTA_H
#define CARTA_H

class Carta 
{
public:
    Carta();
    Carta(int, std::string);
    virtual ~Carta();
    int getValor();
    int getTipo();
    std::string getPalo();
    sf::Sprite* getSprite();

private:
    int tipo;
    std::string palo;
    sf::Texture* image;
    sf::Sprite* spriteCarta;
};

#endif // CARTA_H