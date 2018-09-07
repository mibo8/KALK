#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(VettoreFigure* vf, QWidget *parent) :vf(vf), QMainWindow(parent), ui(new Ui::MainWindow){
    //gestione mainwindow con relativi segnali e slot
    ui->setupUi(this);
    setGeometry(250,130,800,500);
    QWidget* w=new QWidget();
    layout=new QGridLayout();
    setCentralWidget(w);
    setWindowTitle("Kalk");
    w->setLayout(layout);
    scene=new ScenaPianoCartesiano();
    view=new QGraphicsView(scene);
    view->setGeometry(0,0,400,400);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    list=new QListWidget(this);
    list->setContextMenuPolicy(Qt::CustomContextMenu);
    list->setSelectionMode(QAbstractItemView::SingleSelection);
    risultato=new Risultato();
    toolbar=new QToolBar();
    info=new QLabel();
    info->setStyleSheet("QLabel { background-color : #DCDCDC; color : black; }");
    QAction* segmento=new QAction("Segmento", this);toolbar->addAction(segmento);toolbar->addSeparator();
    QAction* triangolo=new QAction("Triangolo", this);toolbar->addAction(triangolo);toolbar->addSeparator();
    QAction* rettangolo=new QAction("Rettangolo", this);toolbar->addAction(rettangolo);toolbar->addSeparator();
    QAction* cerchio=new QAction("Cerchio", this);toolbar->addAction(cerchio);
    connect(segmento, SIGNAL(triggered()), this, SLOT(onClickSegmento()));
    connect(rettangolo, SIGNAL(triggered()), this, SLOT(onClickRettangolo()));
    connect(cerchio, SIGNAL(triggered()), this, SLOT(OnClickCerchio()));
    connect(triangolo, SIGNAL(triggered()), this, SLOT(onClickTriangolo()));
    connect(list,SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(onClickList(QListWidgetItem*)));
    connect(list,SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(mostraContextMenu(QPoint)));
    layout->addWidget(view,2,3,9,8);
    layout->addWidget(list,2,1,6,2);
    layout->addWidget(info,8,1,1,2);
    layout->addWidget(risultato,9,1,3,2);
    layout->addWidget(toolbar,1,1,1,10);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete layout;
    delete scene;
    delete view;
    delete list;
    delete risultato;
    delete toolbar;
    delete info;
}
//metodo relativo al click del bottone "Segmento" nella toolbar
void MainWindow::onClickSegmento(){
    aggiungiSegmento=new QDialog(this);
    aggiungiSegmento->setWindowTitle("Aggiungi Segmento");
    QGridLayout* layoutaggiungi=new QGridLayout(aggiungiSegmento);
    aggiungiSegmento->setLayout(layoutaggiungi);
    QLabel* punto1=new QLabel("Punto 1: ",aggiungiSegmento);
    layoutaggiungi->addWidget(punto1,1,1,1,1);
    x1=new QLineEdit(aggiungiSegmento);
    layoutaggiungi->addWidget(x1,1,2,1,2);
    y1=new QLineEdit(aggiungiSegmento);
    layoutaggiungi->addWidget(y1,1,4,1,2);
    QLabel* punto2=new QLabel("Punto 2: ",aggiungiSegmento);
    layoutaggiungi->addWidget(punto2,2,1,1,1);
    x2=new QLineEdit(aggiungiSegmento);
    layoutaggiungi->addWidget(x2,2,2,1,2);
    y2=new QLineEdit(aggiungiSegmento);
    layoutaggiungi->addWidget(y2,2,4,1,2);
    QPushButton* p=new QPushButton("Aggiungi",aggiungiSegmento);
    layoutaggiungi->addWidget(p,3,3,1,2);
    connect(p,SIGNAL(clicked()),this,SLOT(onClickAggiungiSegmento()));
    aggiungiSegmento->show();
}
//metodo relativo al click del bottone "Aggiungi" della finestra "aggiungiSegmento"
void MainWindow::onClickAggiungiSegmento(){
    try{
        if(!x1->text().isEmpty() && !y1->text().isEmpty() && !x2->text().isEmpty() && !y2->text().isEmpty()) {
            if(x1->text().toDouble() == x2->text().toDouble() && y1->text().toDouble()==y2->text().toDouble()){
                throw err_punti_uguali();
            }
            else{
                Figura* f= new Segmento(Punto(x1->text().toDouble(),y1->text().toDouble()),Punto(x2->text().toDouble(),y2->text().toDouble()));
                vf->pushFigura(f);
                SegmentoGrafico* l=new SegmentoGrafico(x1->text().toDouble()+500,500-y1->text().toDouble(),x2->text().toDouble()+500,500-y2->text().toDouble());
                scene->addItem(l);
                v.push_back(l);
                QListWidgetItem* i= new FiguraListItem(QString::fromStdString(f->getNome()),f,l);
                list->addItem(i);
                aggiungiSegmento->close();
                scene->update();
                view->update();
            }
        }
        else throw err_campi_vuoti();
    }
    catch(err_campi_vuoti){
        aggiungiSegmento->close();
        QMessageBox::about(this,"Errore", "Non sono stati inseriti tutti i campi");
    }
    catch(err_punti_uguali){
        aggiungiSegmento->close();
        QMessageBox::about(this,"Errore", "I punti inseriti hanno le stesse identiche coordinate");
    }
}
//metodo relativo al click del bottone "Rettangolo" nella toolbar
void MainWindow::onClickRettangolo(){
    aggiungiRettangolo=new QDialog(this);
    aggiungiRettangolo->setWindowTitle("Aggiungi Rettangolo");
    QGridLayout* layoutaggiungi=new QGridLayout(aggiungiRettangolo);
    aggiungiRettangolo->setLayout(layoutaggiungi);
    QLabel* punto1=new QLabel("Punto 1: ",aggiungiRettangolo);
    layoutaggiungi->addWidget(punto1,1,1,1,1);
    x1=new QLineEdit(aggiungiRettangolo);
    layoutaggiungi->addWidget(x1,1,2,1,2);
    y1=new QLineEdit(aggiungiRettangolo);
    layoutaggiungi->addWidget(y1,1,4,1,2);
    QLabel* base=new QLabel("Base: ",aggiungiRettangolo);
    layoutaggiungi->addWidget(base,3,1,1,1);
    w=new QLineEdit(aggiungiRettangolo);
    layoutaggiungi->addWidget(w,3,2,1,2);
    QLabel* altezza=new QLabel("Altezza: ",aggiungiRettangolo);
    layoutaggiungi->addWidget(altezza,4,1,1,1);
    h=new QLineEdit(aggiungiRettangolo);
    layoutaggiungi->addWidget(h,4,2,1,2);
    QPushButton* p=new QPushButton("Aggiungi",aggiungiRettangolo);
    layoutaggiungi->addWidget(p,5,3,1,2);
    connect(p,SIGNAL(clicked()),this,SLOT(onClickAggiungiRettangolo()));
    aggiungiRettangolo->show();
}
//metodo relativo al click del bottone "Aggiungi" della finestra "aggiungiRettangolo"
void MainWindow::onClickAggiungiRettangolo(){
    try{
        if(!x1->text().isEmpty() && !y1->text().isEmpty() && !w->text().isEmpty() && !h->text().isEmpty()) {
            if(w->text().toDouble()==0 || h->text().toDouble()==0){
                throw err_campo_zero();
            }
            Figura* f = new Rettangolo(w->text().toDouble(),h->text().toDouble(),x1->text().toDouble(), y1->text().toDouble());
            vf->pushFigura(f);
            RettangoloGrafico* r=new RettangoloGrafico(x1->text().toDouble()+500,500-y1->text().toDouble(),w->text().toDouble(),h->text().toDouble());
            scene->addItem(r);
            v.push_back(r);
            QListWidgetItem* i= new FiguraListItem(QString::fromStdString(f->getNome()),f,r);
            list->addItem(i);
            aggiungiRettangolo->close();
            scene->update();
            view->update();
        }
        else throw err_campi_vuoti();
    }
    catch(err_campi_vuoti){
        aggiungiRettangolo->close();
        QMessageBox::about(this,"Errore", "Non sono stati inseriti tutti i campi");
    }
    catch(err_campo_zero){
        aggiungiRettangolo->close();
        QMessageBox::about(this,"Errore", "Base o altezza ha valore 0");
    }
}
//metodo relativo al click del bottone "Cerchio" nella toolbar
void MainWindow::OnClickCerchio(){
    aggiungiCerchio=new QDialog(this);
    aggiungiCerchio->setWindowTitle("Aggiungi Cerchio");
    QGridLayout* layoutaggiungi=new QGridLayout(aggiungiCerchio);
    aggiungiCerchio->setLayout(layoutaggiungi);
    QLabel* punto1=new QLabel("Punto 1: ",aggiungiCerchio);
    layoutaggiungi->addWidget(punto1,1,1,1,1);
    x1=new QLineEdit(aggiungiCerchio);
    layoutaggiungi->addWidget(x1,1,2,1,2);
    y1=new QLineEdit(aggiungiCerchio);
    layoutaggiungi->addWidget(y1,1,4,1,2);
    QLabel* raggio=new QLabel("Raggio: ",aggiungiCerchio);
    layoutaggiungi->addWidget(raggio,2,1,1,1);
    r=new QLineEdit(aggiungiCerchio);
    layoutaggiungi->addWidget(r,2,2,1,2);
    QPushButton* p=new QPushButton("Aggiungi",aggiungiCerchio);
    layoutaggiungi->addWidget(p,3,3,1,2);
    connect(p,SIGNAL(clicked()),this,SLOT(onClickAggiungiCerchio()));
    aggiungiCerchio->show();
}
//metodo relativo al click del bottone "Aggiungi" della finestra "aggiungiCerchio"
void MainWindow::onClickAggiungiCerchio(){
    try{
        if(!x1->text().isEmpty() && !y1->text().isEmpty() && !r->text().isEmpty()){
            if(r->text().toDouble()==0){
                throw err_campo_zero();
            }
            Figura* f= new Cerchio(x1->text().toDouble(), y1->text().toDouble(),r->text().toDouble());
            vf->pushFigura(f);
            CerchioGrafico* c=new CerchioGrafico(500+x1->text().toDouble(),500-y1->text().toDouble(),r->text().toDouble());
            scene->addItem(c);
            v.push_back(c);
            QListWidgetItem* i= new FiguraListItem(QString::fromStdString(f->getNome()),f, c);
            list->addItem(i);
            aggiungiCerchio->close();
            scene->update();
            view->update();
        }
        else throw err_campi_vuoti();
    }
    catch(err_campi_vuoti){
        aggiungiCerchio->close();
        QMessageBox::about(this,"Errore", "Non sono stati inseriti tutti i campi");
    }
    catch(err_campo_zero){
        aggiungiCerchio->close();
        QMessageBox::about(this,"Errore", "Il raggio ha valore 0");
    }
}
//metodo relativo al click del bottone "Triangolo" nella toolbar
void MainWindow::onClickTriangolo(){
    aggiungiTriangolo=new QDialog(this);
    aggiungiTriangolo->setWindowTitle("Aggiungi Segmento");
    QGridLayout* layoutaggiungi=new QGridLayout(aggiungiTriangolo);
    aggiungiTriangolo->setLayout(layoutaggiungi);
    QLabel* punto1=new QLabel("Punto 1: ",aggiungiTriangolo);
    layoutaggiungi->addWidget(punto1,1,1,1,1);
    x1=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(x1,1,2,1,2);
    y1=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(y1,1,4,1,2);
    QLabel* punto2=new QLabel("Punto 2: ",aggiungiTriangolo);
    layoutaggiungi->addWidget(punto2,2,1,1,1);
    x2=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(x2,2,2,1,2);
    y2=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(y2,2,4,1,2);
    QLabel* punto3=new QLabel("Punto 3: ",aggiungiTriangolo);
    layoutaggiungi->addWidget(punto3,3,1,1,1);
    x3=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(x3,3,2,1,2);
    y3=new QLineEdit(aggiungiTriangolo);
    layoutaggiungi->addWidget(y3,3,4,1,2);
    QPushButton* p=new QPushButton("Aggiungi",aggiungiTriangolo);
    layoutaggiungi->addWidget(p,4,3,1,2);
    connect(p,SIGNAL(clicked()),this,SLOT(onClickAggiungiTriangolo()));
    aggiungiTriangolo->show();
}
//metodo relativo al click del bottone "Aggiungi" della finestra "aggiungiTriangolo"
void MainWindow::onClickAggiungiTriangolo(){
    try{
        if(!x1->text().isEmpty() && !y1->text().isEmpty() && !x2->text().isEmpty() && !y2->text().isEmpty() && !x3->text().isEmpty() && !y3->text().isEmpty()){
            if(x1->text().toDouble() == x2->text().toDouble() && y1->text().toDouble()==y2->text().toDouble()){
                throw err_punti_uguali();
            }
            if(x1->text().toDouble() == x3->text().toDouble() && y1->text().toDouble()==y3->text().toDouble()){
                throw err_punti_uguali();
            }
            if(x2->text().toDouble() == x3->text().toDouble() && y2->text().toDouble()==y3->text().toDouble()){
                throw err_punti_uguali();
            }
            Figura* f= new Triangolo(x1->text().toDouble(),y1->text().toDouble(),x2->text().toDouble(),y2->text().toDouble(),x3->text().toDouble(),y3->text().toDouble());
            vf->pushFigura(f);
            TriangoloGrafico* t=new TriangoloGrafico(500+x1->text().toDouble(),500-y1->text().toDouble(),500+x2->text().toDouble(),500-y2->text().toDouble(),500+x3->text().toDouble(),500-y3->text().toDouble());
            scene->addItem(t);
            v.push_back(t);
            QListWidgetItem* i= new FiguraListItem(QString::fromStdString(f->getNome()),f,t);
            list->addItem(i);
            aggiungiTriangolo->close();
            scene->update();
            view->update();
        }
        else throw err_campi_vuoti();
    }
    catch(err_campi_vuoti){
        aggiungiTriangolo->close();
        QMessageBox::about(this,"Errore", "Non sono stati inseriti tutti i campi");
    }
    catch(err_punti_uguali){
        aggiungiTriangolo->close();
        QMessageBox::about(this,"Errore", "I punti inseriti hanno le stesse identiche coordinate");
    }
}
//metodo relativo al click delle figure presenti nella lista
void MainWindow::onClickList(QListWidgetItem* i)const{
    list->setCurrentItem(i);
    QList<QGraphicsItem*> selezionati=scene->selectedItems();
    auto it= selezionati.begin();
    for(it;it!=selezionati.end();it++) (*it)->setSelected(false);
    FiguraListItem* ci= dynamic_cast<FiguraListItem*>(i);
    if(ci){
        ci->getFGrafico()->setSelected(true);
        info->setText(QString::fromStdString(ci->getFModello()->print()));
        scene->update();
        view->update();
    }
}

void MainWindow::mostraContextMenu(const QPoint & pos){
    if(list->itemAt(pos)){
        FiguraListItem* pf= dynamic_cast<FiguraListItem*>(list->itemAt(pos));
        onClickList(pf);
        MenuCalcoli* menu=new MenuCalcoli(scene,vf,pf->getFModello(),risultato,info, list);
        menu->exec(QPoint(QCursor::pos()));
    }
}
