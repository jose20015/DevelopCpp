#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pessoadialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //preparando a tabela
    QStringList cabecario;
    setWindowTitle("Tabela Pessoa");
    ui->tableWidgetTabelaPessoa->setColumnCount(3);
    cabecario << "Nome" << "Idade" << "Salario";
    ui->tableWidgetTabelaPessoa->setHorizontalHeaderLabels(cabecario);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString nome;
    int idade, resposta, linha;
    double salario;

    PessoaDialog pessoaDialog(this);
    pessoaDialog.setWindowTitle("Adiconar Pessoa");
    resposta = pessoaDialog.exec();

    if(resposta == QDialog::Rejected)return;

    nome = pessoaDialog.set_get_nome();
    idade = pessoaDialog.set_get_idade();
    salario = pessoaDialog.set_get_salario();

    //inserindo uma liinha no final
    ui->tableWidgetTabelaPessoa->insertRow(ui->tableWidgetTabelaPessoa->rowCount());
    linha = ui->tableWidgetTabelaPessoa->rowCount() - 1;
    ui->tableWidgetTabelaPessoa->setItem(linha, Nome, new QTableWidgetItem(nome));
    ui->tableWidgetTabelaPessoa->setItem(linha, Idade, new QTableWidgetItem(QString::number(idade)));
    ui->tableWidgetTabelaPessoa->setItem(linha, Salario, new QTableWidgetItem(QString::number(salario)));

}

