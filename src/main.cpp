#include "mainwindow.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
//    QApplication::addLibraryPath(QApplication::applicationFilePath() + QDir::separator() + "plugins");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
