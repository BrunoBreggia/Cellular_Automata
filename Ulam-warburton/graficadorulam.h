#ifndef GRAFICADORULAM_H
#define GRAFICADORULAM_H
#include <QtWidgets/QOpenGLWidget>

#include "../Microtubules/AutomataCelularBase/mundo.h"

class GraficadorUlam : public Graficador
{
public:
    GraficadorUlam(Mundo* unMundo) : Graficador(unMundo) { }
    void paintGL() override;
};

#endif // GRAFICADORULAM_H
