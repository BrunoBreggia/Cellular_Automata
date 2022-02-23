#include "graficador.h"

Graficador::Graficador(Hormiguero &miHormiguero): hormiguero(miHormiguero)
{
    maxFil = hormiguero.getFilas();
    maxCol = hormiguero.getColumnas();
    motion = false;
    deltaT = 1000;
    cronometro = new QTimer;
    cronometro->start(1000); // 500 milisegundos -> 0.5 seg
    connect( cronometro, SIGNAL(timeout()), this, SLOT(animar()) );
}

void Graficador::graficar(QApplication &p_app)
{
    resize(500, 500);
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
    glOrtho(0.0f, maxCol, 0.0f, maxFil, -1.0f, 1.0f);

    glMatrixMode( GL_MODELVIEW ); // y tenemos la matriz de textura, que no usamos
    glLoadIdentity();
}

void Graficador::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    float k = 1; //resolucion;

    glBegin(GL_QUADS); {
        for (unsigned i=0; i < maxCol; ++i) {
            for (unsigned j=0; j < maxFil; ++j) {
                if (hormiguero.getColor(i,j) == blanco) glColor3f(0,0,0);
                else glColor3f(0.5,0.5,0.5);
                glVertex3f( i*k,     j*k,       0);
                glVertex3f((i+1)*k,  j*k,       0);
                glVertex3f((i+1)*k, (j+1)*k,    0);
                glVertex3f( i*k,    (j+1)*k,    0);
            }
        }

        auto hormigas = hormiguero.getHormigas();
        unsigned i,j;
        glColor3f(1,0.2,0.2);
        Posicion pos;
        for (unsigned a=0; a<hormigas.size(); ++a) {
            pos = hormigas[a].getPosicion();
            i = pos.x;
            j = pos.y;
            glVertex3f( i*k,     j*k,       0);
            glVertex3f((i+1)*k,  j*k,       0);
            glVertex3f((i+1)*k, (j+1)*k,    0);
            glVertex3f( i*k,    (j+1)*k,    0);
        }
    }
    glEnd();
}

void Graficador::mousePressEvent(QMouseEvent *qme)
{
    int x = qme->x()*maxFil/500;
    int y = qme->y()*maxCol/500;

    if( qme->button() == Qt::LeftButton ) {
        hormiguero.cambiarColor(x,maxFil-1-y);
        repaint();
    }
    else if( qme->button() == Qt::RightButton ){
        Hormiga nuevaHormiga(Posicion(x,maxFil-1-y), norte); // por defecto la direccion se elige norte
        hormiguero.agregarHormiga(nuevaHormiga);
        repaint();
    }
}

void Graficador::keyPressEvent(QKeyEvent *qke)
{
    if ( qke->key() == 32)
        motion = !motion;
    else if ( qke->key() == 75){
        hormiguero.quitarHormigas();
        hormiguero.limpiarRastros();
        repaint();
    }
    else if ( qke->key() == 82){
        hormiguero.quitarUltimaHormiga();
        repaint();
    }
    else if ( qke->key() == Qt::Key_Right)
        deltaT /= 2;
    else if ( qke->key() == Qt::Key_Left)
        deltaT *= 2;

}

void Graficador::animar()
{
    if (motion) {
        hormiguero.avanzarEpoca();
        repaint();
        cronometro->start(deltaT);
    }
}
