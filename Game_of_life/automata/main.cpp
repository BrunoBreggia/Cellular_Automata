/**
  En honor a John Horton Conway, británico crador del Juego de la Vida, matemático, profesor
  en Princeton University for Advanced Studies.
  Felleció el 11 de Abril 2020 por el Covid-19.
  Lo recordaremos por siempre por su creación, aquí replicada.
  Descanse en paz, Conway...
*/

#include <QApplication>
#include <iostream>
#include "mundo.h"
#include "graficador.h"
#include "archivador.h"
#include "string"

typedef Posicion p;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Mundo mundo;
//    mundo.setVivos({p(50, 50), p(50,51), p(50,52), p(50,53), p(48,50), p(48,51)});
//    mundo.setVivos({p(25, 25), p(25,26), p(25,27), p(25,28), p(23,25), p(23,26)});
    Graficador graficador(&mundo);

    Archivador archivador;
    std::string option = "1";
    do{
        graficador.graficar(app);
        std::cout << "\n--------------------------------\n"
                  << "Administracion de archivos\n"
                  << "--------------------------------\n\n"
                  << "G. Guardar Tablero de Game of Life actual.\n\n"
                  << "A. Abrir Tablero de Game of Life de biblioteca.\n\n"
                  << "Eljio >> ";
        std::cin >> option;
        if (option == "g" || option == "G") archivador.saveToFile(mundo);
        else
            if (option == "a" || option == "A") archivador.loadFromFile(mundo);
    }while (option != "0");

    std::cout << "\n\n Good Bye!";

    return app.exec();
}
 // See https://copy.sh/life/examples/ for more patterns in the web
