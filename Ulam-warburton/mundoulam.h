#ifndef MUNDOULAM_H
#define MUNDOULAM_H
#include "../Microtubules/AutomataCelularBase/mundo.h"

class MundoUlam : public Mundo
{
public:
    MundoUlam(): Mundo(/*tipoDeMundo*/) { }
    void avanzarEpoca() override;
};

#endif // MUNDOULAM_H
