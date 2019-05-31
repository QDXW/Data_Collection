/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QPushButton *Interface_Realy;
    QPushButton *Interface_Protzek;
    QPushButton *Interface_Hengrui;
    QPushButton *Interface_Ultimed;
    QPushButton *Interface_Quickseal;

    void setupUi(QDialog *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QStringLiteral("Interface"));
        Interface->resize(400, 280);
        Interface_Realy = new QPushButton(Interface);
        Interface_Realy->setObjectName(QStringLiteral("Interface_Realy"));
        Interface_Realy->setGeometry(QRect(40, 20, 131, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        Interface_Realy->setFont(font);
        Interface_Protzek = new QPushButton(Interface);
        Interface_Protzek->setObjectName(QStringLiteral("Interface_Protzek"));
        Interface_Protzek->setGeometry(QRect(220, 20, 131, 61));
        Interface_Protzek->setFont(font);
        Interface_Hengrui = new QPushButton(Interface);
        Interface_Hengrui->setObjectName(QStringLiteral("Interface_Hengrui"));
        Interface_Hengrui->setGeometry(QRect(40, 110, 131, 61));
        Interface_Hengrui->setFont(font);
        Interface_Ultimed = new QPushButton(Interface);
        Interface_Ultimed->setObjectName(QStringLiteral("Interface_Ultimed"));
        Interface_Ultimed->setGeometry(QRect(220, 110, 131, 61));
        Interface_Ultimed->setFont(font);
        Interface_Quickseal = new QPushButton(Interface);
        Interface_Quickseal->setObjectName(QStringLiteral("Interface_Quickseal"));
        Interface_Quickseal->setGeometry(QRect(40, 200, 130, 60));
        Interface_Quickseal->setMinimumSize(QSize(130, 60));
        Interface_Quickseal->setMaximumSize(QSize(130, 60));
        Interface_Quickseal->setFont(font);

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QDialog *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Dialog", Q_NULLPTR));
        Interface_Realy->setText(QApplication::translate("Interface", "REALY", Q_NULLPTR));
        Interface_Protzek->setText(QApplication::translate("Interface", "PROTZEK", Q_NULLPTR));
        Interface_Hengrui->setText(QApplication::translate("Interface", "HENGRUI", Q_NULLPTR));
        Interface_Ultimed->setText(QApplication::translate("Interface", "ULTIMED", Q_NULLPTR));
        Interface_Quickseal->setText(QApplication::translate("Interface", "QUICKSEAL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
