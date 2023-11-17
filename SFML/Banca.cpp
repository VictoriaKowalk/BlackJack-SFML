#include "Banca.h"
#include <cstring>

Banca::Banca(){
   nombre = "La banca";
}

Banca::~Banca()
{
    // Destructor
}

bool Banca::getTurnoBanca() {
    return turnoBanca;
}

void Banca::setTurnoBanca() {
    turnoBanca = true;
}