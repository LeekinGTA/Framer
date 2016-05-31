#include "mainwindow.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow())
{
  ui->setupUi(this);
  //setWindowState(this->windowState() & Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{

}
