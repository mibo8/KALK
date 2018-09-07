#include "cerchiografico.h"

using namespace std;

CerchioGrafico::CerchioGrafico(double x, double y, double r):x(x),y(y),r(r){
    setFlag(GraphicsItemFlag::ItemIsSelectable);
}
//definizione metodo virtuale puro della classe QGraphicsItem
QRectF CerchioGrafico::boundingRect() const{
    return QRectF(QPointF(x-r,y-r),QPointF(x-r,y-r));
}
//overriding del metodo della classe QGraphicsItem
void CerchioGrafico::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if(isSelected()){
        painter->setPen(QPen(QBrush(Qt::red),2));
        painter->drawEllipse(QPoint(x,y),r,r);
    }
    else{
        painter->setPen(Qt::black);
        painter->drawEllipse(QPoint(x,y),r,r);
    }
}

