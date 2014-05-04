#ifndef CORE_H
#define CORE_H
#include <QtCore>
#include <QApplication>
#include <QDebug>

class Core : public QApplication
{
    Q_OBJECT
private:
    int idTimer;
    int time;
    void timerEvent(QTimerEvent *event);
    bool event(QEvent *event);

public:
    explicit Core(int argc, char *argv[]);

signals:
    void timerStat(bool);
    void timerTime(int);

public slots:
    void timerStart();
    void timerStop();
    void timerReset();
    void timerGetTime();

};

#endif // CORE_H
