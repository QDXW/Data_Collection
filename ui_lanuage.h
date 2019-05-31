/********************************************************************************
** Form generated from reading UI file 'lanuage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANUAGE_H
#define UI_LANUAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Lanuage
{
public:
    QPushButton *English;
    QPushButton *Chinese;
    QPushButton *German;
    QPushButton *Protugal;

    void setupUi(QDialog *Lanuage)
    {
        if (Lanuage->objectName().isEmpty())
            Lanuage->setObjectName(QStringLiteral("Lanuage"));
        Lanuage->resize(400, 271);
        English = new QPushButton(Lanuage);
        English->setObjectName(QStringLiteral("English"));
        English->setGeometry(QRect(50, 60, 110, 40));
        English->setMinimumSize(QSize(110, 40));
        English->setMaximumSize(QSize(110, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(16);
        English->setFont(font);
        Chinese = new QPushButton(Lanuage);
        Chinese->setObjectName(QStringLiteral("Chinese"));
        Chinese->setGeometry(QRect(230, 60, 111, 41));
        Chinese->setFont(font);
        German = new QPushButton(Lanuage);
        German->setObjectName(QStringLiteral("German"));
        German->setGeometry(QRect(50, 140, 111, 41));
        German->setFont(font);
        Protugal = new QPushButton(Lanuage);
        Protugal->setObjectName(QStringLiteral("Protugal"));
        Protugal->setGeometry(QRect(230, 140, 111, 41));
        Protugal->setFont(font);

        retranslateUi(Lanuage);

        QMetaObject::connectSlotsByName(Lanuage);
    } // setupUi

    void retranslateUi(QDialog *Lanuage)
    {
        Lanuage->setWindowTitle(QApplication::translate("Lanuage", "Dialog", Q_NULLPTR));
        English->setText(QApplication::translate("Lanuage", "\350\213\261\350\257\255", Q_NULLPTR));
        Chinese->setText(QApplication::translate("Lanuage", "\344\270\255\346\226\207", Q_NULLPTR));
        German->setText(QApplication::translate("Lanuage", "\345\276\267\350\257\255", Q_NULLPTR));
        Protugal->setText(QApplication::translate("Lanuage", "\350\221\241\350\220\204\347\211\231\350\257\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lanuage: public Ui_Lanuage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANUAGE_H
