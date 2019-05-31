#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    this->setWindowTitle("UserInterface Select");
    this->setMinimumHeight(280);
    this->setMaximumHeight(280);
    this->setMaximumWidth(400);
    this->setMinimumWidth(400);
    this->setWindowState(false);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_Interface_Realy_clicked()
{
    emit ChangeInterfaceSingal(INTERFACE_DIASPLAY::DISPLAY_REALY);
    this->close();
}

void Interface::on_Interface_Protzek_clicked()
{
    emit ChangeInterfaceSingal(INTERFACE_DIASPLAY::DISPLAY_PROTZEK);
    this->close();
}

void Interface::on_Interface_Hengrui_clicked()
{
    emit ChangeInterfaceSingal(INTERFACE_DIASPLAY::DISPLAY_HENGRUI);
    this->close();
}

void Interface::on_Interface_Ultimed_clicked()
{
    emit ChangeInterfaceSingal(INTERFACE_DIASPLAY::DISPLAY_ULTIMED);
    this->close();
}

void Interface::on_Interface_Quickseal_clicked()
{
    emit ChangeInterfaceSingal(INTERFACE_DIASPLAY::DISPLAY_QUICKSEAL);
    this->close();
}
