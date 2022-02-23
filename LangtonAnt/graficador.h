#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QtWidgets/QOpenGLWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include "hormiguero.h"
#include <iostream>

class Graficador: public QOpenGLWidget
{
    Q_OBJECT
public:
    Graficador(Hormiguero &miHormiguero);
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
    Hormiguero hormiguero;
    QTimer *cronometro;
    unsigned int maxFil, maxCol, deltaT;
    bool motion;

private slots:
    void animar();
};

#endif // GRAFICADOR_H
