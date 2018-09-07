#ifndef VETTOREFIGURE_H
#define VETTOREFIGURE_H

#include <vector>
#include "figura.h"
#include "segmento.h"
#include <iostream>
//Classe collezione di puntatori a figure.
class VettoreFigure
{
private:
    std::vector<Figura*> vFig;
public:
    VettoreFigure();
    void pushFigura(Figura*);
    void eliminaFigura(Figura*);
    vector <Figura*> getFigure(Figura*) const;
    Figura* getFiguraByString(string) const;
};

#endif // VETTOREFIGURE_H
