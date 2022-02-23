#include "hormiga.h"

Hormiga::Hormiga(Posicion p, cardinal dir): posicion(p), direccion(dir)
{
    mapa[norte] = Posicion( 0, 1);
    mapa[este]  = Posicion( 1, 0);
    mapa[sur]   = Posicion( 0,-1);
    mapa[oeste] = Posicion(-1, 0);
}

void Hormiga::mover(color casilla)
{
    if (casilla == blanco) direccion = cardinal( (direccion + 1)%4 );
    else direccion = cardinal( (direccion + 3)%4 );
    posicion = posicion + mapa[direccion];
}

Posicion Hormiga::getPosicion()
{
    return posicion;
}

Posicion &Hormiga::getPosicion(int a)
{
    return posicion;
}
