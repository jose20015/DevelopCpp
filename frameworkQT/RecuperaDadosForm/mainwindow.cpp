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

void MainWindow::on_BtnMostrar_clicked()
{
    QString nome = ui->TextNome->text();
    QString telefone = ui->TextNome->text();
    QString email = ui->TextEmail->text();

    QMessageBox::information(this, "Dados digitados", "Nome: "+nome+"\nTelefone: "+telefone+"\nEmail: "+email);
}

void MainWindow::on_BtnLimpar_clicked()
{

    //limpar os Texts
    ui->TextNome->clear();
    ui->TextEmail->clear();
    ui->TextTelefone->clear();

    //colocando o foco no imput TextNome
    ui->TextNome->setFocus();

}
