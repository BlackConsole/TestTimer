#include "mainwindow.h"
#include <QApplication>
#include <core.h>
#include <iostream>
#include <QThread>
#include "consolecontrol.h"

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Hello, World" << endl;
    Core a(argc, argv);
    a.cycleStart(1);
    MainWindow w;
    w.show();
    //connect for showing
    QObject::connect(&a,SIGNAL(cycleChanged(int)),&w,SLOT(SetTime(int)));
    ConsoleControl consol;
    consol.AddCommand("start","Start cycle");
    consol.AddCommand("stop","Stop cycle");
    consol.AddCommand("reset","Reset cycle");
    consol.AddCommand("write","Set button name");
    consol.start();
    QObject::connect(&w,SIGNAL(SayInConsol(QString)),&consol,SLOT(Say(QString)));
    QObject::connect(consol.Command("write"),SIGNAL(run(QString)),&w,SLOT(setCaption(QString)));
    QObject::connect(consol.Command("exit"), SIGNAL(run(QString)),&a,SLOT(closeAllWindows()));
    //connect timer commands:
    QObject::connect(consol.Command("start"), SIGNAL(run(QString)),&a,SLOT(cycleStart(int)));
    QObject::connect(consol.Command("stop"),  SIGNAL(run(QString)),&a,SLOT(cycleStop()));
    QObject::connect(consol.Command("reset"), SIGNAL(run(QString)),&a,SLOT(cycleReset()));
    return a.exec();
}
