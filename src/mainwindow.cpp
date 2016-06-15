#include "mainwindow.h"
#include "stdafx.h"
#include <QDebug>

#define TextColor QColor(255,255,255)

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow())
{
  ui->setupUi(this);
  model=new QDirModel(this);
  model->setReadOnly(false);
  model->setSorting(QDir::DirsFirst |QDir::IgnoreCase | QDir::Name);

  ui->treeView->setModel(model);
  //set default file path
#ifdef Q_OS_LINUX
  QModelIndex index=model->index("/home/leekin/");//this path is linux file system
#endif
#ifdef Q_OS_WIN32 || Q_OS_WIN64
  QModelIndex index = model->index("c:/");//default system path
#endif
  ui->treeView->expand(index);
  ui->treeView->scrollTo(index);
  ui->treeView->setCurrentIndex(index);
  ui->treeView->resizeColumnToContents(0);
  image=new QImage();

}

MainWindow::~MainWindow()
{
    delete image;
    delete model;

}


void MainWindow::on_about_triggered()
{
    aboutDialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"WARN!","You would remove all image!!");
}

void MainWindow::on_pushButton_7_clicked()
{
    //QFileInfo fileinfo;
    /**QFileDialog mFileDialog;
    mFileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    mFileDialog.setFileMode(QFileDialog::ExistingFile);
    mFileDialog.setOption(QFileDialog::ReadOnly,true);

    mFileDialog.setWindowTitle(QString("load image"));
    mFileDialog.setDirectory(QString("./"));
    mFileDialog.setNameFilter(QString("ImageFile(*.png *.jpg *.TTF)"));
    imageName=fileinfo.fileName();
    mFileDialog.exec();**/
    FileList=QFileDialog::getOpenFileNames(this,"Loading Image","/home/","ImageFile(*.jpg *.png *.TTF)");
    if(!FileList.empty())
      {
        for(int i=0;i<FileList.size();++i)
          ui->listWidget->addItem(FileList.at(i).toLocal8Bit().constData());
      }
    else
      QMessageBox::warning(this,"warning","No pictures selected!");
}

void MainWindow::on_pushButton_8_clicked()
{
  if(ui->listWidget->currentItem())
    ui->listWidget->currentItem()->setText("Removed!");
}

void MainWindow::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  drawGrid(&painter);
  painter.setPen(Qt::black);
}

void MainWindow::drawGrid(QPainter *painter)
{
  QPoint topLeftPoint(280,90);
  QPoint bottomRightPoint(1300,550);
  QRect rect;
  rect=QRect(topLeftPoint,bottomRightPoint);
          for(int i=0;i<=20;i++)
          {
              int x=rect.left()+(i*(rect.width()-1)/20);
              painter->drawLine(x,rect.top(),x,rect.bottom());
          }
          for(int j=0;j<=10;j++)
          {
              int y=rect.bottom()-(j*(rect.height()-1)/10);
              painter->drawLine(rect.left()-5,y,rect.right(),y);
          }
}
