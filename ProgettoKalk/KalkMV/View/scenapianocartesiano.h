#ifndef SCENAPIANOCARTESIANO_H
#define SCENAPIANOCARTESIANO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <vector>
#include <QPainter>

//classe che permette la rappresentazione del piano cartesiano
class ScenaPianoCartesiano: public QGraphicsScene{
public:
    ScenaPianoCartesiano();
};

#endif // SCENAPIANOCARTESIANO_H
