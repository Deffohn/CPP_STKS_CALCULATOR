#include "mainwindow.hpp"
#include <QApplication>

#include <iostream>
#include "plusoperator.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //plus operator
    PlusOperator plusOperator(1, 2);
    std::cout << plusOperator.execute() << std::endl;

    return a.exec();
}
