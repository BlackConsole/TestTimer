#include <iostream>
#include <QRegExp>
#include "consolecontrol.h"

ConsoleControl::ConsoleControl(QObject *parent) :
  QObject(parent)/*,s_in(""),s_out("")*/
{
 // Say("Hi!!\n");


  AddCommand("help","List all commands");
  AddCommand("say","Make console say something");
  AddCommand("exit","Quit console");

  connect(commands["help"],SIGNAL(run(QString)),this,SLOT(ListCommands()));
  connect(commands["say"], SIGNAL(run(QString)),this,SLOT(Say(QString)));
//  connect(commands["exit"],SIGNAL(run(QString)),this,SLOT(StopLoop()));

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
  s_out<<what<<"\n";
  s_out.flush();
  emit hasWritten();
}

bool ConsoleControl::ParseLine(QString line){
  if(line.isEmpty())return false;
  QString cmd=line.section(QRegExp("\\s+"),0, 0,QString::SectionSkipEmpty);
  QString arg=line.section(QRegExp("\\s+"),1,-1,QString::SectionSkipEmpty);
  if(commands.contains(cmd))
    commands.value(cmd)->Run(arg);
  else Say("Command \""+cmd+"\" not reconginzed!!!! Panic!\n");

  return true;
}

void ConsoleControl::ParseAll(){
  while(ParseLine(s_in.readLine())){  };
  emit hasRead();
}

ConsoleCommand *ConsoleControl::AddCommand(QString key, QString desc)
{
  commands[key]=new ConsoleCommand(this,desc);
  return commands[key];
}

void ConsoleControl::ListCommands(){
  QMapIterator<QString,ConsoleCommand*> it(commands);
  s_out<<"List of commands:\n";
  while(it.hasNext()){
      it.next();
      s_out<<"\t >"<<it.key()<<":\t";
      s_out<<it.value()->desc<<endl;
    }
  s_out.flush();
}
