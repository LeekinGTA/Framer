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
  //fileDialog callback
  void on_pushButton_7_clicked();
  //remove listWidget current item
  void on_pushButton_8_clicked();

  void paintEvent(QPaintEvent *e);

  void drawGrid(QPainter *painter);

private:
  Ui::MainWindow *ui;
  QDirModel *model;
  QString imageName;
  QStringList FileList;
  int HlineSpace;//horizontal line spacing
  int VlineSpace;//vertical line spacing
  QImage *image;
  QList<QString> stageQueue;

};

#endif // MAINWINDOW_H
