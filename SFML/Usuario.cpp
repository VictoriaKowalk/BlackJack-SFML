#include "Usuario.h"
#include "Usuario.h"
#include <cstring>

Usuario::Usuario(std::string _nombre)
{
    nombre = _nombre;
}

Usuario::Usuario() {
}

Usuario::~Usuario() {
}

bool Usuario::getPuedeDividir() {
    return puedeDividir;
}

void Usuario::setPuedeDividir(bool estado) {
    puedeDividir = estado;
}

bool Usuario::getDividio() {
    return dividio;
}

void Usuario::setDividio() {
    dividio = true;
}

void Usuario::quitarCarta() {
    misCartas[manoActual].pop_back();
}

void Usuario::siguienteMano() {
	manoActual++;
}

int Usuario::getManoActual() {
	return manoActual;
}

void Usuario::dividir() {
	/// De nuestra primer mano (parámetro 0) tomamos la segunda carta (índice 1)
	Carta nuevaCarta = getCartas(0)[1];
	/// Quitamos esa carta de nuestra mano 1
	quitarCarta();
	/// Calculamos nuestra mano 1
	setMano(calcularMano());
	/// Pasamos a nuestra siguiente mano
	manoActual++;
	/// Agregamos la carta anterior
	agregarCarta(nuevaCarta);
	/// Calculamos nuestra mano 2
	setMano(calcularMano());
	/// Regresamos a nuestra mano anterior
	manoActual--;
	setPuedeDividir(false);
	setDividio();
}