#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "Carta.h"

class Mazo
{
public:
	Mazo();
	~Mazo();
	void mezclarMazo();
	Carta* getMazo();
	int getSiguienteCarta();
	Carta repartirCarta();
private:
	int siguienteCarta = 0;
	Carta mazo[52] = {}; // Guarda objetos de tipo carta
	std::string palos[4] = {"diamante","corazon","trebol","picas"};
};


