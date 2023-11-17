#pragma once
#include "Jugador.h"


class RegistroJugador {
private:
    char nombre[30];
    int _perdio = 0;
    int _gano = 0;
    int _empato = 0;
public:
    RegistroJugador(Jugador);
    RegistroJugador();
    void perdio();
    void empato();
    void gano();
    void Mostrar();
    std::string getNombre();
    void setGano(int);
    void setEmpato(int);
    void setPerdio(int);
    int getGano();
    int getEmpato();
    int getPerdio();
};
