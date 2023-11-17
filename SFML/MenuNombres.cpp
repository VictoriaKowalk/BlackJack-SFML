#include "MenuNombres.h"
#include "Mesa.h"

MenuNombres::MenuNombres(int usuarios) {
	// Se crea una ventana con un botón de cierre y play, fuente, textura, y fondo
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	playbutton = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	// Se setea la posicion del mouse en 0
	mouse_cord = { 0,0 };
	pressedEnter = false;
	pressedFlechaArriba = false;
	pressedFlechaAbajo = false;
	// Campos de usuario
	campoUsuario1 = new sf::RectangleShape();
	campoUsuario2 = new sf::RectangleShape();
	campoUsuario3 = new sf::RectangleShape();
	// Se inicializa la cantidad de usuarios y el usuario seleccionado actualmente
	cantUsuarios = usuarios;
	usuarioSeleccionado = 1;
}

MenuNombres::~MenuNombres() {
	delete window;
	delete winclose;
	delete playbutton;
	delete font;
	delete image;
	delete bg;
	delete campoUsuario1;
	delete campoUsuario2;
	delete campoUsuario3;
}

// Se setean las propiedades de la ventana Menu
void MenuNombres::set_valores() {
	// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Menu Nombres");
	window->setPosition(sf::Vector2i(280, 100));
	// Se cargan fuentes e imagen
	//font->loadFromFile("./Chicago.ttf");
	font->loadFromFile("./Mono.otf");
	// font->loadFromFile("./Casino.ttf");
	image->loadFromFile("./fondos/usuarios" + std::to_string(cantUsuarios) + ".png");
	// Se cargan las texturas
	bg->setTexture(*image);
	// Se definen las opciones del menú 
	textOptions = { "INGRESE NOMBRES DE USUARIOS","JUGADOR 1", "JUGADOR 2", "JUGADOR 3" };
	textOptionsCoord = { {390,130},{360,240},{360,360},{360,480} };
	textSizes = { 50,35,35,35 };
	textVector.resize(cantUsuarios + 1); // cantUsuarios+1 para que siempre contemple el titulo del menu
	// Se configuran los textos para cada opción
	for (std::size_t i{}; i < textVector.size(); i++) {
		textVector[i].setFont(*font);
		textVector[i].setString(textOptions[i]);
		textVector[i].setCharacterSize(textSizes[i]);
		textVector[i].setPosition(textOptionsCoord[i]);
		textVector[i].setOutlineColor(sf::Color::Magenta);
	}
	textVector[0].setOutlineThickness(0); // El título no tiene borde

	// Se establece el botón de cierre y el botón de jugar
	winclose->setSize(sf::Vector2f(105, 105));
	winclose->setPosition(1105, 2);
	playbutton->setSize(sf::Vector2f(190, 190));
	playbutton->setPosition(1205, 605);

	// Se establecen el tamaño y la posición de los campos de usuario
	campoUsuario1->setSize(sf::Vector2f(420, 57));
	campoUsuario1->setPosition(579, 232);
	campoUsuario2->setSize(sf::Vector2f(420, 57));
	campoUsuario2->setPosition(579, 355);
	campoUsuario3->setSize(sf::Vector2f(420, 57));
	campoUsuario3->setPosition(579, 478);

	// Se establecen las coordenadas para los nombres de cada usuario
	nombresCoord = { {600,240},{600,360},{600,480} };
	// Se establece el tamaño de los vectores de texto y de strings
	nombres.resize(cantUsuarios);
	nombreString.resize(cantUsuarios);
}

// Devuelve si los campos de nombre están llenos
bool MenuNombres::camposLlenos() {
	for (int i = 0;i < nombreString.size();i++) {
		if (nombreString[i].empty()) {
			// std::cout << "Falta el nombre del Jugador " << i + 1 << std::endl;
			return false;
		}
	}
	return true;
}

std::vector<std::string> MenuNombres::getUsuarios() {
	return nombreString;
}

