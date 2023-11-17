#include "MenuJugadores.h"
#include "MenuNombres.h"

MenuJugadores::MenuJugadores(){
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	// Se setea la posicion del cursor y del mouse en 0, y el estado de las teclas en falso (sin presionar)
	pos = 1;
	mouse_cord = { 0,0 };
	pressedFlechaArriba = false;
	pressedFlechaAbajo = false;
	// Se inicializa la cantidad de usuarios en 0
	cantUsuarios = 0;
}

MenuJugadores::~MenuJugadores() {
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

// Setea las propiedades de la ventana MenuJugadores
void MenuJugadores::set_valores() {
	// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Seleccionar jugadores");
	window->setPosition(sf::Vector2i(280, 100));
	// Se cargan fuentes, imagen y textura
	font->loadFromFile("./Casino.ttf");
	image->loadFromFile("./fondos/menu.png");
	bg->setTexture(*image);
	// Se crea un botón de cierre
	winclose->setSize(sf::Vector2f(88, 87));
	winclose->setPosition(1287, 2);
	// Se definen las opciones del menú 
	textOptions = { "CANTIDAD DE JUGADORES","1 JUGADOR", "2 JUGADORES", "3 JUGADORES" };
	textVector.resize(4);
	textCoord = { {470,130},{610,350},{590,470},{590,600} };
	textSizes = { 50,35,35,35 };
	// Se configuran los textos para cada opción
	for (std::size_t i{}; i < textVector.size(); i++) {
		textVector[i].setFont(*font);
		textVector[i].setString(textOptions[i]);
		textVector[i].setCharacterSize(textSizes[i]);
		textVector[i].setOutlineColor(sf::Color::Magenta);
		textVector[i].setPosition(textCoord[i]);
	}
}

void MenuJugadores::setCantUsuarios(int usuarios){
	cantUsuarios = usuarios;
}

int MenuJugadores::getCantUsuarios() {
	return cantUsuarios;
}

// Maneja los eventos de la ventana
void MenuJugadores::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			seguirJugando = false;
			window->close();
		}
		mouse_cord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

		// Desplaza con flecha hacia abajo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressedFlechaAbajo) {
			pressedFlechaAbajo = true;
			if (pos < 3) {
				pos++;
			}
		}
		// Desplaza con flecha hacia arriba
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressedFlechaArriba) {
			pressedFlechaArriba = true;
			if (pos > 1) {
				pos--;
			}
		}
		// Enter para seleccionar la opción
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (pos > 0) {
				setCantUsuarios(pos);
				window->close();
			}
		}
		// Condición para cerrar ventana
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (winclose->getGlobalBounds().contains(mouse_cord)) {
				seguirJugando = false;
				window->close();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false && pressedFlechaArriba) {
		pressedFlechaArriba = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == false && pressedFlechaAbajo) {
		pressedFlechaAbajo = false;
	}
}

// La función draw_all() se encarga de borrar el contenido anterior 
// de la ventana, dibujar el fondo y los textos en la ventana, 
// y luego mostrar la ventana.
void MenuJugadores::draw_all() {
	window->clear();
	window->draw(*bg);
	for (int i = 1;i < textVector.size();i++) {
		if (i != pos) {
			textVector[i].setOutlineThickness(0);
		}
		textVector[pos].setOutlineThickness(3);
	}

	for (sf::Text t : textVector) {
		window->draw(t);
	}
	window->display();
}

// Inicia el menu
void MenuJugadores::correr() {
    // Configuración inicial
	set_valores(); 
    // Entro en el while donde se manejan eventos y se dibuja el contenido del menú en cada iteración hasta que la ventana se cierre.
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
	if (seguirJugando) {
		MenuNombres menuNombres(getCantUsuarios());
		menuNombres.correr();
	}
}