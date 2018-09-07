#include "cerchio.h"
using namespace std;

unsigned int Cerchio::idCerchio=1;

Cerchio::Cerchio(double x, double y, double r):
    Figura("Cerchio "+std::to_string(idCerchio)),centro(x,y), raggio(r){
    idCerchio++;
}

Punto Cerchio::getCentro() const {
    return centro;
}

double Cerchio::perimetro() const {
    return (M_PI*raggio)*2;
}

double Cerchio::area() const{
    return M_PI*pow(raggio,2);
}

double Cerchio::distanza(Figura* pf) const{
    double d, d1;
    Segmento* ps = dynamic_cast<Segmento*>(pf);
    if(ps){
        d=Punto::distanza(centro,ps->getA());
        d1=Punto::distanza(centro,ps->getB());
        if(d<d1) return d;
        else return d1;
    }
    Poligono* pp=dynamic_cast<Poligono*>(pf);
    if(pp){
        d=Punto::distanza(centro,pp->baricentro());
        return d;
    }
    Cerchio* pc=dynamic_cast<Cerchio*>(pf);
    if(pc){
        d=Punto::distanza(centro,pc->centro);
        return d;
    }
}

string Cerchio::print() const{
    return "Centro: "+ centro.print()+ "\nraggio: " + std::to_string(int(raggio));
}

Cerchio::~Cerchio()
{

}
