#include "menucalcoli.h"

using namespace std;

MenuCalcoli::MenuCalcoli(ScenaPianoCartesiano* spc, VettoreFigure* vf, Figura* pf, Risultato* ris, QLabel* info,QWidget *parent):QMenu(parent), spc(spc), f(pf), vf(vf), ris(ris),info(info) {
    //in base al click destro nella lista viene eseguito il cast per capire quale tipo di figura è stata selezionata
    if(dynamic_cast<Segmento*>(f)){
        QAction* lunghezza=new QAction("Lunghezza", this);addAction(lunghezza);
        connect(lunghezza,SIGNAL(triggered()),this,SLOT(onClickLunghezza()));
        QAction* pendenza=new QAction("Pendenza", this);addAction(pendenza);
        connect(pendenza,SIGNAL(triggered()),this,SLOT(onClickPendenza()));
        QAction* distanza=new QAction("Distanza", this);addAction(distanza);
        connect(distanza,SIGNAL(triggered()),this,SLOT(onClickDistanza()));
    }
    else if(dynamic_cast<Cerchio*>(f)){
        QAction* perimetroC=new QAction("Perimetro", this);addAction(perimetroC);
        connect(perimetroC,SIGNAL(triggered()),this,SLOT(onClickPerimetroCerchio()));
        QAction* areaC=new QAction("Area", this);addAction(areaC);
        connect(areaC,SIGNAL(triggered()),this,SLOT(onClickAreaCerchio()));
        QAction* distanza=new QAction("Distanza", this);addAction(distanza);
        connect(distanza,SIGNAL(triggered()),this,SLOT(onClickDistanza()));
    }
    else if(dynamic_cast<Poligono*>(f)){
        QAction* perimetroP=new QAction("Perimetro", this);addAction(perimetroP);
        connect(perimetroP,SIGNAL(triggered()),this,SLOT(onClickPerimetroPoligono()));
        QAction* areaP=new QAction("Area", this);addAction(areaP);
        connect(areaP,SIGNAL(triggered()),this,SLOT(onClickAreaPoligono()));
        QAction* distanza=new QAction("Distanza", this);addAction(distanza);
        connect(distanza,SIGNAL(triggered()),this,SLOT(onClickDistanza()));
    }
    addSeparator();
    QAction* elimina=new QAction("Elimina", this);addAction(elimina);
    connect(elimina,SIGNAL(triggered()),this,SLOT(onClickElimina()));
}
//metodo relativo al click dell'azione "Distanza" nella tendina
void MenuCalcoli::onClickDistanza(){
    distanza=new QDialog();
    distanza->setWindowTitle("Distanza");
    distanza->setGeometry(350,230,250,150);
    QGridLayout* layoutdistanza=new QGridLayout(distanza);
    QLabel* label1=new QLabel("Distanza da: ",distanza);
    layoutdistanza->addWidget(label1,1,2,1,1);
    QLabel* figura1=new QLabel(QString::fromStdString(f->getNome()),distanza);
    layoutdistanza->addWidget(figura1,1,3,1,1);
    QLabel* label2=new QLabel("a: ",distanza);
    layoutdistanza->addWidget(label2,2,2,1,1);
    figura2=new QComboBox(distanza);
    vector <Figura*> v= vf->getFigure(f);
    for(auto it=v.begin();it!=v.end();it++){
        figura2->addItem(QString::fromStdString((*it)->getNome()));
    }
    layoutdistanza->addWidget(figura2,2,3,1,2);
    calcola=new QPushButton("Calcola");
    if(v.empty()){
        QLabel* label3=new QLabel("è presente una sola figura nel piano",distanza);
        label3->setStyleSheet("QLabel { color : red; }");
        layoutdistanza->addWidget(label3,3,1,1,3);
        calcola->setEnabled(false);
    }
    connect(calcola,SIGNAL(clicked()),this,SLOT(onClickCalcola()));
    layoutdistanza->addWidget(calcola,4,2,1,2);
    distanza->setLayout(layoutdistanza);
    distanza->show();
}
//metodo relativo al click del bottone "Calcola" della finestra "Distanza"
void MenuCalcoli::onClickCalcola()const{
    Figura* d2=vf->getFiguraByString(figura2->currentText().toStdString());
    ris->setRis(f->distanza(d2));
    distanza->close();
}

//metodo relativo al click dell'azione "Pendenza" nella tendina
void MenuCalcoli::onClickPendenza()const{
    ris->setRis(dynamic_cast<Segmento*>(f)->pendenza());
}
//metodo relativo al click dell'azione "Lunghezza" nella tendina
void MenuCalcoli::onClickLunghezza() const{
    ris->setRis(dynamic_cast<Segmento*>(f)->lunghezza());
}
//metodo relativo al click dell'azione "Perimetro" nella tendina
void MenuCalcoli::onClickPerimetroCerchio() const{
    ris->setRis(dynamic_cast<Cerchio*>(f)->perimetro());
}
//metodo relativo al click dell'azione "Distanza" nella tendina
void MenuCalcoli::onClickAreaCerchio() const{
    ris->setRis(dynamic_cast<Cerchio*>(f)->area());
}
//metodo relativo al click dell'azione "Perimetro" nella tendina
void MenuCalcoli::onClickPerimetroPoligono() const{
    ris->setRis(dynamic_cast<Poligono*>(f)->perimetro());
}
//metodo relativo al click dell'azione "Area" nella tendina
void MenuCalcoli::onClickAreaPoligono() const{
    ris->setRis(dynamic_cast<Poligono*>(f)->area());
}
//metodo relativo al click dell'azione "Elimina" nella tendina
void MenuCalcoli::onClickElimina() const{
    QListWidget* pl= dynamic_cast<QListWidget*>(parent());
        if(pl){
            FiguraListItem* pi = dynamic_cast<FiguraListItem*>(pl->currentItem());
            spc->removeItem(pi->getFGrafico());
            delete pi->getFGrafico();
            spc->update();
            vf->eliminaFigura(f);
            pl->removeItemWidget(pl->currentItem());
            delete pl->currentItem();
            info->setText("");
        }
}

