#ifndef HORMIGUERO_H
#define HORMIGUERO_H
#include <vector>
#include <iostream>
#include "hormiga.h"

class Hormiguero
{
public:
    Hormiguero(unsigned filas, unsigned columnas);
    void agregarHormiga( Hormiga &h );
    void quitarHormigas();
    void limpiarRastros();
    void avanzarEpoca();
    void cambiarColor(unsigned fil, unsigned col);
    void quitarUltimaHormiga();

    color getColor(unsigned fil, unsigned col);
    std::vector< Hormiga > &getHormigas();
    unsigned getFilas();
    unsigned getColumnas();

private:
    std::vector< std::vector<color> > grilla;
    std::vector<Hormiga> poblacion;
    unsigned maxFil, maxCol, epoca;

    void validarPosicion(Posicion &pos);
};

#endif // HORMIGUERO_H
