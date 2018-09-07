#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <QGraphicsTextItem>

class TriangoloGrafico :public QGraphicsItem
{
private:
        double x1,y1,x2,y2,x3,y3;
public:
    TriangoloGrafico(double,double,double, double,double,double);
    QRectF boundingRect() const;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // TRIANGLE_H
