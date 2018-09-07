#include "segmentografico.h"


using namespace std;
SegmentoGrafico::SegmentoGrafico(double x1, double y1, double x2, double y2):x1(x1), y1(y1), x2(x2), y2(y2){
    setFlag(GraphicsItemFlag::ItemIsSelectable);
}
//definizione metodo virtuale puro della classe QGraphicsItem
QRectF SegmentoGrafico::boundingRect() const{
    QLineF* line= new QLineF(x1,y1,x2,y2);
    qreal selectionOffset=100;
    qreal radAngle=line->angle()*M_PI/180;
    qreal dx = selectionOffset * sin(radAngle);
    qreal dy = selectionOffset * cos(radAngle);
    QPointF offset1 = QPointF(dx,dy);
    QPointF offset2 = QPointF(-dx,-dy);
    return QRectF(line->p1()+ offset1,line->p2() + offset2);
}
//overriding del metodo della classe QGraphicsItem
void SegmentoGrafico::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if(isSelected()){
        painter->setPen(QPen(QBrush(Qt::red),2));
        painter->drawLine(x1,y1,x2,y2);
    }
    else{
        painter->setPen(Qt::black);
        painter->drawLine(x1,y1,x2,y2);
    }

}

