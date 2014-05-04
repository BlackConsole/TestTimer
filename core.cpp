#include "core.h"

void Core::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == idTimer){
        time++;
        qDebug() << time << endl;
    }
}

bool Core::event(QEvent *event)
{
    if (event->type() == 1)
    QApplication::event(event);
}

Core::Core(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    idTimer = 0;
    time = 0;
}

void Core::timerStart()
{
    idTimer = startTimer(1000);
    emit timerStat(true);
}

void Core::timerStop()
{
    QObject::killTimer(idTimer);
    emit timerStat(false);
}

void Core::timerReset()
{
    time = 0;
}

void Core::timerGetTime()
{
    emit timerTime(time);
}



