#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QToolBar>
#include <QDialog>
#include <QPushButton>

#include "Model/vettorefigure.h"
#include "risultato.h"
#include "scenapianocartesiano.h"
#include "segmentografico.h"
#include "rettangolografico.h"
#include "cerchiografico.h"
#include "triangolografico.h"
#include "err_campi_vuoti.h"
#include "figuralistitem.h"
#include "menucalcoli.h"
#include "Model/rettangolo.h"
#include "Model/punto.h"
#include "Model/triangolo.h"
#include "Model/cerchio.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    VettoreFigure* vf;
    QGridLayout* layout;
    ScenaPianoCartesiano* scene;
    QGraphicsView* view;
    QListWidget* list;
    Risultato* risultato;
    QToolBar* toolbar;
    vector <QGraphicsItem*> v;
    QLabel* info;
    QLineEdit* x1;
    QLineEdit* y1;
    QLineEdit* x2;
    QLineEdit* y2;
    QLineEdit* x3;
    QLineEdit* y3;
    QLineEdit* w;
    QLineEdit* h;
    QLineEdit* r;
    QDialog* aggiungiSegmento;
    QDialog* aggiungiRettangolo;
    QDialog* aggiungiCerchio;
    QDialog* aggiungiTriangolo;
public:
    explicit MainWindow(VettoreFigure*, QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
public slots:
    void onClickSegmento();
    void onClickAggiungiSegmento();
    void onClickRettangolo();
    void onClickAggiungiRettangolo();
    void OnClickCerchio();
    void onClickAggiungiCerchio();
    void onClickTriangolo();
    void onClickAggiungiTriangolo();
    void onClickList(QListWidgetItem* )const;
    void mostraContextMenu(const QPoint &);

};

#endif // MAINWINDOW_H
