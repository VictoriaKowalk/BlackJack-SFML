#include "Registro.h"

RegistroJugador::RegistroJugador(Jugador obj) {
    int tamanio = obj.getNombre().length() + 1; // Calcula el tamaño necesario para almacenar el nombre del jugador más el carácter nulo '\0'.
    char* _nombre;
    _nombre = new char[tamanio];
    if (_nombre == nullptr) {
        std::cout << "Error de asignación de memoria." << std::endl;
        return;
    }
    strcpy(_nombre, obj.getNombre().c_str()); // Copia el contenido del nombre del jugador al espacio de memoria reservado.
    strcpy(nombre, _nombre);
    delete[] _nombre;
}

RegistroJugador::RegistroJugador() {

}

void RegistroJugador::gano() {
    _gano++;
}
void RegistroJugador::empato() {
    _empato++;
}
void RegistroJugador::perdio() {
    _perdio++;
}

int RegistroJugador::getPerdio() {
    return _perdio;
}

void RegistroJugador::setPerdio(int perdio) {
    _perdio = perdio;
}

int RegistroJugador::getEmpato() {
    return _empato;
}

void RegistroJugador::setEmpato(int empato) {
    _empato = empato;
}

int RegistroJugador::getGano() {
    return _gano;
}

void RegistroJugador::setGano(int gano) {
    _gano = gano;
}

void RegistroJugador::Mostrar() {
    std::cout << nombre << std::endl;
    std::cout << "Gano: " <<_gano << std::endl;
    std::cout << "Perdio: " << _perdio << std::endl;
    std::cout << "Empato: " << _empato << std::endl;
}
std::string RegistroJugador::getNombre() {
    std::string nombreString = nombre;
    return nombreString;
}