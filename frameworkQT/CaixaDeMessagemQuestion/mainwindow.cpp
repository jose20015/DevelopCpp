#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox::StandardButton resposta = QMessageBox::question(this, "", "Deseja fechar programa ?", QMessageBox::Yes| QMessageBox::No);

    if( resposta == QMessageBox::Yes){
        //encerra aplicação
        QApplication::quit();
        /* ou  dessa forma da no mesmo*/
         //close();
    }
    else {
        QMessageBox::about(this, "", "Programa nã foi fechado");
    }

}
