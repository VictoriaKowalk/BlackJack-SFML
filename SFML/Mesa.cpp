#include "Jugador.h"
#include "Banca.h"
#include "Usuario.h"
#include "Mesa.h"
#include "Mazo.h"
#include "Registro.h"
#include "ArchivoJugadores.h"
#include <windows.h>

Mesa::Mesa(std::vector<std::string> nombres) {
	window = new sf::RenderWindow();
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	sprite = new sf::Sprite();
	imageBoton1 = new sf::Texture();
	spriteBoton1 = new sf::Sprite();
	imageBoton2 = new sf::Texture();
	spriteBoton2 = new sf::Sprite();
	imageBoton3 = new sf::Texture();
	spriteBoton3 = new sf::Sprite();
	// Se setea la posicion del cursor y del mouse en 0, y el estado de las teclas en falso (sin presionar)
	pos = 0;
	pressedEnter = false;
	pressedFlechaArriba = false;
	pressedFlechaAbajo = false;
	// Se llena el vector usuarios con los nombres de los usuarios recibidos de MenuNombre
	cantUsuarios = nombres.size();
	for (int i = 0;i < cantUsuarios;i++) {
		Usuario nuevoUsuario(nombres[i]);
		addUsuario(nuevoUsuario);
	}
	nombresUsuarios = nombres;
	// Se inicializa turno en 0
	turno = 0;
	textVector.resize(3);
	nombresVector.resize(cantUsuarios);
	puntajes.resize(2);
	for (int i = 0; i < 2;i++) {
		puntajes[i].resize(cantUsuarios);
	}
	mensajes.resize(2);
	for (int i = 0;i < 2;i++) {
		mensajes[i].resize(cantUsuarios);
	}
	mensajesResultados.resize(2);
	for (int i = 0;i < 2;i++) {
		mensajesResultados[i].resize(cantUsuarios);
	}
}

Mesa::~Mesa() {
	delete window;
	delete winclose;
	delete font;
	delete image;
	delete sprite;
	delete imageBoton1;
	delete spriteBoton1;
	delete imageBoton2;
	delete spriteBoton2;
	delete imageBoton3;
	delete spriteBoton3;
}

