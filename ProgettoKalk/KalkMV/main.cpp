#include "View/mainwindow.h"
#include <QApplication>
#include "Model/vettorefigure.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VettoreFigure* vf= new VettoreFigure();
    MainWindow w(vf);
    w.show();
    return a.exec();
}
