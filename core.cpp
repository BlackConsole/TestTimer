#include "core.h"

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
//    qDebug() << "cycle value = " <<  cycl.NStep;
    emit cycleChanged(cycl.NStep);
}

Core::Core(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    cycl.id = 0;
    cycl.interval = 0;
    cycl.NStep = 0;
    cycl.stat = false;
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



