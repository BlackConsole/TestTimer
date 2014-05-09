#ifndef CONSOLECOMMAND_H
#define CONSOLECOMMAND_H
#include <QObject>
#include <QString>
class ConsoleCommand: public QObject
{
  Q_OBJECT
public:
  ConsoleCommand(QObject *parent, QString Desc);
  QString desc;
  void Run(QString arg){emit run(arg);}
signals:
  void run(QString);
};

#endif // CONSOLECOMMAND_H
