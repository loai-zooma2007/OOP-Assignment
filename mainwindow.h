#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Image_Class.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_Exit_clicked();

    void on_open_clicked();

    void on_Back_2_clicked();

    void on_apply_clicked();

    void on_reset_clicked();

    void on_Save_clicked();

    void on_Edit_clicked();


private:
    Ui::MainWindow *ui;
    Image CurrentImage;
    Image OriginalImage;

    void updateImageDisplay();
};
#endif // MAINWINDOW_H
