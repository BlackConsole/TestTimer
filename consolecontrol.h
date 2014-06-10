#ifndef CONSOLECONTROL_H
#define CONSOLECONTROL_H

#include <QThread>
#include <QTextStream>
#include <QMap>
#include "consolecommand.h"
class ConsoleControl : public QObject
{
  Q_OBJECT
public:
  explicit ConsoleControl(QObject *parent = 0);
  ~ConsoleControl();


   ConsoleCommand* Command(QString key){return commands.value(key);}
   ConsoleCommand* AddCommand(QString key, QString desc);
   bool ParseLine(QString line);

   QTextStream s_in;
   QTextStream s_out;
private:
  QMap<QString,ConsoleCommand*> commands;
  bool ready;
signals:
  void hasWritten();
  void hasRead();
public slots:
  void Flush();
  void Say(QString what);
  void ParseAll();
  void ListCommands();

};

#endif // CONSOLECONTROL_H
