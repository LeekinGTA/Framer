#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutdialog.h"
#include <QDirModel>
#include "stdafx.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_about_triggered();

  void on_pushButton_2_clicked();

  void on_pushButton_7_clicked();
  //remove listWidget current item
  void on_pushButton_8_clicked();

private:
  Ui::MainWindow *ui;
  QDirModel *model;
  QString imageName;
  QStringList FileList;

};

#endif // MAINWINDOW_H
