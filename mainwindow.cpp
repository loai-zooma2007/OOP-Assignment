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

void MainWindow::on_Back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Save_clicked()
{
    QString filePath = QFileDialog::getSaveFileName( this, "Save Image", QDir::homePath() + "/edited_image.png",
                                                    "PNG Image (.png);;JPEG Image (.jpg .jpeg);;BMP Image (.bmp);;TGA Image (.tga)" );

    if (filePath.isEmpty())
        return;

    try
    {
        CurrentImage.saveImage(filePath.toStdString());
        QMessageBox::information(
            this,
            "Saved",
            "Image saved successfully!"
            );
    }
    catch (const std::exception& e)
    {
        QMessageBox::warning(this, "Save Error", e.what());
    }
}

void MainWindow::on_reset_clicked()
{
    CurrentImage = OriginalImage;

    updateImageDisplay();
}

void MainWindow::on_open_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Choose Image",QDir::homePath(),"Images(*.png *.jpg *.jpeg *.bmp *.tga)");
    if(filePath.isEmpty())return;
    try
    {
        CurrentImage.loadNewImage(filePath.toStdString());
        OriginalImage = CurrentImage;

        updateImageDisplay();
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
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Gray Scale", "Please open an image first."); return; }

        GrayScale(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==blckWhtAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Black&White", "Please open an image first."); return; }

        Black_White(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==invertAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Invert", "Please open an image first."); return; }

        Invert(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==framAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Fram", "Please open an image first."); return; }

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
        double thickness = QInputDialog::getDouble(this,"Fram Setting","Enter Frame Thickness:",10.0,1.0,1000.0,1,&ok);
        if(!ok)return;

        Fram(CurrentImage,type,option,thickness);
        updateImageDisplay();
    }
    else if(selected==flipAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Flip", "Please open an image first."); return; }

        QStringList flipTypes;
        flipTypes <<"Horizontal"<<"Vertical";

        bool ok;
        QString typeName = QInputDialog::getItem(this,"Flip Setting","Choose Flip type:",flipTypes,0,false,&ok);
        if(!ok)return;
        int type = (typeName=="Horizontal")?1:2;

        Flip(CurrentImage,type);
        updateImageDisplay();
    }
    else if(selected==rotateAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Rotate", "Please open an image first."); return; }

        QStringList rotationAngle;
        rotationAngle <<"90"<<"180"<<"270";

        bool ok;
        QString angleStr = QInputDialog::getItem(this,"Rotate Setting","Choose Rotation Angle:",rotationAngle,0,false,&ok);
        if(!ok)return;

        int angle = ((rotationAngle.indexOf(angleStr)+1)*90);

        Rotate(CurrentImage,angle);
        updateImageDisplay();
    }
    else if(selected==drkLghtAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Darken&Lighten", "Please open an image first."); return; }

        QStringList drklghtTypes;
        drklghtTypes <<"Darkening"<<"Lighting";

        bool ok;
        QString typeName = QInputDialog::getItem(this,"Darken&Lighten Setting","Choose Option:",drklghtTypes,0,false,&ok);
        if(!ok)return;
        int type =(typeName=="Darkening")?1:2;

        float precent = QInputDialog::getDouble(this,"Darken&Lighten Setting","Enter precentage:",10.0,0.0,100.0,1,&ok);
        if(!ok)return;

        Darken_Lighten(CurrentImage,precent,type);
        updateImageDisplay();

    }
    else if(selected==resizeAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Resize", "Please open an image first."); return; }

        bool okWidth, okHeight;
        int newWidth = QInputDialog::getInt(
            this,
            "Resize Image",
            "Enter new width:",
            CurrentImage.width,
            1,
            10000,
            1,
            &okWidth
            );

        if (!okWidth)
            return;

        int newHeight = QInputDialog::getInt(
            this,
            "Resize Image",
            "Enter new height:",
            CurrentImage.height,
            1,
            10000,
            1,
            &okHeight
            );

        if (!okHeight)
            return;

        Resize(CurrentImage, newWidth, newHeight);
        updateImageDisplay();

    }
    else if(selected==mergeAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Merge", "Please open an image first."); return; }

        Image second;
        QString filePath = QFileDialog::getOpenFileName(this,"Choose Second Image",QDir::homePath(),"Images(*.png *.jpg *.jpeg *.bmp *.tga)");
        if(filePath.isEmpty())return;
        try
        {
             second.loadNewImage(filePath.toStdString());
        }
        catch(const std::exception& e){QMessageBox::warning(this,"Load Error",e.what());}

        Merge(CurrentImage,second);
        updateImageDisplay();
    }
    else if(selected==edgDtctAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Edge Detection", "Please open an image first."); return; }

        DetectEdges(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==cropAction)
    {
         if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Crop", "Please open an image first."); return; }

        bool ok;

        int x = QInputDialog::getInt(
            this, "Crop", "Enter X:",
            0, 0, CurrentImage.width - 1, 1, &ok
            );
        if (!ok) return;

        int y = QInputDialog::getInt(
            this, "Crop", "Enter Y:",
            0, 0, CurrentImage.height - 1, 1, &ok
            );
        if (!ok) return;

        int width = QInputDialog::getInt(
            this, "Crop", "Enter Width:",
            CurrentImage.width - x, 1, CurrentImage.width - x, 1, &ok
            );
        if (!ok) return;

        int height = QInputDialog::getInt(
            this, "Crop", "Enter Height:",
            CurrentImage.height - y, 1, CurrentImage.height - y, 1, &ok
            );
        if (!ok) return;

        Crop(CurrentImage, width, height, x, y);
        updateImageDisplay();

    }
    else if(selected==blurAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Blur", "Please open an image first."); return; }

        bool ok;
        int radius=QInputDialog::getInt(this,"Blur Setting","Enter Blur radius:",5,0,10,1,&ok);
        if(!ok)return;

        Blur(CurrentImage,radius);
        updateImageDisplay();
    }
    else if(selected==sunLghtAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Sun Light", "Please open an image first."); return; }

        bool ok;
        float intensity = QInputDialog::getDouble(this,"Sun Light Setting","Enter Light intensity:",1.0,0.1,3.0,1,&ok);
        if(!ok)return;

        Sunlight(CurrentImage,intensity);
        updateImageDisplay();
    }
    else if(selected==tvAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "DenDenMushi", "Please open an image first."); return; }

        DenDenMushi(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==prplNghtAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Purple Night", "Please open an image first."); return; }

        PurpleNight(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==infraredAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Infrared", "Please open an image first."); return; }

        Infrared(CurrentImage);
        updateImageDisplay();
    }
    else if(selected==skewAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Skew", "Please open an image first."); return; }

        bool ok;
        float angleDgrs = QInputDialog::getDouble(this,"Skew Setting","Enter Skew Angle:",0.0,-89.9,89.9,1,&ok);
        if(!ok)return;

        Skew(CurrentImage,angleDgrs);
        updateImageDisplay();
    }
    else if(selected==oilPntAction)
    {
        if (CurrentImage.width <= 0 || CurrentImage.height <= 0) { QMessageBox::warning(this, "Oil Paint", "Please open an image first."); return; }

        bool ok;
        int radius=QInputDialog::getInt(this,"Oil Paint Setting","Enter Oilp radius:",5,0,10,1,&ok);
        if(!ok)return;

        OilPaint(CurrentImage,radius);
        updateImageDisplay();
    }
}


void MainWindow::on_Edit_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::updateImageDisplay()
{
    QImage image( CurrentImage.imageData, CurrentImage.width, CurrentImage.height, CurrentImage.width * CurrentImage.channels, QImage::Format_RGB888 );
    QPixmap pixmap = QPixmap::fromImage(image.copy());

    if (pixmap.width() > ui->imageLabel->width() ||
        pixmap.height() > ui->imageLabel->height())
    {
        pixmap = pixmap.scaled(
            ui->imageLabel->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );
    }

    ui->imageLabel->setPixmap(pixmap);

    QString details =
        "Dimensions: " + QString::number(CurrentImage.width) +
        " x " + QString::number(CurrentImage.height) + " px\n" +
        "Channels: " + QString::number(CurrentImage.channels);

    ui->ImageDetails->setText(details);
}

