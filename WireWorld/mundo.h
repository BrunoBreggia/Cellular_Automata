#ifndef MUNDO_H
#define MUNDO_H
#include "celula.h"
#include "constantes.h"
#include <vector>
#include <iostream>

struct Posicion;

class Mundo
{
public:
    Mundo(int pfil=maxFil, int pcol=maxCol);
    void cambiarActivo(unsigned x, unsigned y);
    void avanzarCicloReloj();
    Celula& celula(unsigned int x, unsigned int y);
    void headsOff();
    void quemarTodo();

    unsigned int getFilas() const { return fil; }
    unsigned int getColumnas() const { return col; }

    ~Mundo();

private:
    unsigned int fil, col;
    std::vector< std::vector<Celula> > grilla;
    std::vector< std::vector<state > > mascara;

};

struct Posicion {
    Posicion(unsigned int px=0, unsigned int py=0): x(px),y(py) {}
    int x=0,y=0;
    void getVecinos(std::vector<Posicion> &listado) {
        listado.clear();
        listado.resize(8);
        listado[0] = Posicion(x-1, y-1);
        listado[1] = Posicion(x-1,  y );
        listado[2] = Posicion(x-1, y+1);
        listado[3] = Posicion( x , y+1);
        listado[4] = Posicion(x+1, y+1);
        listado[5] = Posicion(x+1,  y );
        listado[6] = Posicion(x+1, y-1);
        listado[7] = Posicion( x , y-1);

        for (unsigned i=0; i<8; ++i) {
            if (listado[i].x < 0) listado[i].x = listado[i].x + maxFil;
            if (listado[i].y < 0) listado[i].y = listado[i].y + maxCol;

            if (listado[i].x >= maxFil) listado[i].x = listado[i].x - maxFil;
            if (listado[i].y >= maxCol) listado[i].y = listado[i].y - maxCol;
        }
    }
};

#endif // MUNDO_H
