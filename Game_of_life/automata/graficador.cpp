#include "graficador.h"

Graficador::Graficador(Mundo *mundo)
{
    miMundo = mundo;
    pixFil = miMundo->getFilas();
    pixCol = miMundo->getColumnas();

    if (pixFil>pixCol) {
        pixCol = TAM*1.f*pixCol/pixFil;
        pixFil = TAM;
    } else if (pixFil<pixCol){
        pixFil = TAM*1.f*pixFil/pixCol;
        pixCol = TAM*1.f;
    } else {
        pixFil = TAM;
        pixCol = TAM;
    }

    motion = false;
    terminated = false;
    deltaT = 1000;
    cronometro = new QTimer;
    cronometro->start(1000); // 500 milisegundos -> 0.5 seg
    connect( cronometro, SIGNAL(timeout()), this, SLOT(animar()) );
}

void Graficador::graficar(QApplication &p_app)
{
    resize(pixCol, pixFil);
    show();
    p_app.exec();
}

void Graficador::setVelocidad_ms(unsigned dt)
{
    deltaT = dt;
}

Graficador::~Graficador()
{
    delete cronometro;
}

void Graficador::initializeGL()
{
    glClearColor(0, 0, 0, 0);
}

void Graficador::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0f, miMundo->getColumnas(), miMundo->getFilas(), 0.0f, -1.0f, 1.0f);

    glMatrixMode( GL_MODELVIEW ); // y tenemos la matriz de textura, que no usamos
    glLoadIdentity();
}

void Graficador::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f(0, 1, 0);
    float k = 1; //resolucion;

    glBegin(GL_QUADS); {
        for (unsigned i=0; i < miMundo->getFilas(); ++i) {
            for (unsigned j=0; j < miMundo->getColumnas(); ++j) {
                if ( miMundo->celula(i, j).estaVivo() ) {
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

void Graficador::mousePressEvent(QMouseEvent *qme)
{
    int x = 1.f*qme->x()/pixCol * miMundo->getColumnas();
    int y = 1.f*qme->y()/pixFil * miMundo->getFilas()   ;

    miMundo->cambiarEstado(y,x);
    repaint();
}

void Graficador::keyPressEvent(QKeyEvent *qke)
{
    if ( qke->key() == 32)
        motion = !motion;
    if ( qke->key() == Qt::Key_Right)
        deltaT /= 2;
    if ( qke->key() == Qt::Key_Left)
        deltaT *= 2;
    if ( qke->key() == 75){
        miMundo->killAll();
        repaint();
    }
    if ( qke->key() == 70)
        close();
}

void Graficador::animar()
{
    if (motion) {
        miMundo->avanzarEpoca();
        repaint();
    }
    cronometro->start(deltaT);
}

