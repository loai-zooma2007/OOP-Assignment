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

    void on_Start_clicked();

    void on_Back_clicked();

    void on_open_clicked();

    void on_Back_2_clicked();

    void on_apply_clicked();

private:
    Ui::MainWindow *ui;
    Image CurrentImage;
};
#endif // MAINWINDOW_H
