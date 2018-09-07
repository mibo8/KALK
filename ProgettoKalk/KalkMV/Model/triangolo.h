#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "poligono.h"

class Triangolo: public Poligono {
private:
    static unsigned int idTriangolo;
public:
    Triangolo(double, double, double, double);
    Triangolo(double, double, double, double, double, double);
    virtual double perimetro() const;
    virtual double area() const;
    virtual Triangolo* clona() const;
    virtual Punto baricentro() const;
    string print() const;
    virtual ~Triangolo();
};

#endif // TRIANGOLO_H
