#include "mundo.h"

Mundo::Mundo(int pfil, int pcol): fil(pfil), col(pcol)
{
    grilla.resize(fil);
    mascara.resize(fil);

    for (unsigned i=0; i<fil; ++i){
        grilla[i].resize(col);
        mascara[i].resize(col);

        for (unsigned j=0; j<col; ++j)
            mascara[i][j] = 0;
    }
}

void Mundo::setVivos(std::vector<Posicion> p)
{
    for (unsigned i=0; i<p.size(); ++i) {
        grilla[ p[i].x ][ p[i].y ].setVivo();
    }
    std::cout << "vivos seteados\n";
}

void Mundo::cambiarEstado(unsigned fil, unsigned col)
{
    if (grilla[fil][col].estaVivo()) grilla[fil][col].setMuerto();
    else grilla[fil][col].setVivo();
}

void Mundo::avanzarEpoca()
{
    std::vector<Posicion> vecinos;

    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j)
            if ( grilla[i][j].estaVivo() ) {
                Posicion pos(i, j);
                pos.getVecinos( vecinos );
                for (unsigned k=0; k<8; ++k)
                    mascara[ vecinos[k].x ][ vecinos[k].y ] += 1;
            }

    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j){
            if (mascara[i][j] == 3 && !(grilla[i][j].estaVivo())) grilla[i][j].setVivo();
            else if (mascara[i][j] < 2 && grilla[i][j].estaVivo() ) grilla[i][j].setMuerto();
            else if (mascara[i][j] > 3 && grilla[i][j].estaVivo() ) grilla[i][j].setMuerto();
            mascara[i][j] = 0;
        }
}

Celula &Mundo::celula(unsigned int x, unsigned int y)
{
    return grilla[x][y];
}

void Mundo::killAll()
{
    for (unsigned i=0; i<fil; ++i)
        for (unsigned j=0; j<col; ++j)
            grilla[i][j].setMuerto();
}

unsigned int Mundo::getFilas() const
{
    return fil;
}

unsigned int Mundo::getColumnas() const
{
    return col;
}

void Mundo::cambiarDimesion(unsigned pfil, unsigned pcol)
{
    fil=pfil;
    col=pcol;

    grilla.resize(fil);
    mascara.resize(fil);

    for (unsigned i=0; i<fil; ++i){
        grilla[i].resize(col);
        mascara[i].resize(col);

        for (unsigned j=0; j<col; ++j)
            mascara[i][j] = 0;
    }
}

Mundo::~Mundo()
{
    // Nada
}
