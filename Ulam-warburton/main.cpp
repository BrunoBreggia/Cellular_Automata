#include <QApplication>
#include "../Microtubules/AutomataCelularBase/graficador.h"
#include "mundoulam.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MundoUlam mundo;
    Graficador graficador(&mundo);
    graficador.graficar(app);

    return app.exec();
}
