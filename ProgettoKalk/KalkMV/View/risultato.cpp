#include "View/risultato.h"

using namespace std;
Risultato::Risultato(){
    titolo= new QLabel("Risultato: ");
    QVBoxLayout* layout=new QVBoxLayout(this);
    setLayout(layout);
    layout->addWidget(titolo);
    ris= new QLCDNumber();
    ris->setStyleSheet("QLCDNumber { background-color : #696969; color : white; }");
    ris->setDigitCount(8);
    ris->display(0.0);
    layout->addWidget(ris);
}

void Risultato::setTitolo(QString s){
    titolo->setText(s);
}

void Risultato::setRis(double n){
    ris->display(n);
}
