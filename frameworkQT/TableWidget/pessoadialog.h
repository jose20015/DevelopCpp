#ifndef PESSOADIALOG_H
#define PESSOADIALOG_H

#include <QDialog>

namespace Ui {
class PessoaDialog;
}

class PessoaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PessoaDialog(QWidget *parent = nullptr);
    ~PessoaDialog();

    //decalaração dos atributos
    QString set_get_nome() const;
    int set_get_idade() const;
    double set_get_salario() const ;


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PessoaDialog *ui;
};

#endif // PESSOADIALOG_H
