#include "mainwindow.hpp"
#include <QApplication>

#include <iostream>
#include "plusoperator.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("stksCalculator");

    w.show();
    return a.exec();
}
