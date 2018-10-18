#include "mainwindow.h"
#include <Log/Log.h>
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QString translatorFileName = ":/translations/i18n/Lidar_en.qm";
//    QTranslator *translator = new QTranslator(&a);
//    if (translator->load(translatorFileName))
//    {
//        a.installTranslator(translator);
//    }
    LogInit();
    MainWindow w;
    w.show();
    w.setWindowTitle("RL-A3000");
    return a.exec();
}
