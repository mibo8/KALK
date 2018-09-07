#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include "segmento.h"
#include "punto.h"
#include "poligono.h"
#include <cmath>
#include <iostream>

class Rettangolo : public Poligono{
private:
    static unsigned int idRettangolo;
public:

    Rettangolo(double, double, double, double);
    double diagonale() const;
    virtual double perimetro() const;
    virtual double area() const;
    virtual Punto baricentro() const;
    string print() const;
    virtual ~Rettangolo();
};

#endif // RETTANGOLO_H
