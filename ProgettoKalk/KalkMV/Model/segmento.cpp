#include "segmento.h"

#define _USE_MATH_DEFINES

unsigned int Segmento::idSegmento=1;

Segmento::Segmento(Punto pa, Punto pb):Figura("Segmento "+std::to_string(idSegmento)), a(pa), b(pb){
    idSegmento++;
}

Punto Segmento::getA()const{
    return a;
}

Punto Segmento::getB()const{
    return b;
}

double Segmento::pendenza() const{
    if(a.getX()==b.getX()) return 90;
    double rad=atan((b.getY()-a.getY())/(b.getX()-a.getX()));
    return (180.0*rad)/M_PI;
}

double Segmento::lunghezza() const{
    return Punto::distanza(a,b);
}

string Segmento::print() const{
    return "A" + a.print() + "B" + b.print();
}

Segmento::~Segmento()
{

}

double Segmento::distanza (Figura* pf) const {
    double d, d1;
    Segmento* ps = dynamic_cast<Segmento*>(pf);
    if(ps){
        d=Punto::distanza(a,ps->a);
        d1=Punto::distanza(a,ps->b);
        if(d>d1) d=d1;
        d1=Punto::distanza(b,ps->a);
        if(d>d1) d=d1;
        d1=Punto::distanza(b,ps->b);
        if(d>d1) return d1;
        else return d;
    }
    Poligono* pp=dynamic_cast<Poligono*>(pf);
    if(pp){
        Punto pBar= pp->baricentro();
        d=Punto::distanza(a,pBar);
        d1=Punto::distanza(b,pBar);
        if(d>d1) return d1;
        else return d;
    }
    Cerchio* pc=dynamic_cast<Cerchio*>(pf);
    if(pc){
        d=Punto::distanza(a,pc->getCentro());
        d1=Punto::distanza(b,pc->getCentro());
        if(d>d1) return d1;
        else return d;
    }
}

