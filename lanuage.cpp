#include "lanuage.h"
#include "ui_lanuage.h"

Lanuage::Lanuage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lanuage)
{
    ui->setupUi(this);
    this->setMinimumHeight(270);
    this->setMaximumHeight(270);
    this->setMaximumWidth(400);
    this->setMinimumWidth(400);
    this->setWindowTitle("Lanuage Select");
}

Lanuage::~Lanuage()
{
    delete ui;
}
void Lanuage::myslot(quint8 d)
{
    qDebug()<<d;
}
void Lanuage::on_English_clicked()
{
   emit ChangeLanuageSingal(FONT_DIASPLAY::DISPLAY_FONT_ENGLISH);
   this->close();
}

void Lanuage::on_Chinese_clicked()
{
   emit ChangeLanuageSingal(FONT_DIASPLAY::DISPLAY_FONT_CHINESE);
   this->close();
}

void Lanuage::on_German_clicked()
{
   emit ChangeLanuageSingal(FONT_DIASPLAY::DISPLAY_FONT_GERMAN);
   this->close();
}

void Lanuage::on_Protugal_clicked()
{
   emit ChangeLanuageSingal(FONT_DIASPLAY::DISPLAY_FONT_PROTUGAL);
   this->close();
}
