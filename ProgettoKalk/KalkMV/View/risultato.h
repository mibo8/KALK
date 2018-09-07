#ifndef RISULTATO_H
#define RISULTATO_H

#include <QLabel>
#include <QLCDNumber>
#include <QWidget>
#include <iostream>
#include <QVBoxLayout>

//classe utilizzata per visualizzare i risultati delle operazioni
class Risultato:public QWidget{
    Q_OBJECT
private:
    QLabel* titolo;
    QLCDNumber* ris;

public:
    Risultato();
    void setTitolo(QString);
    void setRis(double);
};
#endif // RISULTATO_H

