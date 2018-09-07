#include "figuralistitem.h"

FiguraListItem::FiguraListItem(QString nome, Figura* pf, QGraphicsItem* f):
    QListWidgetItem(nome), fModello(pf), fGrafico(f){}

Figura* FiguraListItem::getFModello() const{
    return fModello;
}

QGraphicsItem* FiguraListItem::getFGrafico() const{
    return fGrafico;
}
