#include <QApplication>
#include "mundo.h"
#include "ventana.h"
#include "constantes.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Mundo Circuito;
//    Circuito.celula(0,0).setEstado( cable );
//    Circuito.avanzarCicloReloj();
//    std::cout << "Hola , todo bien \n";
    Ventana graficador(Circuito);

    graficador.graficar(app);


    return app.exec();
}
