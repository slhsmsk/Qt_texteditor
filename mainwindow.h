#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFontDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_Me_triggered();

    void on_actionPrint_triggered();

    void on_actionChange_Font_triggered();

    void on_actionChange_Color_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
