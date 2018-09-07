#include "rettangolografico.h"

using namespace std;

RettangoloGrafico::RettangoloGrafico(double x1, double y1, double w, double h) : x1(x1), y1(y1), w(w), h(h){
    setFlag(GraphicsItemFlag::ItemIsSelectable);
}
//definizione metodo virtuale puro della classe QGraphicsItem
QRectF RettangoloGrafico::boundingRect() const{
    return QRectF(x1,y1,w,h);
}
//overriding del metodo della classe QGraphicsItem
void RettangoloGrafico::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if(isSelected()){
        painter->setPen(QPen(QBrush(Qt::red),2));
        painter->drawRect(x1,y1,w,h);
    }
    else{
        painter->setPen(Qt::black);
        painter->drawRect(x1,y1,w,h);
    }
}
