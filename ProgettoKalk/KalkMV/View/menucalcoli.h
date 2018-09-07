#ifndef MENUCALCOLI_H
#define MENUCALCOLI_H
#include <QMenu>
#include <QObject>
#include "Model/figura.h"
#include "Model/cerchio.h"
#include "Model/segmento.h"
#include "Model/poligono.h"
#include "Model/vettorefigure.h"
#include "risultato.h"
#include "scenapianocartesiano.h"
#include <QComboBox>
#include <QPushButton>
#include <QObject>
#include <QDialog>
#include "mainwindow.h"

class MenuCalcoli: public QMenu{
    Q_OBJECT
private:
    Figura* f;
    QDialog* distanza;
    ScenaPianoCartesiano* spc;
    VettoreFigure* vf;
    Risultato*  ris;
    QLabel* info;
    QComboBox* figura2;
    QPushButton* calcola;
public:
    MenuCalcoli(ScenaPianoCartesiano*, VettoreFigure*,Figura*,Risultato*,QLabel*, QWidget * = nullptr);
public slots:
    void onClickDistanza();
    void onClickCalcola()const;
    void onClickLunghezza() const;
    void onClickPendenza() const;
    void onClickPerimetroCerchio() const;
    void onClickAreaCerchio() const;
    void onClickPerimetroPoligono() const;
    void onClickAreaPoligono() const;
    void onClickElimina() const;
};

#endif // MENUCALCOLI_H
