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

//Caixa de Mensagem About da bibloteca QMessageBox
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this, "About", "Caixa de Texto About");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this, "Caixa de texto AboutQt");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::critical(this, "Critical", "Caixa de mensagem Critical");
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Information", "Caixa de mensagem informatio");
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::question(this, "Question","Você gostou das caixas de mensagens ?");
}

void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::warning(this, "Worning", "Caixa de mensagem worning");
}