// Setea las propiedades de la ventana Mesa
void Mesa::set_valores() {
	// Se crea la ventana
	window->create(sf::VideoMode(1400, 800), "Mesa");
	window->setPosition(sf::Vector2i(280, 100));
	// Se cargan fuentes, imagen y textura
	// font->loadFromFile("./Casino.ttf");
	//font->loadFromFile("./Chicago.ttf"); //Fuente profe
	font->loadFromFile("./Mono.otf");
	image->loadFromFile("./fondos/mesa2.png");
	sprite->setTexture(*image);
	// Se cargan las imagenes para los botones
	imageBoton1->loadFromFile("./fondos/boton1.png");
	spriteBoton1->setTexture(*imageBoton1);
	imageBoton2->loadFromFile("./fondos/boton2.png");
	spriteBoton2->setTexture(*imageBoton2);
	imageBoton3->loadFromFile("./fondos/boton3.png");
	spriteBoton3->setTexture(*imageBoton3);
	// Se definen las opciones del menú 
	textOptions = { "PEDIR UNA CARTA","PLANTARSE", "DIVIDIR" };
	
	// Se configuran los textos para cada opción
	coordenadas = { {1095,465},{1095,525},{1095,585} };
	for (int i = 0; i < textVector.size(); i++) {
		textVector[i].setFont(*font);
		textVector[i].setCharacterSize(20);
		textVector[i].setPosition(coordenadas[i]);
		textVector[i].setString(textOptions[i]);
		textVector[i].setOutlineColor(sf::Color::Black);
		textVector[i].setOutlineThickness(1);

	}
	// JUGADORES
	// Se configuran los nombres
	coordNombres = { {680,600},{380,600},{80,600} };
	for (int i = 0; i < nombresVector.size(); i++) {
		nombresVector[i].setFont(*font);
		nombresVector[i].setString(nombresUsuarios[i]);
		nombresVector[i].setCharacterSize(30);
		nombresVector[i].setPosition(coordNombres[i]);
		nombresVector[i].setOutlineColor(sf::Color::Black);
		nombresVector[i].setOutlineThickness(1);
	}
	// Se configuran los puntajes
	coordPuntajes = { { {680,650},{380,650},{80,650} }, { {830,650},{530,650},{230,650} } };
	for (int m = 0; m < puntajes.size(); m++) {
		for (int u = 0; u < cantUsuarios; u++) {
			puntajes[m][u].setFont(*font);
			puntajes[m][u].setCharacterSize(20);
			puntajes[m][u].setPosition(coordPuntajes[m][u]);
			puntajes[m][u].setOutlineColor(sf::Color::Black);
			puntajes[m][u].setOutlineThickness(1);
		}
	}
	// Se configuran los mensajes
	coordMensajes = { { {680,680},{380,680},{80,680} }, { {830,680},{530,680},{230,680} } };
	for (int m = 0; m < mensajes.size(); m++) {
		for (int u = 0; u < cantUsuarios; u++) {
			mensajes[m][u].setFont(*font);
			mensajes[m][u].setCharacterSize(20);
			mensajes[m][u].setPosition(coordMensajes[m][u]);
			mensajes[m][u].setOutlineColor(sf::Color::Black);
			mensajes[m][u].setOutlineThickness(1);
		}
	}
	coordMensajesResultados = {{ {680,710},{380,710},{80,710} }, { {830,710},{530,710},{230,710} }};
	for (int m = 0; m < mensajesResultados.size(); m++) {
		for (int u = 0; u < cantUsuarios; u++) {
			mensajesResultados[m][u].setFont(*font);
			mensajesResultados[m][u].setCharacterSize(20);
			mensajesResultados[m][u].setPosition(coordMensajesResultados[m][u]);
			mensajesResultados[m][u].setOutlineColor(sf::Color::Black);
			mensajesResultados[m][u].setOutlineThickness(1);
		}
	}
	// BANCA
	// Se configura el nombre
	nombreBanca.setFont(*font);
	nombreBanca.setString("BANCA");
	nombreBanca.setCharacterSize(30);
	nombreBanca.setPosition({ 250, 100 });
	nombreBanca.setOutlineColor(sf::Color::Black);
	nombreBanca.setOutlineThickness(1);

	// Se configura el puntaje
	puntajeBanca.setFont(*font);
	puntajeBanca.setCharacterSize(20);
	puntajeBanca.setPosition({ 250,150 });
	puntajeBanca.setOutlineColor(sf::Color::Black);
	puntajeBanca.setOutlineThickness(1);

	// Se configura el mensaje
	mensajeBanca.setFont(*font);
	mensajeBanca.setCharacterSize(20);
	mensajeBanca.setPosition({ 250,180 });
	mensajeBanca.setOutlineColor(sf::Color::Black);
	mensajeBanca.setOutlineThickness(1);

	// Se configura el mensaje de finalización
	mensajeGameOver.setFont(*font);
	mensajeGameOver.setCharacterSize(40);
	mensajeGameOver.setPosition({ 500, 730 });
	mensajeGameOver.setOutlineColor(sf::Color::Black);
	mensajeGameOver.setOutlineThickness(1);

}

bool Mesa::getGameOver() {
	return gameOver;
}

void Mesa::setGameOver() {
	gameOver = true;
	mensajeGameOver.setString("JUEGO TERMINADO");
}

