#include "graficadorgol.h"

GraficadorGOL::GraficadorGOL(QWidget *p_app) : QOpenGLWidget(p_app)
{
//    app = p_app;
    pixFil = miMundo.getFilas();
    pixCol = miMundo.getColumnas();

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

void GraficadorGOL::graficar(QApplication *app)
{
    resize(pixCol, pixFil);
    show();
    app->exec();
}

void GraficadorGOL::setVelocidad_ms(unsigned dt)
{
    deltaT = dt;
}

GraficadorGOL::~GraficadorGOL()
{
    delete cronometro;
}

void GraficadorGOL::toggleHold()
{
    motion = !motion;
}

void GraficadorGOL::acelerar(float escala)
{
    deltaT *= escala;
}

void GraficadorGOL::limpiarTodo()
{
    miMundo.killAll();
    repaint();
}

void GraficadorGOL::cerrar()
{
    close();
}

void GraficadorGOL::initializeGL()
{
    glClearColor(0, 0, 0, 0);
}

void GraficadorGOL::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0.0f, miMundo.getColumnas(), miMundo.getFilas(), 0.0f, -1.0f, 1.0f);

    glMatrixMode( GL_MODELVIEW ); // y tenemos la matriz de textura, que no usamos
    glLoadIdentity();
}

void GraficadorGOL::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f(0, 1, 0);
    float k = 1; //resolucion;

    glBegin(GL_QUADS); {
        for (unsigned i=0; i < miMundo.getFilas(); ++i) {
            for (unsigned j=0; j < miMundo.getColumnas(); ++j) {
                if ( miMundo.celula(i, j).estaVivo() ) {
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

void GraficadorGOL::mousePressEvent(QMouseEvent *qme)
{
    int x = 1.f*qme->x()/pixCol * miMundo.getColumnas();
    int y = 1.f*qme->y()/pixFil * miMundo.getFilas()   ;

    miMundo.cambiarEstado(y,x);
    repaint();
}

void GraficadorGOL::keyPressEvent(QKeyEvent *qke)
{
    if ( qke->key() == 32)
        toggleHold();
    if ( qke->key() == Qt::Key_Right)
        acelerar(0.5);
    if ( qke->key() == Qt::Key_Left)
        acelerar(2);
    if ( qke->key() == 75)
        limpiarTodo();
    if ( qke->key() == 70)
        cerrar();
}

void GraficadorGOL::animar()
{
    if (motion) {
        miMundo.avanzarEpoca();
        repaint();
    }
    cronometro->start(deltaT);
}

