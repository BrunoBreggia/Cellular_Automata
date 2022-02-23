#ifndef VENTANA_H
#define VENTANA_H

#include <QtWidgets/QOpenGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include "mundo.h"
#include <iostream>
using namespace std;

class Ventana : public QOpenGLWidget
{
    Q_OBJECT

public:
    Ventana(Mundo &mundo);
    void graficar(QApplication &p_app);
    void setVelocidad_ms(unsigned dt);
    ~Ventana();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();

    void mousePressEvent(QMouseEvent *qme); //extraido de QWidget
    void keyPressEvent(QKeyEvent *qke);

private:
    Mundo miMundo;
    QTimer *cronometro;
    unsigned int maxFil, maxCol, deltaT;
//    bool motion, terminated;

private slots:
    void animar();

};
#endif // VENTANA_H
