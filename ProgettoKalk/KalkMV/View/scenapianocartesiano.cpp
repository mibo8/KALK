#include "scenapianocartesiano.h"


ScenaPianoCartesiano::ScenaPianoCartesiano():QGraphicsScene(0,0, 1000, 1000){
    std::vector<QGraphicsItem*> pianoCartesiano;
    pianoCartesiano.push_back( new QGraphicsLineItem(500,0,500,1000));
    pianoCartesiano.push_back( new QGraphicsLineItem(0,500,1000,500));
    pianoCartesiano.push_back(new QGraphicsLineItem(985,510,1000,500));
    pianoCartesiano.push_back( new QGraphicsLineItem(985,490,1000,500));
    pianoCartesiano.push_back( new QGraphicsLineItem(490,15,500,0));
    pianoCartesiano.push_back( new QGraphicsLineItem(510,15,500,0));
    for (int i=25;i<=975;i=i+25){
        pianoCartesiano.push_back( new QGraphicsLineItem(497,i,503,i));
        pianoCartesiano.push_back( new QGraphicsLineItem(i,497,i,503));
    }
    QPen pennaAssi;
    pennaAssi.setWidth(2);
    for(auto i=pianoCartesiano.begin();i!=pianoCartesiano.end();i++){
        dynamic_cast<QGraphicsLineItem*>(*i)->setPen(pennaAssi);
        addItem(*i);

    }

    std::vector<QGraphicsItem*> quadri;
    for (int i=0;i<=1000;i=i+25){
        quadri.push_back( new QGraphicsLineItem(0,i,1000,i));
        quadri.push_back( new QGraphicsLineItem(i,0,i,1000));
    }
    QPen pennaQuadri;
    pennaQuadri.setStyle(Qt::DotLine);
    pennaQuadri.setBrush(Qt::gray);
    for(auto i=quadri.begin();i!=quadri.end();i++){
        dynamic_cast<QGraphicsLineItem*>(*i)->setPen(pennaQuadri);
        addItem(*i);
    }
}
