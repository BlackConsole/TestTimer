#include "mainwindow.h"
#include <QApplication>
#include <core.h>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Hello, World" << endl;
    Core a(argc, argv);
    a.timerStart();
    MainWindow w;
    w.show();

    return a.exec();
}
