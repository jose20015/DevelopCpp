#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString css = "color: #240480";
    ui->label->setStyleSheet(css);
    ui->label->setText("Hello Word!");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString css = "color: #8155FF";
    ui->label->setStyleSheet(css);
    ui->label->setText("Seu primeiro Programa no Framework QT");
}
