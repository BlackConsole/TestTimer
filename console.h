#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#include "consolecontrol.h"


class Console : public QObject
{
    Q_OBJECT

private:
    ConsoleControl *fCC;
    int ConsoleMode;
    void hello_scr();

public:
    explicit Console(QObject *parent = 0);
    ~Console();
    void execut();
signals:
    void finished();

public slots:

    void process();
    void stop();

};

#endif // CONSOLE_H
