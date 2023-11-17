#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuInicio.h"
#include <ctime>

using namespace sf;
using namespace std;

int main() {
    
    std::srand(std::time(0));
    Inicio juego;
    juego.correr();
    return EXIT_SUCCESS;
}