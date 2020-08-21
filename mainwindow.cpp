#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include<QPrinter>
#include<QPrintDialog>
#include<QColorDialog>
#include<QFileDialog>


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


void MainWindow::on_actionOpen_triggered()
{
    //Create File Dialog

    QString filename = QFileDialog::getOpenFileName(this,"Open A File","/home/ss/");
    ui->textEdit->setText(filename);
}


void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this,"About Me","This is info box");
}

void MainWindow::on_actionAbout_Me_triggered()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"test","Emin misiniz?",QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        qDebug()<<"You clicked Yes ";
        QMessageBox::information(this,"sonuç","Evete bastn");
        QApplication::quit();
    }else{
        qDebug()<<"You clicked No man";
        QMessageBox::information(this,"sonuç","no didin");
    }
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("Yazdırma Ekranı");
    if(ui->textEdit->textCursor().hasSelection())dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if(dialog.exec()!=QDialog::Accepted)
    {
        return;
    }



}

void MainWindow::on_actionChange_Font_triggered()
{
   bool ok;

   QFont font = QFontDialog::getFont(&ok, QFont("Helvetica[Cronyx]",12),this);

   if(ok)
   {
       ui->textEdit->setFont(font);
   }
}

void MainWindow::on_actionChange_Color_triggered()
{
    bool ok;

    QColor color = QColorDialog::getColor(Qt::yellow,this);

    if(ok)
    {
        ui->textEdit->setTextColor(color);
    }
}
