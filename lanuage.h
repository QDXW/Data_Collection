#ifndef LANUAGE_H
#define LANUAGE_H

#include <QDialog>
#include<QDebug>

namespace Ui {
class Lanuage;
}

enum FONT_DIASPLAY{
    DISPLAY_FONT_CHINESE,				/* 简体中文 */
    DISPLAY_FONT_ENGLISH,				/* 英语 */
    DISPLAY_FONT_GERMAN,				/* 德语 */
    DISPLAY_FONT_PROTUGAL,				/* 葡萄牙语 */

    DISPLAY_FONT,
};

class Lanuage : public QDialog
{
    Q_OBJECT

public:
    explicit Lanuage(QWidget *parent = 0);
    ~Lanuage();

private slots:

    void on_English_clicked();

    void on_Chinese_clicked();

    void on_German_clicked();

    void on_Protugal_clicked();

    void myslot(quint8);

private:
    Ui::Lanuage *ui;
signals:
    void ChangeLanuageSingal(quint8);
    void ChangeInterfaceSingal(quint8);
};

#endif // LANUAGE_H
