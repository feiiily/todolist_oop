#include "mainwindow.h"
#include "test.h"
#include <QApplication>
#include<QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    test t;
    t.show();
    // w.show();
    return a.exec();
}
