#include "ArchivoJugadores.h"



ArchivoJugadores::ArchivoJugadores(const char* n)
{
    strcpy_s(nombre, n);
}
bool ArchivoJugadores::grabarRegistro(RegistroJugador reg)
{
    FILE* p;
    p = fopen(nombre, "ab");
    if (p == NULL) return false;
    fseek(p, sizeof reg, 0);
    int escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoJugadores::contarRegistros()
{
    FILE* p;
    p = fopen(nombre, "rb");
    if (p == NULL) return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(RegistroJugador);
}

RegistroJugador ArchivoJugadores::leerRegistro(int pos) {
    RegistroJugador reg;
    FILE* p;
    p = fopen(nombre, "rb");
    if (p == NULL) return reg;
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}