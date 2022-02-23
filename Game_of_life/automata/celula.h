#ifndef CELULA_H
#define CELULA_H


class Celula
{
public:
    Celula();
    void setVivo();
    void setMuerto();
    bool estaVivo();

private:
    bool estado;

};

#endif // CELULA_H
