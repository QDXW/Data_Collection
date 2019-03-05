/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *COMSelectcomboBox;
    QPushButton *Connect_Btn;
    QComboBox *TypeSelctcomboBox;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *NormalMode_Btn;
    QPushButton *DebugMode_Btn;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLineEdit *Set_BorderLine_lineEdit;
    QPushButton *Set_BorderLine_Btn;
    QLineEdit *Read_BorderLine_lineEdit;
    QPushButton *Read_BorderLine_Btn;
    QLabel *Set_Cal_label;
    QPushButton *Set_Cal_Btn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Set_5V;
    QPushButton *WriteIDCard_Btn;
    QPushButton *ReadIDCard_Btn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *WriteRES_Btn;
    QPushButton *ReadRES_Btn;
    QLineEdit *ReadRES_lineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *SetSNandFW_Btn;
    QLineEdit *SNDate_lineEdit;
    QSpinBox *SNNumber_spinBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *LaunchPrinter_Btn;
    QPushButton *ClosePrinter_Btn;
    QPushButton *SetTime_Btn;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *EnglishSet_Btn;
    QPushButton *ChineseSet_Btn;
    QPushButton *JieKe_Btn;
    QTextBrowser *textBrowser;
    QPushButton *Clear_Btn;
    QPushButton *Get_Status_Btn;
    QLabel *Status_Label;
    QPushButton *password;
    QWidget *APP;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QTableView *tableView;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QTableView *C_TLocal_tableView;
    QTableView *C_TRecev_tableView;
    QWidget *page_4;
    QCustomPlot *CurveShow;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QCheckBox *Curver_checkBox;
    QCheckBox *RowDatacheckBox;
    QCheckBox *CandTDatecheckBox;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *SaveBtn;
    QPushButton *ClearBtn;
    QPushButton *ChangeShow;
    QWidget *page_6;
    QGridLayout *gridLayout_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1310, 785);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(17);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 1, 0, 0);
        COMSelectcomboBox = new QComboBox(centralWidget);
        COMSelectcomboBox->setObjectName(QStringLiteral("COMSelectcomboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(COMSelectcomboBox->sizePolicy().hasHeightForWidth());
        COMSelectcomboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(COMSelectcomboBox);

        Connect_Btn = new QPushButton(centralWidget);
        Connect_Btn->setObjectName(QStringLiteral("Connect_Btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Connect_Btn->sizePolicy().hasHeightForWidth());
        Connect_Btn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Connect_Btn);

        TypeSelctcomboBox = new QComboBox(centralWidget);
        TypeSelctcomboBox->setObjectName(QStringLiteral("TypeSelctcomboBox"));
        sizePolicy.setHeightForWidth(TypeSelctcomboBox->sizePolicy().hasHeightForWidth());
        TypeSelctcomboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(TypeSelctcomboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        gridLayout_2 = new QGridLayout(page_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setContentsMargins(-1, -1, -1, 9);
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setIconSize(QSize(33, 15));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_9 = new QVBoxLayout(tab);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 50, 281, 51));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 239, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        NormalMode_Btn = new QPushButton(layoutWidget);
        NormalMode_Btn->setObjectName(QStringLiteral("NormalMode_Btn"));
        NormalMode_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(NormalMode_Btn);

        DebugMode_Btn = new QPushButton(layoutWidget);
        DebugMode_Btn->setObjectName(QStringLiteral("DebugMode_Btn"));
        DebugMode_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(DebugMode_Btn);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_10->addWidget(pushButton);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 291, 251));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        Set_BorderLine_lineEdit = new QLineEdit(groupBox_2);
        Set_BorderLine_lineEdit->setObjectName(QStringLiteral("Set_BorderLine_lineEdit"));
        Set_BorderLine_lineEdit->setGeometry(QRect(101, 161, 71, 20));
        Set_BorderLine_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        Set_BorderLine_Btn = new QPushButton(groupBox_2);
        Set_BorderLine_Btn->setObjectName(QStringLiteral("Set_BorderLine_Btn"));
        Set_BorderLine_Btn->setGeometry(QRect(10, 160, 75, 23));
        Set_BorderLine_Btn->setMaximumSize(QSize(16777215, 16777215));
        Read_BorderLine_lineEdit = new QLineEdit(groupBox_2);
        Read_BorderLine_lineEdit->setObjectName(QStringLiteral("Read_BorderLine_lineEdit"));
        Read_BorderLine_lineEdit->setGeometry(QRect(100, 190, 71, 20));
        Read_BorderLine_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        Read_BorderLine_Btn = new QPushButton(groupBox_2);
        Read_BorderLine_Btn->setObjectName(QStringLiteral("Read_BorderLine_Btn"));
        Read_BorderLine_Btn->setGeometry(QRect(9, 189, 75, 23));
        Read_BorderLine_Btn->setMaximumSize(QSize(16777215, 16777215));
        Set_Cal_label = new QLabel(groupBox_2);
        Set_Cal_label->setObjectName(QStringLiteral("Set_Cal_label"));
        Set_Cal_label->setGeometry(QRect(90, 220, 72, 16));
        sizePolicy.setHeightForWidth(Set_Cal_label->sizePolicy().hasHeightForWidth());
        Set_Cal_label->setSizePolicy(sizePolicy);
        Set_Cal_label->setMaximumSize(QSize(16777215, 16777215));
        Set_Cal_Btn = new QPushButton(groupBox_2);
        Set_Cal_Btn->setObjectName(QStringLiteral("Set_Cal_Btn"));
        Set_Cal_Btn->setGeometry(QRect(9, 220, 75, 23));
        Set_Cal_Btn->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 127, 239, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Set_5V = new QPushButton(layoutWidget1);
        Set_5V->setObjectName(QStringLiteral("Set_5V"));

        horizontalLayout_3->addWidget(Set_5V);

        WriteIDCard_Btn = new QPushButton(layoutWidget1);
        WriteIDCard_Btn->setObjectName(QStringLiteral("WriteIDCard_Btn"));
        WriteIDCard_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(WriteIDCard_Btn);

        ReadIDCard_Btn = new QPushButton(layoutWidget1);
        ReadIDCard_Btn->setObjectName(QStringLiteral("ReadIDCard_Btn"));
        ReadIDCard_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(ReadIDCard_Btn);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 98, 241, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        WriteRES_Btn = new QPushButton(layoutWidget2);
        WriteRES_Btn->setObjectName(QStringLiteral("WriteRES_Btn"));
        WriteRES_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(WriteRES_Btn);

        ReadRES_Btn = new QPushButton(layoutWidget2);
        ReadRES_Btn->setObjectName(QStringLiteral("ReadRES_Btn"));
        ReadRES_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(ReadRES_Btn);

        ReadRES_lineEdit = new QLineEdit(layoutWidget2);
        ReadRES_lineEdit->setObjectName(QStringLiteral("ReadRES_lineEdit"));
        ReadRES_lineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(ReadRES_lineEdit);

        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(12, 68, 211, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        SetSNandFW_Btn = new QPushButton(layoutWidget3);
        SetSNandFW_Btn->setObjectName(QStringLiteral("SetSNandFW_Btn"));
        SetSNandFW_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(SetSNandFW_Btn);

        SNDate_lineEdit = new QLineEdit(layoutWidget3);
        SNDate_lineEdit->setObjectName(QStringLiteral("SNDate_lineEdit"));
        SNDate_lineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(SNDate_lineEdit);

        SNNumber_spinBox = new QSpinBox(layoutWidget3);
        SNNumber_spinBox->setObjectName(QStringLiteral("SNNumber_spinBox"));
        SNNumber_spinBox->setMaximum(999);

        horizontalLayout_5->addWidget(SNNumber_spinBox);

        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(11, 38, 239, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        LaunchPrinter_Btn = new QPushButton(layoutWidget4);
        LaunchPrinter_Btn->setObjectName(QStringLiteral("LaunchPrinter_Btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LaunchPrinter_Btn->sizePolicy().hasHeightForWidth());
        LaunchPrinter_Btn->setSizePolicy(sizePolicy2);
        LaunchPrinter_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(LaunchPrinter_Btn);

        ClosePrinter_Btn = new QPushButton(layoutWidget4);
        ClosePrinter_Btn->setObjectName(QStringLiteral("ClosePrinter_Btn"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ClosePrinter_Btn->sizePolicy().hasHeightForWidth());
        ClosePrinter_Btn->setSizePolicy(sizePolicy3);
        ClosePrinter_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(ClosePrinter_Btn);

        SetTime_Btn = new QPushButton(layoutWidget4);
        SetTime_Btn->setObjectName(QStringLiteral("SetTime_Btn"));
        SetTime_Btn->setMaximumSize(QSize(16777215, 16777215));
        SetTime_Btn->setAutoRepeatDelay(300);

        horizontalLayout_8->addWidget(SetTime_Btn);

        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(11, 9, 239, 25));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        EnglishSet_Btn = new QPushButton(layoutWidget5);
        EnglishSet_Btn->setObjectName(QStringLiteral("EnglishSet_Btn"));
        EnglishSet_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(EnglishSet_Btn);

        ChineseSet_Btn = new QPushButton(layoutWidget5);
        ChineseSet_Btn->setObjectName(QStringLiteral("ChineseSet_Btn"));
        ChineseSet_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(ChineseSet_Btn);

        JieKe_Btn = new QPushButton(layoutWidget5);
        JieKe_Btn->setObjectName(QStringLiteral("JieKe_Btn"));
        JieKe_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(JieKe_Btn);

        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(320, 50, 921, 361));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        textBrowser->setFont(font);
        Clear_Btn = new QPushButton(groupBox);
        Clear_Btn->setObjectName(QStringLiteral("Clear_Btn"));
        Clear_Btn->setGeometry(QRect(1160, 430, 75, 23));
        Clear_Btn->setMaximumSize(QSize(100, 16777215));
        Get_Status_Btn = new QPushButton(groupBox);
        Get_Status_Btn->setObjectName(QStringLiteral("Get_Status_Btn"));
        Get_Status_Btn->setGeometry(QRect(24, 11, 75, 23));
        Get_Status_Btn->setMaximumSize(QSize(16777215, 16777215));
        Status_Label = new QLabel(groupBox);
        Status_Label->setObjectName(QStringLiteral("Status_Label"));
        Status_Label->setGeometry(QRect(105, 12, 64, 16));
        sizePolicy.setHeightForWidth(Status_Label->sizePolicy().hasHeightForWidth());
        Status_Label->setSizePolicy(sizePolicy);
        Status_Label->setMaximumSize(QSize(150, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        Status_Label->setFont(font1);
        password = new QPushButton(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(0, 650, 51, 31));
        password->setAutoDefault(false);
        password->setFlat(true);

        verticalLayout_9->addWidget(groupBox);

        tabWidget->addTab(tab, QString());
        APP = new QWidget();
        APP->setObjectName(QStringLiteral("APP"));
        stackedWidget_2 = new QStackedWidget(APP);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(10, 10, 1241, 631));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        tableView = new QTableView(page_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 20, 1241, 391));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy4);
        tableView->setMinimumSize(QSize(0, 0));
        tableView->setStyleSheet(QLatin1String("alternate-background-color: rgb(200, 200, 200);\n"
"gridline-color: rgb(192, 112, 16);"));
        layoutWidget6 = new QWidget(page_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(0, 430, 1241, 191));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        C_TLocal_tableView = new QTableView(layoutWidget6);
        C_TLocal_tableView->setObjectName(QStringLiteral("C_TLocal_tableView"));
        sizePolicy4.setHeightForWidth(C_TLocal_tableView->sizePolicy().hasHeightForWidth());
        C_TLocal_tableView->setSizePolicy(sizePolicy4);
        C_TLocal_tableView->setMinimumSize(QSize(0, 80));
        C_TLocal_tableView->setStyleSheet(QLatin1String("alternate-background-color: rgb(200, 200, 200);\n"
"gridline-color: rgb(192, 112, 16);"));

        horizontalLayout_7->addWidget(C_TLocal_tableView);

        C_TRecev_tableView = new QTableView(layoutWidget6);
        C_TRecev_tableView->setObjectName(QStringLiteral("C_TRecev_tableView"));
        sizePolicy4.setHeightForWidth(C_TRecev_tableView->sizePolicy().hasHeightForWidth());
        C_TRecev_tableView->setSizePolicy(sizePolicy4);
        C_TRecev_tableView->setMinimumSize(QSize(0, 80));
        C_TRecev_tableView->setStyleSheet(QLatin1String("alternate-background-color: rgb(200, 200, 200);\n"
"gridline-color: rgb(192, 112, 16);"));

        horizontalLayout_7->addWidget(C_TRecev_tableView);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        CurveShow = new QCustomPlot(page_4);
        CurveShow->setObjectName(QStringLiteral("CurveShow"));
        CurveShow->setEnabled(true);
        CurveShow->setGeometry(QRect(20, 10, 1201, 581));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(10);
        sizePolicy5.setHeightForWidth(CurveShow->sizePolicy().hasHeightForWidth());
        CurveShow->setSizePolicy(sizePolicy5);
        CurveShow->setMinimumSize(QSize(0, 0));
        CurveShow->setStyleSheet(QStringLiteral(""));
        stackedWidget_2->addWidget(page_4);
        layoutWidget7 = new QWidget(APP);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(20, 650, 351, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget7);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Curver_checkBox = new QCheckBox(layoutWidget7);
        Curver_checkBox->setObjectName(QStringLiteral("Curver_checkBox"));
        Curver_checkBox->setChecked(true);

        horizontalLayout_2->addWidget(Curver_checkBox);

        RowDatacheckBox = new QCheckBox(layoutWidget7);
        RowDatacheckBox->setObjectName(QStringLiteral("RowDatacheckBox"));
        RowDatacheckBox->setChecked(true);

        horizontalLayout_2->addWidget(RowDatacheckBox);

        CandTDatecheckBox = new QCheckBox(layoutWidget7);
        CandTDatecheckBox->setObjectName(QStringLiteral("CandTDatecheckBox"));
        CandTDatecheckBox->setChecked(true);
        CandTDatecheckBox->setTristate(false);

        horizontalLayout_2->addWidget(CandTDatecheckBox);

        layoutWidget8 = new QWidget(APP);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(1040, 650, 195, 30));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        SaveBtn = new QPushButton(layoutWidget8);
        SaveBtn->setObjectName(QStringLiteral("SaveBtn"));

        horizontalLayout_6->addWidget(SaveBtn);

        ClearBtn = new QPushButton(layoutWidget8);
        ClearBtn->setObjectName(QStringLiteral("ClearBtn"));

        horizontalLayout_6->addWidget(ClearBtn);

        ChangeShow = new QPushButton(APP);
        ChangeShow->setObjectName(QStringLiteral("ChangeShow"));
        ChangeShow->setGeometry(QRect(390, 650, 93, 28));
        tabWidget->addTab(APP, QString());

        gridLayout_2->addWidget(tabWidget, 4, 0, 1, 1);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(page_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(6);
        gridLayout_3->setContentsMargins(7, 6, 1, 9);
        stackedWidget->addWidget(page_6);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        password->setDefault(false);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RL-A2000-Test", Q_NULLPTR));
        Connect_Btn->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        TypeSelctcomboBox->clear();
        TypeSelctcomboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "A3000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "A2000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "S100", Q_NULLPTR)
        );
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        NormalMode_Btn->setText(QApplication::translate("MainWindow", "\346\255\243\345\270\270\346\250\241\345\274\217", Q_NULLPTR));
        DebugMode_Btn->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\346\250\241\345\274\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\260\345\275\225", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        Set_BorderLine_Btn->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\350\276\271\347\225\214\347\272\277", Q_NULLPTR));
        Read_BorderLine_Btn->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\350\276\271\347\225\214\347\272\277", Q_NULLPTR));
        Set_Cal_label->setText(QApplication::translate("MainWindow", "Success/Fail", Q_NULLPTR));
        Set_Cal_Btn->setText(QApplication::translate("MainWindow", "\346\240\241\345\207\206", Q_NULLPTR));
        Set_5V->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\2005V", Q_NULLPTR));
        WriteIDCard_Btn->setText(QApplication::translate("MainWindow", "\345\206\231ID\345\215\241", Q_NULLPTR));
        ReadIDCard_Btn->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226ID\345\215\241", Q_NULLPTR));
        WriteRES_Btn->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256RES", Q_NULLPTR));
        ReadRES_Btn->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226RES", Q_NULLPTR));
        SetSNandFW_Btn->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256SN", Q_NULLPTR));
        LaunchPrinter_Btn->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\211\223\345\215\260\346\234\272", Q_NULLPTR));
        ClosePrinter_Btn->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\223\345\215\260\346\234\272", Q_NULLPTR));
        SetTime_Btn->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        EnglishSet_Btn->setText(QApplication::translate("MainWindow", "\350\213\261\346\226\207", Q_NULLPTR));
        ChineseSet_Btn->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", Q_NULLPTR));
        JieKe_Btn->setText(QApplication::translate("MainWindow", "\346\215\267\345\205\213\350\257\255", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\260\345\256\213\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        Clear_Btn->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", Q_NULLPTR));
        Get_Status_Btn->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\212\266\346\200\201", Q_NULLPTR));
        Status_Label->setText(QApplication::translate("MainWindow", "APP/Boot", Q_NULLPTR));
        password->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "APP", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\345\274\217:", Q_NULLPTR));
        Curver_checkBox->setText(QApplication::translate("MainWindow", "\346\233\262\347\272\277", Q_NULLPTR));
        RowDatacheckBox->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256", Q_NULLPTR));
        CandTDatecheckBox->setText(QApplication::translate("MainWindow", "C&&T", Q_NULLPTR));
        SaveBtn->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        ClearBtn->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        ChangeShow->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(APP), QApplication::translate("MainWindow", "DATA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
