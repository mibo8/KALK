#include "punto.h"

Punto::Punto(): x(0), y(0){}

Punto::Punto(double cx, double cy): x(cx), y(cy){}

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    return y;
}

void Punto::setX(double cx){
    x=cx;
}

void Punto::setY(double cy){
    y=cy;
}

double Punto::distanza(Punto p1,Punto p2) {
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

string Punto::print() const
{
    return "("+ std::to_string(int(x))+", "+std::to_string(int(y))+ ") ";
}

