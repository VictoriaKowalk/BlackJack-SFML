#pragma once
#include "Registro.h"

class ArchivoJugadores
{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char*);
    bool grabarRegistro(RegistroJugador);
    int contarRegistros();
    RegistroJugador leerRegistro(int);
};


