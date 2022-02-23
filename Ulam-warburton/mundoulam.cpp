#include "mundoulam.h"

void MundoUlam::avanzarEpoca()
{
    // Leyes del automata (se recorre la matriz aplicando las leyes de evolucion a cada celula)
    for (auto j=0; j<matriz.size(); ++j)
        for (auto i=0; i<matriz[j].size(); ++i) {
            pos aqui(j,i);
            vector<pos> vecinos;
            aqui.getVecindadNeumann(vecinos);
            int counter = 0;
            for (auto k=0; k<vecinos.size(); ++k)
                if ( matriz[ vecinos[k].y ][ vecinos[k].x ].getEstadoActual() == estado2 ) ++counter;
            if (counter == 1) matriz[ j ][ i ].setEstadoProximo(estado2);
        }

    // Actualizacion
    for (auto j=0; j<matriz.size(); ++j)
        for (auto i=0; i<matriz[j].size(); ++i)
            matriz[j][i].actualizar();
}
