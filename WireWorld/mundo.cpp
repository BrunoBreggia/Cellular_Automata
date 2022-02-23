#include "mundo.h"

Mundo::Mundo(int pfil, int pcol): fil(pfil), col(pcol)
{
    grilla.resize(fil);
    mascara.resize(fil);
    for( unsigned i=0; i<fil; ++i ){
        grilla[i].resize(col);
        mascara[i].resize(col);
    }
    for (auto &fila : mascara)  ////////////// beware... a for-each!!
        for (auto &valor : fila)
            valor = cable;
}

void Mundo::cambiarActivo(unsigned x, unsigned y)
{
    state st = grilla[x][y].getEstado();
    (st == empty)? grilla[x][y].setEstado(cable) : grilla[x][y].setEstado(empty);
}

void Mundo::avanzarCicloReloj()
{
    std::vector<Posicion> vecinos;

    for(unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j) {
            if (grilla[i][j].getEstado() == cable) {
                Posicion p(i,j);
                p.getVecinos(vecinos);
                unsigned count = 0;
                for (auto &v : vecinos)
                    if (grilla[v.x][v.y].getEstado()==head)
                        ++count;
                if (count !=0 && count < 3) mascara[i][j] = head;
            } else if (grilla[i][j].getEstado() == head)
                mascara[i][j] = tail;
        }

    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j){
            if (grilla[i][j].getEstado() != empty) {
                grilla[i][j].setEstado( mascara[i][j] );
            }
            mascara[i][j] = cable;
        }
}

Celula &Mundo::celula(unsigned int x, unsigned int y)
{
    return grilla[x][y];
}

void Mundo::headsOff()
{
    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j)
            if (grilla[i][j].getEstado()<3)
                grilla[i][j].setEstado(cable);
}

void Mundo::quemarTodo()
{
    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j)
            grilla[i][j].setEstado( empty );
}

Mundo::~Mundo()
{
    // Nada
}
