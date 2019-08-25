#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    MainWindow w;
    w.show();

    QFile file(":/style.css");
    file.open(QFile::ReadOnly);

    QString style = QLatin1String(file.readAll());

    //a.setStyleSheet(style);
    file.close();

    return a.exec();
}
