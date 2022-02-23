#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <QtWidgets/QOpenGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include "mundo.h"
#include <iostream>

using namespace std;

class Graficador : public QOpenGLWidget
{
    Q_OBJECT

public:
    Graficador(Mundo *mundo);
    void graficar(QApplication &p_app);
    void setVelocidad_ms(unsigned dt);
    ~Graficador();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();

    void mousePressEvent(QMouseEvent *qme); //extraido de QWidget
    void keyPressEvent(QKeyEvent *qke);

private:
    Mundo *miMundo;
    QTimer *cronometro;
    unsigned int pixFil, pixCol, deltaT;
    bool motion, terminated;

private slots:
    void animar();

};

#endif // GRAFICADOR_H
