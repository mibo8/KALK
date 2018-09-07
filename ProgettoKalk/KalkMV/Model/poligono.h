#ifndef POLIGONO_H
#define POLIGONO_H
#include "figura.h"
#include "punto.h"
#include "cerchio.h"
#include "segmento.h"
#include <iostream>

class Poligono:public Figura{
protected:
    const unsigned int nLati;
    Punto* p;
public:

    Poligono(unsigned int);
    virtual double distanza(Figura*)const;
    virtual double perimetro() const =0;
    virtual double area() const =0;
    virtual Punto baricentro() const =0;
    virtual ~Poligono() =default;
};

#endif // POLIGONO_H
