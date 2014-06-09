#ifndef CORE_H
#define CORE_H
#include <QtCore>
#include <QApplication>
#include <QDebug>
#include <QThread>
#include "mainwindow.h"
#include "consolecontrol.h"
#include "console.h"
//apt-get install libncurses5 libncurses5-dev  for include ncurses.h
//http://habrahabr.ru/post/150274/   about using QThread

struct CoreCycle{
    int id;
    int NStep;
    int interval;
    bool stat;
};



class Core : public QApplication
{
    Q_OBJECT
private:
    CoreCycle cycl;
    Console *Lord;
    void timerEvent(QTimerEvent *event);
    bool event(QEvent *event);
    void cycleStep();
    void consoleStart();




//    QTextStream s_in;
//    QTextStream s_out;

public:
    explicit Core(int argc, char *argv[]);
    ~Core();

    MainWindow w;

//    ConsoleControl terminal;

signals:
    void cycleStat(bool);
    void cycleValue(int);
    void cycleChanged(int);
    void consoleStop();

public slots:
    void cycleStart(int t = 0);
    void cycleStop();
    void cycleReset();
    void cycleGetValue();
    void cycleGetStat();

};

#endif // CORE_H
