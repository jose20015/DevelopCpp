#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //forma manual de go to slot
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*foorma função com go to slot de fecar janela com */
void MainWindow::on_pushButton_clicked()
{
    close();
    //ou this.close();

}
