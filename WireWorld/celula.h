#ifndef CELULA_H
#define CELULA_H

enum state {head=0, tail=1, cable=2, empty=3};

class Celula
{
public:
    Celula(const state st=empty): Estado(st) { }
    state getEstado() const { return Estado; }
    void setEstado(const state st) { Estado = st; }
private:
    state Estado;
};

#endif // CELULA_H
