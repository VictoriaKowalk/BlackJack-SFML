#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include "Mazo.h"
#include "Jugador.h"
#include "Usuario.h"
#include "Banca.h"

class Mesa 
{
public:
    Mesa(std::vector<std::string>);
    ~Mesa();
    void correr();
    void repartir();
    std::vector<Usuario> getUsuarios();
    void addUsuario(Usuario);
    void siguienteTurno();
    void loop_events();
    void setGameOver();
    bool getGameOver();
    void determinarResultados();
private:
    Mazo miMazo;
    int pos;
    int cantUsuarios;
    int turno;
    bool pressedEnter;
    bool pressedFlechaArriba;
    bool pressedFlechaAbajo;
    bool seguirJugando = true;
    bool gameOver;
    Banca banca;
    sf::Font* font;
    sf::RenderWindow* window;
    sf::RectangleShape* winclose;
    sf::Texture* image;
    sf::Sprite* sprite;
    sf::Texture* imageBoton1;
    sf::Sprite* spriteBoton1;
    sf::Texture* imageBoton2;
    sf::Sprite* spriteBoton2;
    sf::Texture* imageBoton3;
    sf::Sprite* spriteBoton3;
    sf::Text nombreBanca;
    sf::Text mensajeBanca;
    sf::Text puntajeBanca;
    sf::Text mensajeGameOver;
    std::vector<const char*> textOptions;
    std::vector<sf::Vector2f> coordenadas;
    std::vector<sf::Vector2f> coordNombres;
    std::vector<std::vector<sf::Vector2f>> coordPuntajes;
    std::vector<std::vector<sf::Vector2f>> coordMensajes;
    std::vector<std::vector<sf::Vector2f>> coordMensajesResultados;
    std::vector<sf::Text> textVector;
    std::vector<std::vector<sf::Text>> puntajes;
    std::vector<std::vector<sf::Text>> mensajes;
    std::vector<std::vector<sf::Text>> mensajesResultados;
    std::vector<Usuario> usuarios;
    std::vector<std::string> nombresUsuarios;
    std::vector<sf::Text> nombresVector;
    // Coordenadas para las cartas de los jugadores
    int pos_y = 400;
    int pos_x[3] = { 650, 350, 50 }; // Se dibujan los jugadores de derecha a izquierda
    // Coordenadas para las cartas de la segunda mano de los jugadores
    int pos_x_division[3] = { 700, 400, 100 }; // Se dibujan los jugadores de derecha a izquierda
    // Coordenadas para las cartas de la banca
    int pos_x_banca = 350;
    int pos_y_banca = 100;
protected:
    void set_valores();
    void draw_all();
};