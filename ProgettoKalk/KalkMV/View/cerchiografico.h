#ifndef CIRCLE_H
#define CIRCLE_H
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <QGraphicsTextItem>
#include <QRect>
#include "View/figuralistitem.h"

class CerchioGrafico : public QGraphicsItem
{
private:
    double x,y,r;
public:
    CerchioGrafico(double, double, double);
    QRectF boundingRect() const;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // CIRCLE_H
