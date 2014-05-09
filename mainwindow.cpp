#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->okButton,   SIGNAL(clicked()),this,SLOT(   okClicked()));
  connect(ui->notokButton,SIGNAL(clicked()),this,SLOT(notokClicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setCaption(QString arg){
  ui->lineEdit->setText(arg);
}

void MainWindow::SetTime(int val){
  ui->lcdNumber->display(val);
}
