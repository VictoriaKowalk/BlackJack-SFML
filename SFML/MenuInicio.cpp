#include "MenuInicio.h"
#include "MenuJugadores.h"

Inicio::Inicio() {
	window = new sf::RenderWindow();
	winNext = new sf::RectangleShape();
	image = new sf::Texture();
	sprite = new sf::Sprite();
	// Se setea la posición del mouse en 0
	mouse_cord = { 0,0 };
}

Inicio::~Inicio() {
	delete window;
	delete winNext;
	delete image;
	delete sprite;
}

// Setea las propiedades de la ventana Inicio
void Inicio::set_valores() {
	// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Inicio");
	window->setPosition(sf::Vector2i(280, 100));
	// Se carga la imagen y texturas
	image->loadFromFile("./fondos/bienvenida.png");
	sprite->setTexture(*image);
	// Se crea un botón de avance
	winNext->setSize(sf::Vector2f(190, 190));
	winNext->setPosition(1145, 550);
	winNext->setFillColor(sf::Color::Blue);
}

// Maneja los eventos de la ventana
void Inicio::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			seguirJugando = false;
			window->close();
		}
		// Condición para el Enter
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			window->close();
		}
		// Condición para el click del mouse
		mouse_cord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (winNext->getGlobalBounds().contains(mouse_cord)) {
				window->close();
			}
		}
	}
}

void Inicio::draw_all() {
	window->clear();
	window->draw(*sprite);
	window->display();
}

void Inicio::correr() {
	set_valores();
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
	if (seguirJugando) {
		MenuJugadores menuJugadores;
		menuJugadores.correr();
	}
}






