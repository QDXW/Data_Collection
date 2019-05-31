#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>

namespace Ui {
class Interface;
}

enum INTERFACE_DIASPLAY{
    DISPLAY_REALY,				/* 睿丽图标 */
    DISPLAY_PROTZEK,			/* 德国 */
    DISPLAY_HENGRUI,			/* 恒睿 */
    DISPLAY_ULTIMED,			/* Ultimed */
    DISPLAY_QUICKSEAL,			/* 捷克图标 */

    DISPLAY_INTERFACE,
};

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private slots:
    void on_Interface_Realy_clicked();

    void on_Interface_Protzek_clicked();

    void on_Interface_Hengrui_clicked();

    void on_Interface_Ultimed_clicked();

    void on_Interface_Quickseal_clicked();

signals:
    void ChangeInterfaceSingal(quint8);

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
