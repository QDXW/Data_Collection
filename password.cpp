#include "password.h"
#include "ui_password.h"
#include "QDialog.h"
#include "QMessageBox.h"
Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
    ui->User_Label->setFocus();
    this->setMinimumHeight(300);
    this->setMaximumHeight(300);
    this->setMaximumWidth(400);
    this->setMinimumWidth(400);
    this->setWindowTitle("Password");
}

Password::~Password()
{
    delete ui;
}

void Password::on_Confirm_clicked()
{
    if((ui->Password_Label->text() == "void9948312527") && (ui->User_Label->text() == "Administrator"))
    {
        emit QDialog::accept();
    }
    else
    {
        emit QDialog::reject();
        QMessageBox::warning(this,tr("温馨提醒"),tr("用户名或密码错误!"));
    }
}

void Password::on_Cancel_clicked()
{
    emit QDialog::reject();
}

void Password::Clear_Password()
{
    ui->User_Label->setText(tr("Admin"));
    ui->Password_Label->clear();
}
