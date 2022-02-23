#include "celula.h"

Celula::Celula()
{
    estado = false;
}

void Celula::setVivo()
{
    estado = true;
}

void Celula::setMuerto()
{
    estado = false;
}

bool Celula::estaVivo()
{
    return estado;
}
