#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QImage>
#include <QDir>
#include <QMenu>
#include "Filter.h"
#include <QAction>
#include <QPoint>
#include <QInputDialog>
#include <QStringList>

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
    QString filePath = QFileDialog::getOpenFileName(this,"Choose Image",QDir::homePath(),"Images(*.png *.jpg *.jpeg *.bmp *.tga)");
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


void MainWindow::on_apply_clicked()
{
    QMenu menu(this);
    QAction *grayAction = menu.addAction("Gray Scale");
    QAction *blckWhtAction = menu.addAction("Black & White");
    QAction *invertAction = menu.addAction("Invert");
    QAction *framAction = menu.addAction("Fram");
    QAction *flipAction = menu.addAction("Flip");
    QAction *rotateAction = menu.addAction("Rotate");
    QAction *drkLghtAction = menu.addAction("Darken & lighten");
    QAction *resizeAction = menu.addAction("Resize");
    QAction *mergeAction = menu.addAction("Merge");
    QAction *edgDtctAction = menu.addAction("Edge Detection");
    QAction *cropAction = menu.addAction("Crop");
    QAction *blurAction = menu.addAction("Blur");
    QAction *sunLghtAction = menu.addAction("Sun Light");
    QAction *tvAction = menu.addAction("DenDenMushi");
    QAction *prplNghtAction = menu.addAction("Purple Night");
    QAction *infraredAction = menu.addAction("Infrared");
    QAction *skewAction = menu.addAction("Skew");
    QAction *oilPntAction = menu.addAction("Oil Paint");

    QAction *selected = menu.exec(ui->apply->mapToGlobal(QPoint(0,ui->apply->height())));
    if(selected==grayAction)
    {
        GrayScale(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==blckWhtAction)
    {
        Black_White(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==invertAction)
    {
        Invert(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==framAction)
    {
        QStringList framTypes;
        framTypes <<"Simple"<<"Decorated";

        bool ok;
        QString typeName = QInputDialog::getItem(this,"Frame Setting","Choose Frame type:",framTypes,0,false,&ok);
        if(!ok)return;
        int type = (typeName=="Simple")?1:2;
        QStringList colors;
        if(type==1){colors<<"Red"<<"Green"<<"Blue"<<"White"<<"Black";}
        else{colors<<"Red&White"<<"Red&Black"<<"Green&White"<<"Green&Black"<<"Blue&White"<<"Blue&Black"<<"Black&White"<<"White&Black";}
        QString colorName = QInputDialog::getItem(this,"Frame Setting","Choose Frame color:",colors,0,false,&ok);
        if(!ok)return;
        int option = colors.indexOf(colorName)+1;
        double thickness = QInputDialog::getDouble(this,"Fram Setting","Enter Frame Thickness:",10.0,1.0,100.0,1,&ok);
        if(!ok)return;

        Fram(CurrentImage,type,option,thickness);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==flipAction)
    {

    }
    else if(selected==rotateAction)
    {

    }
    else if(selected==drkLghtAction)
    {

    }
    else if(selected==resizeAction)
    {

    }
    else if(selected==mergeAction)
    {

    }
    else if(selected==edgDtctAction)
    {
        DetectEdges(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==cropAction)
    {

    }
    else if(selected==blurAction)
    {

    }
    else if(selected==sunLghtAction)
    {
        Sunlight(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==tvAction)
    {
        DenDenMushi(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==prplNghtAction)
    {
        PurpleNight(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==infraredAction)
    {
        Infrared(CurrentImage);
        QImage image(CurrentImage.imageData,CurrentImage.width
                     ,CurrentImage.height,CurrentImage.width*CurrentImage.channels,QImage::Format_RGB888);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image.copy()).scaled(ui->imageLabel->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    else if(selected==skewAction)
    {

    }
    else if(selected==oilPntAction)
    {

    }
}

