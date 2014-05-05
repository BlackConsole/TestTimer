#ifndef CORE_H
#define CORE_H
#include <QtCore>
#include <QApplication>
#include <QDebug>

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
    void timerEvent(QTimerEvent *event);
    bool event(QEvent *event);
    void cycleStep();

public:
    explicit Core(int argc, char *argv[]);

signals:
    void cycleStat(bool);
    void cycleValue(int);

public slots:
    void cycleStart(int t = 0);
    void cycleStop();
    void cycleReset();
    void cycleGetValue();
    void cycleGetStat();

};

#endif // CORE_H
