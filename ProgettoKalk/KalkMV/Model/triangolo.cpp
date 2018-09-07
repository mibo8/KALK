#include "triangolo.h"
#include <cmath>

unsigned int Triangolo::idTriangolo=1;

Triangolo::Triangolo(double base, double altezza, double x, double y):Poligono(3){
    p= new Punto[3];
    p[0]= Punto(x,y);
    p[1]= Punto(x+base,y);
    p[2]= Punto(x+base/2, y+altezza);
    setNome("Triangolo "+std::to_string(idTriangolo));
    idTriangolo++;
}
Triangolo::Triangolo(double xa, double ya, double xb, double yb, double xc, double yc):Poligono(3){
    p= new Punto[3];
    p[0]= Punto(xa,ya);
    p[1]= Punto(xb,yb);
    p[2]= Punto(xc,yc);
    setNome("Triangolo "+std::to_string(idTriangolo));
    idTriangolo++;
}


double Triangolo::perimetro() const{
    return (Punto::distanza(p[0],p[1])+ Punto::distanza(p[1],p[2])+ Punto::distanza(p[2],p[0])) ;
}
double Triangolo::area() const{
    return fabs((p[2].getX()-p[0].getX())*(p[1].getY()-p[0].getY())-(p[1].getX()-p[0].getX())*(p[2].getY()-p[0].getY())/2);
}

Punto Triangolo::baricentro() const {
    double cx, cy;
    cx=(p[0].getX()+p[1].getX()+p[2].getX())/3;
    cy=(p[0].getY()+p[1].getY()+p[2].getY())/3;
    return Punto(cx,cy);
}

Triangolo* Triangolo::clona() const {return new Triangolo(*this);}
string Triangolo::print() const
{
    return "A" + p[0].print() + "B" + p[1].print()+ "\nC" + p[2].print();
}

Triangolo::~Triangolo()
{

}
