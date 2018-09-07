#ifndef FIGURALISTITEM_H
#define FIGURALISTITEM_H
#include <QListWidgetItem>
#include "Model/figura.h"
#include <QString>
#include <QGraphicsItem>

class FiguraListItem: public QListWidgetItem{
private:
    Figura* fModello;
    QGraphicsItem* fGrafico;
public:
    FiguraListItem( QString, Figura*, QGraphicsItem*);
    Figura* getFModello() const;
    QGraphicsItem* getFGrafico() const;
};

#endif // FIGURALISTITEM_H
