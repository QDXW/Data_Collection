/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Password
{
public:
    QLineEdit *User_Label;
    QLineEdit *Password_Label;
    QPushButton *Confirm;
    QPushButton *Cancel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Password)
    {
        if (Password->objectName().isEmpty())
            Password->setObjectName(QStringLiteral("Password"));
        Password->resize(400, 300);
        User_Label = new QLineEdit(Password);
        User_Label->setObjectName(QStringLiteral("User_Label"));
        User_Label->setGeometry(QRect(180, 40, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(20);
        User_Label->setFont(font);
        Password_Label = new QLineEdit(Password);
        Password_Label->setObjectName(QStringLiteral("Password_Label"));
        Password_Label->setGeometry(QRect(180, 120, 171, 51));
        Password_Label->setFont(font);
        Password_Label->setEchoMode(QLineEdit::Password);
        Password_Label->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Confirm = new QPushButton(Password);
        Confirm->setObjectName(QStringLiteral("Confirm"));
        Confirm->setGeometry(QRect(30, 220, 131, 51));
        Confirm->setFont(font);
        Cancel = new QPushButton(Password);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(210, 220, 131, 51));
        Cancel->setFont(font);
        label = new QLabel(Password);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 131, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(18);
        label->setFont(font1);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(Password);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 120, 131, 51));
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Raised);

        retranslateUi(Password);

        QMetaObject::connectSlotsByName(Password);
    } // setupUi

    void retranslateUi(QDialog *Password)
    {
        Password->setWindowTitle(QApplication::translate("Password", "Dialog", Q_NULLPTR));
        User_Label->setText(QApplication::translate("Password", "Admin", Q_NULLPTR));
        Password_Label->setText(QString());
        Confirm->setText(QApplication::translate("Password", "Confirm", Q_NULLPTR));
        Cancel->setText(QApplication::translate("Password", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("Password", "User Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Password", "Password:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Password: public Ui_Password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
