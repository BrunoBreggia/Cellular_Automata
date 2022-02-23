#include <QApplication>
#include <iostream>
#include "hormiguero.h"
#include "graficador.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Hormiguero hormiguero(100,100);
    Hormiga h( Posicion(50,50) );
    hormiguero.agregarHormiga(h);

    Graficador graf(hormiguero);
    graf.graficar(app);

    return app.exec();
}
