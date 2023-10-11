#include "Bienvenida.h"

Bienvenida::Bienvenida() {
    window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
    image = new sf::Texture();
	sprite = new sf::Sprite();
   }

Bienvenida::~Bienvenida() {
    delete window;
}


//En la función set_valores(), se realizan varias configuraciones. 
void Bienvenida::set_valores() {
	// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Bienvenida");
	window->setPosition(sf::Vector2i(0, 0));
	pos = 0;
	pressed = theselect = false;
	//cargo la imagen
	image->loadFromFile("./Bienvenida.png");
	// se cargan las texturas
	sprite->setTexture(*image);
	pos_mouse = { 0,0 };
	mouse_cord = { 0,0 };

	winclose->setSize(sf::Vector2f(190,190));
	winclose->setPosition(1145, 550);
	winclose->setFillColor(sf::Color::Blue);
}

//En la función loop_events(), se manejan los eventos de la ventana
void Bienvenida::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		pos_mouse = sf::Mouse::getPosition(*window);
		mouse_cord = window->mapPixelToCoords(pos_mouse);
		//Para desplazar con la flecha para abajo
	
		//Enter para selecionar la opcion
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
			theselect = true;
			
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

void Bienvenida::draw_all() {
	window->clear();
	window->draw(*sprite);
	window->display();
}


void Bienvenida::mostrar() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
		window->draw(*sprite);
        window->display();
    }
}







