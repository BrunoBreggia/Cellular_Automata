#include "hormiguero.h"

Hormiguero::Hormiguero(unsigned filas, unsigned columnas)
{
    maxFil = filas;
    maxCol = columnas;
    epoca = 0;

    grilla.resize(maxCol);
    for (unsigned i=0; i<maxCol; ++i)
        grilla[i].resize(maxFil);

    limpiarRastros();
}

void Hormiguero::agregarHormiga(Hormiga &h)
{
//    Posicion aux = h.getPosicion();
    validarPosicion( h.getPosicion(1) );
//    h.setPosicion( aux );
    poblacion.push_back(h);
}

void Hormiguero::quitarHormigas()
{
    poblacion.clear();
}

void Hormiguero::limpiarRastros()
{
    for (unsigned i=0; i<maxCol; ++i)
        for (unsigned j=0; j<maxFil; ++j)
            grilla[i][j] = blanco;
}

void Hormiguero::avanzarEpoca()
{
    Posicion pos;

    for (unsigned i=0; i<poblacion.size(); ++i) {

        // Muevo una por una a cada hormiga
        pos = poblacion[i].getPosicion();
        poblacion[i].mover( grilla[pos.x][pos.y] );

        // Aseguro que la posicion sea valida para este hormiguero
        validarPosicion( poblacion[i].getPosicion(1) );

        // Cambio color a casilla abandonada
        grilla[pos.x][pos.y] = color(1 - grilla[pos.x][pos.y]);
    }

    ++epoca;
    std::cout << "Epoca: " << epoca << "\n";
}

void Hormiguero::cambiarColor(unsigned  fil, unsigned col)
{
    grilla[fil][col] = color(1 - grilla[fil][col]);
}

void Hormiguero::quitarUltimaHormiga()
{
    poblacion.pop_back();
}

color Hormiguero::getColor(unsigned fil, unsigned col)
{
    return grilla[fil][col];
}

std::vector<Hormiga> &Hormiguero::getHormigas()
{
    return poblacion;
}

unsigned Hormiguero::getFilas()
{
    return maxFil;
}

unsigned Hormiguero::getColumnas()
{
    return maxCol;
}

void Hormiguero::validarPosicion(Posicion &pos)
{
    int pCol = pos.x, pFil = pos.y;

    if (pFil<0) pFil += maxFil;
    if (pCol<0) pCol += maxCol;

    if (pFil>=maxFil) pFil -= maxFil;
    if (pCol>=maxCol) pCol -= maxCol;

    pos.x = pCol;
    pos.y = pFil;
}
