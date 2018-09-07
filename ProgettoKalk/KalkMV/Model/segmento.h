#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "punto.h"
#include "figura.h"
#include <cmath>
#include "poligono.h"
#include "cerchio.h"
#include <iostream>

class Segmento: public Figura{
private:
    Punto a;
    Punto b;
    static unsigned int idSegmento;
public:
    Segmento(Punto, Punto b);
    Punto getA()const;
    Punto getB()const;
    double pendenza() const;
    virtual double distanza (Figura*) const;
    double lunghezza() const;
    string print() const;
    virtual ~Segmento();
};

#endif // SEGMENTO_H
