#ifndef CERCHIO_H
#define CERCHIO_H
#include "punto.h"
#include "poligono.h"
#include "figura.h"
#include <cmath>
#define _USE_MATH_DEFINES

class Cerchio: public Figura{
    private:
        Punto centro;
        double raggio;
        static unsigned int idCerchio;
    public:
        Cerchio(double, double, double);
        Punto getCentro() const;
        double perimetro() const;
        double area() const;
        virtual double distanza (Figura*) const;
        string print() const;
        virtual ~Cerchio();
};

#endif // CERCHIO_H