// Se reparten dos cartas por jugador y banca al principio del juego
void Mesa::repartir() {
	gameOver = false;
	miMazo.mezclarMazo();//El mazo es una propiedad de la mesa
	std::cout << "La proxima carta esta en la posicion " << miMazo.getSiguienteCarta() << std::endl;
	for (int i = 0;i < 2;i++) {
		// Se reparte a los jugadores
		for (int j = 0;j < usuarios.size();j++) {
			std::cout << usuarios[j].getNombre() << std::endl;
			Carta nuevaCarta = miMazo.repartirCarta();
			std::cout << "La carta vale " << nuevaCarta.getValor() << std::endl;
			usuarios[j].agregarCarta(nuevaCarta);
			std::cout << "La proxima carta esta en la posicion " << miMazo.getSiguienteCarta() << std::endl;
		}
		// Se reparte a la banca
		std::cout << "BANCA" << std::endl;
		Carta nuevaCarta = miMazo.repartirCarta();
		std::cout << "La carta vale " << nuevaCarta.getValor() << std::endl;
		banca.agregarCarta(nuevaCarta);
		std::cout << "La proxima carta esta en la posicion " << miMazo.getSiguienteCarta() << std::endl;
	}
	// Se calculan las manos de los jugadores
	for (int i=0; i < cantUsuarios; i++) {
		usuarios[i].setMano(usuarios[i].calcularMano());
		std::cout << "La mano de " << usuarios[i].getNombre() << " es de " << usuarios[i].getMano(0) << std::endl;
		puntajes[0][i].setString(std::to_string(usuarios[i].getMano(0)));// Mensaje del puntaje de la mano actual
		// Si alguno tiene Blackjack, seteamos el mensaje correspondiente
		if (usuarios[i].getBlackjack()) {
			mensajes[0][i].setString("BLACKJACK");
		}
		// De lo contrario, y si alguno puede dividir, seteamos la propiedad correspondiente
		else if (usuarios[i].getCartas(0)[0].getTipo() == usuarios[i].getCartas(0)[1].getTipo()) {
			usuarios[i].setPuedeDividir(true);
		}
		// Descomentar esta línea para poder dividir SIEMPRE
		usuarios[i].setPuedeDividir(true);
	}
	// Se calcula la mano de la banca
	banca.setMano(banca.calcularMano());

	// Si tiene Blackjack, seteamos los mensajes correspondientes
	if (banca.getBlackjack()) {
		puntajeBanca.setString("21");
		mensajeBanca.setString("BLACKJACK");
		// Y terminamos el juego pasando al turno de la banca, que ya no va a tomar ninguna otra acción
		//banca.setTurnoBanca();
		//setGameOver();
	}
	
	// De lo contrario, solo seteamos el mensaje de puntaje con el valor de la carta visible
	else {
		if (banca.getCartas(0)[1].getValor() == 1) {
			puntajeBanca.setString(std::to_string(11));
			// Si tiene un As visible, por única vez vamos a hacer que valga 11
		}
		else {
			puntajeBanca.setString(std::to_string(banca.getCartas(0)[1].getValor()));
		}
	}
}

std::vector<Usuario> Mesa::getUsuarios() {
	return usuarios;
}

// Agrega usuarios al vector Usuarios
void Mesa::addUsuario(Usuario nuevoUsuario) {
	usuarios.push_back(nuevoUsuario);
}

