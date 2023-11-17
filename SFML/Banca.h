#include "Jugador.h"
#ifndef BANCA_H
#define BANCA_H

/// Computadora, hereda atributos de Jugador
class Banca:public Jugador
{
public:
    Banca();
    virtual ~Banca();
    void setTurnoBanca();
    bool getTurnoBanca();
private:
    bool turnoBanca = false;
};

#endif // BANCA_H