// Maneja los eventos de la ventana
void MenuNombres::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			seguirJugando = false;
			window->close();
		}
		// Condición para el Enter
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressedEnter) {
			pressedEnter = true;
			// Sirve como atajo para pasar al siguiente campo
			if (camposLlenos()) {
				window->close();
			} else if (usuarioSeleccionado < cantUsuarios) {
				usuarioSeleccionado++;
			}
		}

		// Desplaza con flecha hacia abajo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressedFlechaAbajo) {
			pressedFlechaAbajo = true;
			if (usuarioSeleccionado < cantUsuarios) {
				usuarioSeleccionado++;
			}
		}
		// Desplaza con flecha hacia arriba
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressedFlechaArriba) {
			pressedFlechaArriba = true;
			if (usuarioSeleccionado > 1) {
				usuarioSeleccionado--;
			}
		}

		// Condición para el click del mouse
		mouse_cord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (winclose->getGlobalBounds().contains(mouse_cord)) {
				seguirJugando = false;
				window->close();
			}
			else if (playbutton->getGlobalBounds().contains(mouse_cord)) {
				if (camposLlenos()) {
					window->close();
				}
			}
			else if (campoUsuario1->getGlobalBounds().contains(mouse_cord)) {
				usuarioSeleccionado = 1;
			}
			else if (campoUsuario2->getGlobalBounds().contains(mouse_cord) && cantUsuarios > 1) {
				usuarioSeleccionado = 2;
			}
			else if (campoUsuario3->getGlobalBounds().contains(mouse_cord) && cantUsuarios > 2) {
				usuarioSeleccionado = 3;
			}
		}
		// Condición para escribir
		// Registra el texto ingresado por teclado
		if (event.type == sf::Event::TextEntered) 
		{
			if (event.text.unicode < 250) { // ASCII
				if (nombreString[usuarioSeleccionado-1].size() < 20) {
					// Si el string tiene menos de 20 caracteres, podemos escribir más
					nombreString[usuarioSeleccionado - 1].push_back(static_cast<char>(event.text.unicode));
					nombres[usuarioSeleccionado - 1].setString(nombreString[usuarioSeleccionado - 1]);
					nombres[usuarioSeleccionado - 1].setFont(*font);
					nombres[usuarioSeleccionado - 1].setCharacterSize(35);
					nombres[usuarioSeleccionado - 1].setPosition(nombresCoord[usuarioSeleccionado - 1]);
				}
			}
		}
		// Condición para borrar
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
			if (nombreString[usuarioSeleccionado-1].size() > 0){
				// Si el string tiene al menos 1 caracter, se puede borrar
				nombreString[usuarioSeleccionado - 1].pop_back();
				nombres[usuarioSeleccionado - 1].setString(nombreString[usuarioSeleccionado - 1]);
				nombres[usuarioSeleccionado - 1].setFont(*font);
				nombres[usuarioSeleccionado - 1].setCharacterSize(35);
				nombres[usuarioSeleccionado - 1].setPosition(nombresCoord[usuarioSeleccionado - 1]);
			}
		}
	}
	// Seteamos el pressed en False cuando el usuario deja de apretar Enter
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == false && pressedEnter) {
		pressedEnter = false;
	}
	// Seteamos el pressed en False cuando el usuario deja de apretar flecha Arriba
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false && pressedFlechaArriba) {
		pressedFlechaArriba = false;
	}
	// Seteamos el pressed en False cuando el usuario deja de apretar flecha Abajo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == false && pressedFlechaAbajo) {
		pressedFlechaAbajo = false;
	}
}

// La función draw_all() se encarga de borrar el contenido anterior 
// de la ventana, dibujar el fondo y los textos en la ventana, 
// y luego mostrar la ventana.
void MenuNombres::draw_all() {
	window->clear();
	window->draw(*bg);
	// Ajustamos el borde de la opción seleccionada
	for (int i = 1;i < textVector.size();i++) {
		if (i != usuarioSeleccionado) {
			textVector[i].setOutlineThickness(0);
		}
	}
	textVector[usuarioSeleccionado].setOutlineThickness(3);
	
	// Dibujamos los vectores de texto
	for (auto t : textVector) {
		window->draw(t);
	}
	for (auto n : nombres) {
		window->draw(n);
	}

	window->display();
}



// Inicia el menu Nombres
void MenuNombres::correr() {
	// Configuración inicial
	set_valores();
	// Entro en el while donde se manejan eventos y se dibuja el contenido del menú en cada iteración hasta que la ventana se cierre.
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
	if (seguirJugando) {
		Mesa mesa(getUsuarios());
		mesa.correr();
	}
}

