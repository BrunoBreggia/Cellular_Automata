#include "archivador.h"

Archivador::Archivador()
{

}

void Archivador::saveToFile(Mundo &pmundo)
{
    std::string name="";
    std::cout  << "Nombre de archivo: ";
    std::cin >> name;
    name = "gof/" + name;
    name += ".gof";
    std::fstream salida(name.c_str(), std::ios::binary | std::ios::out);
//    std::cout  << salida.is_open();

    unsigned int fil = pmundo.getFilas();
    unsigned int col = pmundo.getColumnas();
    bool estado;

    salida.write( (char*) &fil, sizeof(unsigned int) );
    salida.write( (char*) &col, sizeof(unsigned int) );

    for(unsigned i=0; i<pmundo.getFilas(); ++i){
        for(unsigned j=0; j<pmundo.getColumnas(); ++j){
            estado = pmundo.celula(i,j).estaVivo();
//            std::cout << estado << " ";
            salida.write( (char*) &estado, sizeof(bool) );
        }
//        std::cout << std::endl;
    }

//    std::cout  << "archivo guardado\n";
    salida.close();
}

void Archivador::loadFromFile(Mundo &pmundo)
{
    std::string name="";
    std::cout  << "Nombre de archivo: ";
    std::cin >> name;
    name = "gof/" + name;
    name += ".gof";
    std::fstream entrada(name.c_str(), std::ios::binary | std::ios::in);
//    std::cout  << entrada.is_open();

    unsigned int fil;
    unsigned int col;
    bool estado;

    entrada.read( (char*) &fil, sizeof(unsigned int) );
    entrada.read( (char*) &col, sizeof(unsigned int) );
    Mundo nuevoMundo;(fil, col);

    std::vector<Posicion> vivos;
    for(unsigned i=0; i<fil; ++i){
        for(unsigned j=0; j<col; ++j){
            entrada.read( (char*) &estado, sizeof(bool) );
//            std::cout << estado << " ";
            if (estado) vivos.push_back(Posicion(i, j));
        }
//        std::cout << std::endl;
    }
    nuevoMundo.setVivos(vivos);
    pmundo = nuevoMundo;

//    std::cout  << "archivo abierto\n";
    entrada.close();
}
