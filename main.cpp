#include "mainwindow.h"
#include <QApplication>
#include <core.h>
#include <iostream>
#include <QThread>
#include "console.h"

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Hello, World" << endl;
    Core a(argc, argv);
    a.cycleStart(1);
    MainWindow w;
    w.show();
//    a.set
//    console cons;
//    QThread tr;
//    cons.moveToThread(&tr);

//    tr.start();
//    cons.run();
    return a.exec();
}
