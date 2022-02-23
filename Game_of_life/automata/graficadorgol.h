#ifndef GRAFICADORGOL_H
#define GRAFICADORGOL_H
#include <QtWidgets/QOpenGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include "mundo.h"
#include <iostream>

using namespace std;

class GraficadorGOL : public QOpenGLWidget
{
    Q_OBJECT

public:
    GraficadorGOL(QWidget *p_app);
    void graficar(QApplication *app);
    void setVelocidad_ms(unsigned dt);
    ~GraficadorGOL();

    void toggleHold();
    void acelerar(float escala);
    void limpiarTodo();
    void cerrar();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();
    void mousePressEvent(QMouseEvent *qme); //extraido de QWidget
    void keyPressEvent(QKeyEvent *qke);

private:
    Mundo miMundo;
//    QApplication *app;
    QTimer *cronometro;
    unsigned int pixFil, pixCol, deltaT;
    bool motion, terminated;

private slots:
    void animar();

};


#endif // GRAFICADORGOL_H
