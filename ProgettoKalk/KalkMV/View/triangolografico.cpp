#include "triangolografico.h"

using namespace std;
TriangoloGrafico::TriangoloGrafico(double x1, double y1,double x2, double y2,double x3, double y3):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){
    setFlag(GraphicsItemFlag::ItemIsSelectable);
}
//definizionemetodo virtuale puro della classe QGraphicsItem
QRectF TriangoloGrafico::boundingRect() const{
    return QRectF(QPointF(x1,y1),QPointF(x2,y2));
}
//overriding del metodo della classe QGraphicsItem
void TriangoloGrafico::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    QPoint p[3]={ QPoint(x1,y1), QPoint(x2,y2), QPoint(x3,y3)};
    if(isSelected()){
        painter->setPen(QPen(QBrush(Qt::red),2));
        painter->drawPolygon(p,3);
    }
    else{
        painter->setPen(Qt::black);
        painter->drawPolygon(p,3);
    }
}
