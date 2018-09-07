#ifndef LINE_H
#define LINE_H
#include <QGraphicsTextItem>
#include <QPainter>
#include <iostream>
#include <QLine>
#include <cmath>
#include <QPointF>
#define _USE_MATH_DEFINES

class SegmentoGrafico : public QGraphicsItem
{
private:
    double x1,y1,x2,y2;

public:
    SegmentoGrafico(double, double, double, double);
    QRectF boundingRect() const;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // LINE_H
