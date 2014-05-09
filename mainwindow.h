#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "consolecontrol.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

signals:
  void SayInConsol(QString);
public slots:
  void okClicked()   { emit SayInConsol("Ok!!  :)");}
  void notokClicked(){ emit SayInConsol("NotOk :(");}
  void setCaption(QString arg);
  void SetTime(int);

private:
  Ui::MainWindow *ui;
//  ConsoleControl *consol;
//  QThread consThread;
};

#endif // MAINWINDOW_H
