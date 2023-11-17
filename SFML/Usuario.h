#ifndef USUARIO_H
#define USUARIO_H
#include "Jugador.h"

/// Humano, hereda atributos de Jugador
class Usuario:public Jugador
{
public:
    Usuario();
    Usuario(std::string);
    virtual ~Usuario();
    bool getPuedeDividir();
    void setPuedeDividir(bool);
    bool getDividio();
    void setDividio();
    void quitarCarta();
    void dividir();
    int getManoActual();
    void siguienteMano();
protected:
    bool puedeDividir = false;
    bool dividio = false;
};

#endif // USUARIO_H