#include "poligono.h"

Poligono::Poligono(unsigned int n):Figura("Poligono"),nLati(n), p(0){}

double Poligono::distanza(Figura* pf) const{
    double d, d1;
    Segmento* ps = dynamic_cast<Segmento*>(pf);
    if(ps){
        d=Punto::distanza(baricentro(),ps->getA());
        d1=Punto::distanza(baricentro(),ps->getA());
        if(d<d1) return d;
        else return d1;
    }
    Poligono* pp=dynamic_cast<Poligono*>(pf);
    if(pp){
        d=Punto::distanza(baricentro(),pp->baricentro());
        return d;
    }
    Cerchio* pc=dynamic_cast<Cerchio*>(pf);
    if(pc){
        d=Punto::distanza(baricentro(),pc->getCentro());
        return d;
    }
}


