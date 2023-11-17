#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Jugador.h"
#include "Usuario.h"

Jugador::Jugador() {
    misCartas.resize(2);
}

Jugador::~Jugador()
{
    // Destructor
}

// Calcula el valor de la mano actual
int Jugador::calcularMano() {
    int i, valorCarta;
    bool hayAs = false;
    total = 0;

    /// Por cada carta en la mano, suma su valor numérico al total.
    /// Si hay un As en la mano, lo contemplamos a futuro mediante la bandera hayAs.
    for (i = 0;i < misCartas[manoActual].size();i++) {
        valorCarta = misCartas[manoActual][i].getValor();
        if (valorCarta == 1) {
            hayAs = true;
        }
        total += valorCarta;
    }

    /// Si el total excede 21, el jugador se pasó
    if (total > 21) {
        setSePaso(manoActual);
    }

    // Si el total es menor o igual a once y tenemos un As, podemos usar su valor como 11.
    else if (total <= 11 && hayAs) {
        total += 10;
        // Comparamos si el total es menor a 21.
        if (total < 21) {
            /// Le mostramos ambos valores posibles de su mano.
            std::cout << total - 10 << " o " << total << std::endl;
        }
        // Si no es menor a 21 y no se pasó de 21, entonces es igual a 21.
        else {
            if (misCartas.size() == 2) {
                // Si es la primer mano (dos cartas), es Blackjack.
                setBlackjack();
            }
            else {
                // Sino, sólo es 21
                set21();
            }
        }
    }
    // De lo contrario, evaluamos la última posibilidad que requiera un paso extra.
    else if (total == 21) {
        set21();
    } 

    hayAs = false;
    return total;
}

// Devuelve el vector de cartas especificado por parámetro
std::vector<Carta> Jugador::getCartas(int _cartas) {
    return misCartas[_cartas];
}

// Agrega la carta al vector de cartas indicado por la mano actual
void Jugador::agregarCarta(Carta nuevaCarta) {
    misCartas[manoActual].push_back(nuevaCarta);
}

std::string Jugador::getNombre() {
    return nombre;
}

// Guarda el valor de la mano actual
void Jugador::setMano(int _mano) {
    mano[manoActual] = _mano;
}

// Devuelve el valor de la mano especificado parámetro
int Jugador::getMano(int _mano) {
    return mano[_mano];
}

// Devuelve si hay Blackjack en la mano actual
bool Jugador::getBlackjack() {
    return blackjack[manoActual];
}

// Asigna Blackjack a la mano actual
void Jugador::setBlackjack() {
    blackjack[manoActual] = true;
}

// Devuelve si hay 21 en la mano actual
bool Jugador::get21() {
    return veintiuno[manoActual];
}

// Asigna 21 a la mano actual
void Jugador::set21() {
    veintiuno[manoActual] = true;
}

// Devuelve si la mano actual se pasó
bool Jugador::getSePaso(int _mano) {
    return sePaso[_mano];
}

// Asigna que la mano actual se pasó
void Jugador::setSePaso(int _mano) {
    sePaso[_mano] = true;
}

// Devuelve si el jugador se plantó en su mano actual
bool Jugador::getPlanto() {
    return sePlanto[manoActual];
}

// Asigna que el jugador se plantó en su mano actual
void Jugador::setPlanto() {
    sePlanto[manoActual] = true;
}


