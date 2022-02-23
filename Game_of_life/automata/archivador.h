#ifndef ARCHIVADOR_H
#define ARCHIVADOR_H
#include "mundo.h"
#include "string"
#include <qfiledialog.h>
#include <fstream>
#include <iostream>

class Archivador
{
public:
    Archivador();
    void saveToFile(Mundo &pmundo);
    void loadFromFile(Mundo &pmundo);
};

#endif // ARCHIVADOR_H
