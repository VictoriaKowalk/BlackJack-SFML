#include "Menu.h"

//constructor de la clase Menu
Menu::Menu(){
// Se crea una ventana
	window = new sf::RenderWindow();
// un botón de cierre
	winclose = new sf::RectangleShape();
// una fuente
	font = new sf::Font();
//  una textura(
	image = new sf::Texture();
//  un fondo(sf::Sprite) 
	bg = new sf::Sprite();
	}


//destructor para de liberar la memoria
Menu::~Menu() {
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete bg;
}



//En la función set_valores(), se realizan varias configuraciones. 
void Menu::set_valores() {
// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Menu");
	window->setPosition(sf::Vector2i(0, 0));
	pos = 0;
	pressed = theselect = false;
// se cargan fuentes 
	font->loadFromFile("./Casino.ttf");
	image->loadFromFile("./menu.png");
// se cargan las texturas
	bg->setTexture(*image);
	pos_mouse = { 0,0 };
	mouse_cord = { 0,0 };

// se definen las opciones de menú 
	opciones = { "CANTIDAD DE JUGADORES","1 JUGADOR", "2 JUGADORES", "3 JUGADORES" };
	textos.resize(4);
	coordenadas = { {470,130},{610,350},{590,470},{590,600} };
	sizes = { 50,35,35,35 };
// se configuran los textos para cada opción. 
	for (std::size_t i{}; i < textos.size(); i++) {
		textos[i].setFont(*font);
		textos[i].setString(opciones[i]);
		textos[i].setCharacterSize(sizes[i]);
		textos[i].setOutlineColor(sf::Color::White);
		textos[i].setPosition(coordenadas[i]);
	}
// Además, se establece el botón de cierre en la esquina superior derecha de la ventana.
//seteo el tamaño y la posicion de la x para cerrar la ventana
	winclose->setSize(sf::Vector2f(88, 87));
	winclose->setPosition(1287, 2);
	winclose->setFillColor(sf::Color::Transparent);
}

//En la función loop_events(), se manejan los eventos de la ventana
void Menu::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		pos_mouse = sf::Mouse::getPosition(*window);
		mouse_cord = window->mapPixelToCoords(pos_mouse);
		//Para desplazar con la flecha para abajo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
			if (pos < 3) {
			pos++;
			pressed = true;
			textos[pos].setOutlineThickness(3);
			textos[pos - 1].setOutlineThickness(0);
			pressed = false;
			theselect = false;
			//std::cout << "pos: " << pos <<' \n';
			}
		}
		//Para desplazar la flecha para arriba
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
			if (pos >1) {
				pos--;
				pressed = true;
				textos[pos].setOutlineThickness(3);
				textos[pos + 1].setOutlineThickness(0);
				pressed = false;
				theselect = false;
				//std::cout << "pos: " << pos <<' \n';
			}
		}
		//Enter para selecionar la opcion
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&!theselect) {
			theselect = true;
			/*if (pos == 1) {

			}*/
		}
		//condicion para el click del mouse
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (winclose->getGlobalBounds().contains(mouse_cord)) {
				//std::cout << "Se cerro la ventana!" << ' \n';
				window->close();
			}
		}
	}
}

//La función draw_all() se encarga de borrar el contenido anterior de la ventana, dibujar el fondo y los textos en la ventana, y luego mostrar la ventana.
void Menu::draw_all() {
	window->clear();
	window->draw(*bg);
	//for each
	for (auto t : textos) {
		window->draw(t);
	}
	window->display();
}

//La función correr_menu() inicia el menú 
void Menu::correr_menu() {
// llamo a set_valores() para la configuración inicial 
	set_valores(); 
// entro en el while donde se manejan eventos y se dibuja el contenido del menú en cada iteración hasta que la ventana se cierre.
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
}

//////////
//CARGAR IMAGEN DE BLACKJACK
// 
