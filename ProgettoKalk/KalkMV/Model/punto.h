#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>
#include <iostream>
#include <iostream>

using namespace std;

class Punto{
private:
    double x;
    double y;
public:
    Punto();
    Punto(double, double);
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    static double distanza(Punto, Punto);
    string print() const;
};

#endif // PUNTO_H

