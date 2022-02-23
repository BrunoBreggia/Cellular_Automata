#include "ventana.h"

Ventana::Ventana(Mundo &mundo) : miMundo(mundo)
{
    maxFil = miMundo.getFilas();
    maxCol = miMundo.getColumnas();
//    motion = true;
//    terminated = false;
    deltaT = 1000;
    cronometro = new QTimer;
    cronometro->start(1000); // 500 milisegundos -> 0.5 seg
    connect( cronometro, SIGNAL(timeout()), this, SLOT(animar()) );
}

void Ventana::graficar(QApplication &p_app)
{
    resize(500, 500);
    show();
    p_app.exec();
}

void Ventana::setVelocidad_ms(unsigned dt)
{
    deltaT = dt;
}

Ventana::~Ventana()
{
    delete cronometro;
}

void Ventana::initializeGL()
{
    glClearColor(0, 0, 0, 0);
}

void Ventana::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0f, maxCol, maxFil, 0.0f, -1.0f, 1.0f);

    glMatrixMode( GL_MODELVIEW ); // y tenemos la matriz de textura, que no usamos
    glLoadIdentity();
}

void Ventana::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    float k = 1; //resolucion;

    glBegin(GL_QUADS); {
        for (unsigned i=0; i < maxFil; ++i) {
            for (unsigned j=0; j < maxCol; ++j) {
                if ( miMundo.celula(i, j).getEstado() != 3 ) {
                    switch (miMundo.celula(i, j).getEstado()) {
                    case cable:
                        glColor3f(0.6, 0.6, 0.6);
                        break;
                    case head:
                        glColor3f(1, 0, 0);
                        break;
                    case tail:
                        glColor3f(1, 1, 0);
                        break;
                    }
                    glVertex3f(  j*k,      i*k,     0);
                    glVertex3f(  j*k,     (i+1)*k,  0);
                    glVertex3f( (j+1)*k,  (i+1)*k,  0);
                    glVertex3f( (j+1)*k,   i*k,     0);
                }
            }
        }
    }
    glEnd();
}

void Ventana::mousePressEvent(QMouseEvent *qme)
{
    int x = qme->y()*maxFil/500;
    int y = qme->x()*maxCol/500;

    if( qme->button() == Qt::LeftButton ) {
        miMundo.cambiarActivo(x,y);
        repaint();
    } else if( qme->button() == Qt::RightButton ){
        if (miMundo.celula(x,y).getEstado() == 2){
            miMundo.celula(x,y).setEstado(head);
            repaint();
        }
    }
}

void Ventana::keyPressEvent(QKeyEvent *qke)
{
    if ( qke->key() == 32){
        miMundo.headsOff();
        repaint();
    }
    if ( qke->key() == Qt::Key_Right)
        deltaT /= 2;
    if ( qke->key() == Qt::Key_Left)
        deltaT *= 2;
    if ( qke->key() == 75){
        miMundo.quemarTodo();
        repaint();
    }
}

void Ventana::animar()
{
    miMundo.avanzarCicloReloj();
    repaint();
    cronometro->start(deltaT);
}
