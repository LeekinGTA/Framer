#include "mainwindow.h"
#include "stdafx.h"
#include <QDebug>

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

}

MainWindow::~MainWindow()
{

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
    for(int i=0;i<FileList.size();++i)
      ui->listWidget->addItem(FileList.at(i).toLocal8Bit().constData());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->listWidget->currentItem()->setText("remove it");
}
