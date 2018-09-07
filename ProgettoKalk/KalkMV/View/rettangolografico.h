#ifndef RECT_H
#define RECT_H
#include <QGraphicsTextItem>
#include <QPainter>
#include <iostream>
#include <QGraphicsTextItem>
#include <QRect>

class RettangoloGrafico : public QGraphicsItem
{
private:
    double x1,y1,w,h;
public:
    RettangoloGrafico(double, double, double, double);
    QRectF boundingRect() const;
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // RECT_H
