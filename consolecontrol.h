#ifndef CONSOLECONTROL_H
#define CONSOLECONTROL_H

#include <QThread>
#include <QTextStream>
#include <QMap>
#include "consolecommand.h"
class ConsoleControl : public QThread
{
  Q_OBJECT
public:
  explicit ConsoleControl(QObject *parent = 0);
  ~ConsoleControl();
  QString Ask(QString what);
  void Loop();
   void run() {StartLoop();}
   ConsoleCommand* Command(QString key){return commands.value(key);}
   ConsoleCommand* AddCommand(QString key, QString desc);
private:
  QTextStream s_in;
  QTextStream s_out;
  QMap<QString,ConsoleCommand*> commands;
  bool loop_running;
  bool ready;
signals:
  void Stopped();
public slots:
  void Flush();
  void StartLoop();
  void StopLoop();
  void Say(QString what);
  void ListCommands();

};

#endif // CONSOLECONTROL_H