// Maneja los eventos de la ventana
void Mesa::loop_events() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}

		if (!getGameOver()) {
			if (banca.getTurnoBanca() == false) {// Si todavia no es el turno de la banca
				// Configuramos nombre del usuario
				nombresVector[turno].setOutlineColor(sf::Color::Magenta);
				nombresVector[turno].setOutlineThickness(3);
				// Si el usuario actual tiene Blackjack, pasamos al turno del siguiente
				if (usuarios[turno].getBlackjack()) {
					siguienteTurno();
				}

				//Para desplazar con la flecha para abajo
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressedFlechaAbajo) {
					pressedFlechaAbajo = true;
					if (pos < 2 && usuarios[turno].getPuedeDividir() || pos < 1) {
						pos++;
						textVector[pos].setOutlineThickness(3);
						textVector[pos - 1].setOutlineThickness(1);
					}
				}
				// Para desplazar la flecha para arriba
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressedFlechaArriba) {
					pressedFlechaArriba = true;
					if (pos > 0) {
						pos--;
						textVector[pos].setOutlineThickness(3);
						textVector[pos + 1].setOutlineThickness(1);
					}
				}
				// Enter para selecionar la opcion
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressedEnter) {
					pressedEnter = true;
					Carta nuevaCarta;
					switch (pos) {
					case 0:
						// Pedimos una nueva carta
						std::cout << usuarios[turno].getNombre() << " pide otra carta " << std::endl;
						nuevaCarta = miMazo.repartirCarta();
						std::cout << "La proxima carta esta en la posicion " << miMazo.getSiguienteCarta() << std::endl;
						usuarios[turno].agregarCarta(nuevaCarta);
						std::cout << "La carta vale " << nuevaCarta.getValor() << std::endl;
						usuarios[turno].setMano(usuarios[turno].calcularMano());
						std::cout << "La mano de " << usuarios[turno].getNombre() << " es de " << usuarios[turno].getMano(usuarios[turno].getManoActual()) << std::endl;
						puntajes[usuarios[turno].getManoActual()][turno].setString(std::to_string(usuarios[turno].getMano(usuarios[turno].getManoActual())));
						if (usuarios[turno].getSePaso(usuarios[turno].getManoActual())) {
							mensajes[usuarios[turno].getManoActual()][turno].setString("SE PASO");
						}

						// Si perdemos o llegamos a 21 pasamos al siguiente turno.
						if (usuarios[turno].getSePaso(usuarios[turno].getManoActual()) || usuarios[turno].get21()) {
							if (usuarios[turno].getDividio() && usuarios[turno].getManoActual() == 0) {
								usuarios[turno].siguienteMano();
							}
							else {
								siguienteTurno();
							}
							
						}
						break;
					case 1:
						//se planta y pasa al siguiente turno
						mensajes[usuarios[turno].getManoActual()][turno].setString("SE PLANTO");
						if (usuarios[turno].getDividio() && usuarios[turno].getManoActual() < 1) {
							usuarios[turno].siguienteMano();
						}
						else {
							siguienteTurno();
						}
						break;
					case 2:
						// Se separa la mano en dos manos.
						usuarios[turno].dividir();
						puntajes[0][turno].setString(std::to_string(usuarios[turno].getMano(0)));
						puntajes[1][turno].setString(std::to_string(usuarios[turno].getMano(1)));
						break;
					}
				}
			}
			else {
				banca.setMano(banca.calcularMano());
				puntajeBanca.setString(std::to_string(banca.getMano(0)));

				if (banca.getBlackjack()) {
					puntajeBanca.setString("21");
					mensajeBanca.setString("BLACKJACK");
				}
				if (banca.getMano(0) < 17) {
					Carta nuevaCarta;
					nuevaCarta = miMazo.repartirCarta();
					std::cout << "La proxima carta esta en la posicion " << miMazo.getSiguienteCarta() << std::endl;
					banca.agregarCarta(nuevaCarta);

				}
				else {
					if (banca.getSePaso(0)) {
						mensajeBanca.setString("SE PASO");
					}
					else {
						mensajeBanca.setString("SE PLANTO");
					}
					setGameOver();
					determinarResultados();
					//continuar?
				}
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

// Dibuja todos los elementos que aparecen en la ventana Mesa
void Mesa::draw_all() {
	window->clear();
	window->draw(*sprite);

	// CARTAS JUGADORES
	for (int i = 0; i < usuarios.size();i++) {
		int pos_x_actual = pos_x[i];
		int pos_y_actual = pos_y;
		// MANO 1
		for (int j = 0; j < usuarios[i].getCartas(0).size(); j++) {
			sf::Sprite* spriteCarta = usuarios[i].getCartas(0)[j].getSprite();
			if (usuarios[i].getDividio()) {
				spriteCarta->setPosition(pos_x_actual-50, pos_y_actual);
				window->draw(*spriteCarta);
				pos_y_actual += 30;
			}
			else {
				spriteCarta->setPosition(pos_x_actual, pos_y_actual);
				window->draw(*spriteCarta);
				pos_x_actual += 30;
				pos_y_actual += 30;
			}
		}
		// MANO 2
		if (usuarios[i].getDividio()) {
			pos_x_actual = pos_x_division[i];
			pos_y_actual = pos_y;
			for (int j = 0; j < usuarios[i].getCartas(1).size(); j++) {
				sf::Sprite* spriteCarta = usuarios[i].getCartas(1)[j].getSprite();
				spriteCarta->setPosition(pos_x_actual + 50, pos_y_actual);
				window->draw(*spriteCarta);
				pos_y_actual += 30;
			}
		}
	}

	// OPCIONES
	// Si no es el turno de la banca, dibujamos las opciones
	if (banca.getTurnoBanca() == false) {
		// Iteramos por usuario
		for (int i = 0; i < usuarios.size(); i++) {
			// Si es su turno, dibujamos las opciones posibles
			if (i == turno) {
				window->draw(*spriteBoton1);
				window->draw(*spriteBoton2);
				window->draw(textVector[0]);
				window->draw(textVector[1]);
				// Preguntamos si puede dividir
				if (usuarios[i].getPuedeDividir()) {
					window->draw(*spriteBoton3);
					window->draw(textVector[2]);
				}
			}
		}
	}

	// TEXTOS JUGADORES
	for (sf::Text n : nombresVector) {
		window->draw(n);
	}

	for (std::vector<sf::Text> m : puntajes) {
		for (int i = 0;i < cantUsuarios;i++) {
			window->draw(m[i]);
		}
	}
	for (std::vector<sf::Text> m : mensajes) {
		for (int i = 0;i < cantUsuarios;i++) {
			window->draw(m[i]);
		}
	}
	for (std::vector<sf::Text> m : mensajesResultados) {
		for (int i = 0;i < cantUsuarios;i++) {
			window->draw(m[i]);
		}
	}

	// CARTAS BANCA
	// Inicializa las posiciones actuales de las cartas de la banca con las posiciones iniciales predefinidas.
	int pos_x_actual_banca = pos_x_banca;
	int pos_y_actual_banca = pos_y_banca;
	// Recorre las cartas en la mano de la banca.
	for (int i = 0; i < banca.getCartas(0).size(); i++) {
		// Si todavía no es el turno de la banca y es su primer carta, dibujar el revés
		if (banca.getTurnoBanca() == false && i == 0) {
			sf::Sprite* spriteCartaOculta = new sf::Sprite();// Crea un nuevo objeto Sprite para la carta oculta.
			image = new sf::Texture();
			image->loadFromFile("./cartas/Mazo.png");// Carga la imagen del reverso de la carta desde un archivo.
			spriteCartaOculta->setTexture(*image);
			spriteCartaOculta->setPosition(pos_x_actual_banca, pos_y_actual_banca);
			window->draw(*spriteCartaOculta);// Dibuja el Sprite en la ventana.
			// Incrementa las posiciones actuales para la siguiente carta.
			pos_x_actual_banca += 30;
			pos_y_actual_banca += 30;
		}
		// Si no, dibujar la carta normalmente
		else {
			sf::Sprite* spriteCarta = banca.getCartas(0)[i].getSprite();
			spriteCarta->setPosition(pos_x_actual_banca, pos_y_actual_banca);
			window->draw(*spriteCarta);
			pos_x_actual_banca += 30;
			pos_y_actual_banca += 30;
		}
	}

	// TEXTOS BANCA
	window->draw(nombreBanca);
	window->draw(puntajeBanca);
	window->draw(mensajeBanca);

	// MENSAJES JUEGO
	window->draw(mensajeGameOver);

	window->display();
}

void Mesa::siguienteTurno() {
	// Al dejar de ser su turno, reseteamos la configuración de su nombre
	nombresVector[turno].setOutlineColor(sf::Color::Black);
	nombresVector[turno].setOutlineThickness(1);
	// Si no hay siguiente usuario elegible, es turno de la banca
	if (turno + 1 == usuarios.size()) {
		banca.setTurnoBanca();
	}
	// De lo contrario podemos pasar al siguiente jugador
	else {
		turno++;
		nombresVector[turno].setOutlineColor(sf::Color::Magenta);
		nombresVector[turno].setOutlineThickness(3);
	}
}

// Recibe el usuario y el numero de mano a comparar con la banca
void Mesa::determinarResultados() {

	ArchivoJugadores miarchi("jugadores.dat"); // Se crea un objeto de la clase ArchivoJugadores para manejar archivos
	int cantRegistros = miarchi.contarRegistros();

	for (int i = 0; i < cantUsuarios;i++) {
		RegistroJugador reg(usuarios[i]);
		for (int j = 0; j < 2;j++) { // representa cada mano
			if (banca.getSePaso(0) == false && usuarios[i].getSePaso(j) == true) {
				if (usuarios[i].getDividio() || j == 0) {
					mensajesResultados[j][i].setString("PERDIO");
					reg.perdio();
				}
			}
			else if (banca.getSePaso(0) == true && usuarios[i].getSePaso(j) == false) {
				if (usuarios[i].getDividio() || j == 0) {
					mensajesResultados[j][i].setString("GANO");
					reg.gano();
				}
			}
			else if (banca.getSePaso(0) == true && usuarios[i].getSePaso(j) == true) {
				if (usuarios[i].getDividio() || j == 0) {
					mensajesResultados[j][i].setString("EMPATO");
					reg.empato();
				}
			}
			else {
				if (banca.getMano(0) > usuarios[i].getMano(j)) {
					if (usuarios[i].getDividio() || j == 0) {
						mensajesResultados[j][i].setString("PERDIO");
						reg.perdio();
					}
				}
				else if (banca.getMano(0) == usuarios[i].getMano(j)) {
					if (usuarios[i].getDividio() || j == 0) {
						mensajesResultados[j][i].setString("EMPATO");
						reg.empato();
					}
				}
				else {
					if (usuarios[i].getDividio() || j == 0) {
						mensajesResultados[j][i].setString("GANO");
						reg.gano();
					}
				}
			}
		}
		//reg.Mostrar();
		miarchi.grabarRegistro(reg);
	}
	cantRegistros = miarchi.contarRegistros();
	std::cout << "REGISTROS DE PARTIDAS" << std::endl;
	for (int i = 0; i < cantRegistros; i++) {
		RegistroJugador reg = miarchi.leerRegistro(i);
		reg.Mostrar();
	}
}

void Mesa::correr() {
	set_valores();
	repartir();
	while (window->isOpen()) {
		loop_events();
		draw_all();
	}
}

