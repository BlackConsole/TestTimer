#include "core.h"



Core::Core(int argc, char *argv[]) :
    QApplication(argc, argv)
{

//    init cycle
    cycl.id = 0;
    cycl.interval = 0;
    cycl.NStep = 0;
    cycl.stat = false;


    consoleStart();
//    w.show();


}

Core::~Core()
{
    emit consoleStop();
}



void Core::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == cycl.id){
        cycleStep();
    }
}

bool Core::event(QEvent *event)
{
    //if (event->type() == 1)

    return QApplication::event(event);
}

void Core::cycleStep()
{
    cycl.NStep++;

    emit cycleChanged(cycl.NStep);

}

void Core::consoleStart()
{
    Console* term = new Console;
    QThread* thrd = new QThread;
    Lord = term;
    term->moveToThread(thrd);
    connect(thrd,SIGNAL(started()),term,SLOT(process()));
    connect(term,SIGNAL(finished()),thrd,SLOT(quit()));
    connect(this,SIGNAL(consoleStop()),term,SLOT(stop()));
    connect(term,SIGNAL(finished()),term,SLOT(deleteLater()));
    thrd->start();

}



void Core::cycleStart(int interval_time)
{
    cycl.id = startTimer(interval_time);
    cycl.interval = interval_time;
    cycl.stat = true;
    emit cycleStat(true);
}

void Core::cycleStop()
{
    killTimer(cycl.id);
    cycl.id = 0;
    cycl.stat = false;
    emit cycleStat(false);
}

void Core::cycleReset()
{
    cycl.NStep = 0;
}

void Core::cycleGetValue()
{
    emit cycleValue(cycl.NStep);
}

void Core::cycleGetStat()
{
    emit cycleStat(cycl.stat);
}



