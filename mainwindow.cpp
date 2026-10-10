#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_Start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_open_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Choose Image","Images(*.png *.jpg *.jpeg *.bmp *.tga)");
    if(filePath.isEmpty())return;
    try
    {
        CurrentImage.loadNewImage(filePath.toStdString());
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);

        ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    catch(const std::exception& e){QMessageBox::warning(this,"Load Error",e.what());}
}

