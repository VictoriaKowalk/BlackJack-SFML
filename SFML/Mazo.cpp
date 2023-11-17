#include "Mazo.h"

Mazo::Mazo() {
}

Mazo::~Mazo() {
}

Carta * Mazo::getMazo() {
	return mazo;
}

int Mazo::getSiguienteCarta() {
	return siguienteCarta;
}

Carta Mazo::repartirCarta() {
	Carta nuevaCarta = mazo[siguienteCarta]; // Obtiene la carta en la posición actual(siguienteCarta) del mazo.
	siguienteCarta++;
	return nuevaCarta;
}

void Mazo::mezclarMazo() {
	// Creo una matriz booleana de 52 cartas (13 valores por 4 palos)
	bool cartasRepartidas[13][4] = { false };
	// Hago un for de 52 cartas
	for (int i = 0; i < 52; i++) {
		// Mientras que la carta en la posición buscada sea 0 significa que no se le asignó un valor aún
		while (mazo[i].getTipo() == 0) {
			int valor = rand() % 13 + 1; // Elige un valor entre 1 y 13 (para la carta)
			int palo = rand() % 4 + 1; // Elige un valor entre 1 y 4 (para el palo)
			// Si en mi vector esa carta aún no salió, la asignamos a nuestro mazo
			if (cartasRepartidas[valor-1][palo-1] == false) {
				Carta carta(valor, palos[palo-1]);
				mazo[i] = carta;
				std::cout << "Valor: " << carta.getTipo() << " Palo: " << carta.getPalo() << std::endl;
				cartasRepartidas[valor-1][palo-1] = true;
			}
			/// Pero si esa carta ya salió, buscamos una nueva carta.
		}
	}
}