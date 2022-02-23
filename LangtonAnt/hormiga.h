#ifndef HORMIGA_H
#define HORMIGA_H
#include <map>
#include <iostream>

struct Posicion
{
    Posicion(int px=0, int py=0): x(px), y(py) {}
    Posicion operator +(const Posicion other) {
        return Posicion(x+other.x, y+other.y );
    }
    int x,y;
};
enum cardinal {norte=0, este=1, sur=2, oeste=3};
enum color {blanco=0, negro=1};

class Hormiga
{
public:
    Hormiga(Posicion p, cardinal dir=norte);
    void mover(color casilla);
    Posicion getPosicion();
    Posicion &getPosicion(int a);

private:
    Posicion posicion;
    cardinal direccion;
    std::map<cardinal, Posicion> mapa;
};




#endif // HORMIGA_H
