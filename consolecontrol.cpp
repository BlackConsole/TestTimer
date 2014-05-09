#include <iostream>
#include <QRegExp>
#include "consolecontrol.h"

ConsoleControl::ConsoleControl(QObject *parent) :
  QThread(parent),s_in(stdin),s_out(stdout)
{
  loop_running=false;
  Say("Hi!!\n");


  AddCommand("help","List all commands");
  AddCommand("say","Make console say something");
  AddCommand("exit","Quit console");

  connect(commands["help"],SIGNAL(run(QString)),this,SLOT(ListCommands()));
  connect(commands["say"], SIGNAL(run(QString)),this,SLOT(Say(QString)));
  connect(commands["exit"],SIGNAL(run(QString)),this,SLOT(StopLoop()));

//  StartLoop();
}

ConsoleControl::~ConsoleControl(){
  Say("Bye!!\n");
  Flush();
}
void ConsoleControl::Flush(){
  s_out.flush();
  s_in.flush();
}

void ConsoleControl::Say(QString what){
  s_out<<"[[CControl]]:"<<what<<"\n";
  Flush();
}

QString ConsoleControl::Ask(QString what){
  s_out<<what+":";
  Flush();
  QString res=s_in.readLine();
  return res;
}

void ConsoleControl::Loop(){
  Flush();
  QString line = Ask("Enter command [\"help\" for list of commands]");
  if(line.isEmpty())return;
  QString cmd=line.section(QRegExp("\\s+"),0, 0,QString::SectionSkipEmpty);
  QString arg=line.section(QRegExp("\\s+"),1,-1,QString::SectionSkipEmpty);
//  Say("cmd="+cmd+", arg="+arg);
  if(commands.contains(cmd))
    commands.value(cmd)->Run(arg);
  else Say("Command \""+cmd+"\" not reconginzed!!!! Panic!!!!11\n");
  usleep(100);
}

ConsoleCommand *ConsoleControl::AddCommand(QString key, QString desc)
{
  commands[key]=new ConsoleCommand(this,desc);
  return commands[key];
}

void ConsoleControl::StartLoop(){
  loop_running=true;
  while(loop_running) Loop();
//  this->terminate();
}

void ConsoleControl::StopLoop(){
  loop_running=false;
}

void ConsoleControl::ListCommands(){
  QMapIterator<QString,ConsoleCommand*> it(commands);
  while(it.hasNext()){
      it.next();
      s_out<<"\t >"<<it.key()<<":\t";
      s_out<<it.value()->desc<<endl;
    }
}
