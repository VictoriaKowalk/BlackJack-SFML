#define _CRT_SECURE_NO_WARNINGS
#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include "Carta.h"
#include <iostream>

///El jugador con todos los metodos que pueden hacer tanto el Usuario como la banca

class Jugador
{
public:
    Jugador();
    virtual ~Jugador();
    int calcularMano();
    std::vector<Carta> getCartas(int);
    std::string getNombre();
    void setMano(int);
    int getMano(int);
    bool getBlackjack();
    void setBlackjack();
    void set21();
    bool get21();
    bool getSePaso(int);
    void setSePaso(int);
    bool getPlanto();
    void setPlanto();
    void agregarCarta(Carta);
protected:
    std::vector<std::vector<Carta>> misCartas;
    std::string nombre;
    int manoActual = 0;
    int total;
    int mano[2];
    bool sePaso[2] = { false };
    bool sePlanto[2] = { false };
    bool blackjack[2] = { false };
    bool veintiuno[2] = { false };
};

#endif // JUGADOR_H



