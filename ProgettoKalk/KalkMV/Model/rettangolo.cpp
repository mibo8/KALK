#include "rettangolo.h"

using namespace std;

unsigned int Rettangolo::idRettangolo=1;

Rettangolo::Rettangolo(double base, double altezza, double x, double y):Poligono(4){
    p= new Punto[4];
    p[0]= Punto(x,y);
    p[1]= Punto(x+base,y);
    p[2]= Punto(x+base, y-altezza);
    p[3]= Punto(x,y-altezza);
    setNome("Rettangolo "+std::to_string(idRettangolo));
    idRettangolo++;
}

double Rettangolo::diagonale() const{
    return sqrt(pow(Punto::distanza(p[0],p[1]),2) + pow(Punto::distanza(p[1],p[2]),2));
}

double Rettangolo::perimetro() const{
    return (Punto::distanza(p[0],p[1])+ Punto::distanza(p[1],p[2])) *2;
}

double Rettangolo::area() const{
    return Punto::distanza(p[0],p[1])* Punto::distanza(p[1],p[2]);
}

Punto Rettangolo::baricentro() const {
    double cx, cy;
    cx=(p[0].getX()+p[1].getX())/2;
    cy=(p[0].getY()+p[1].getY())/2;
    return Punto (cx,cy);
}

string Rettangolo::print() const
{
    return "A" + p[0].print() + "B" + p[1].print()+ "\nC" + p[2].print() + "D" + p[3].print();
}

Rettangolo::~Rettangolo()
{

}
