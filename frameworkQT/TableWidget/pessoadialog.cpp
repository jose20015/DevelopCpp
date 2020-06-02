#include "pessoadialog.h"
#include "ui_pessoadialog.h"

PessoaDialog::PessoaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PessoaDialog)
{
    ui->setupUi(this);
}

PessoaDialog::~PessoaDialog()
{
    delete ui;
}

void PessoaDialog::on_buttonBox_accepted()
{
    accept();
}

void PessoaDialog::on_buttonBox_rejected()
{
   reject();
}

//set dos atributos nome, idade, salário
QString PessoaDialog::set_get_nome() const{
    return ui->nome->text();
}
int PessoaDialog::set_get_idade() const{
    return ui->idade->value();
}
double PessoaDialog::set_get_salario() const{
    return ui->salario->value();
}
