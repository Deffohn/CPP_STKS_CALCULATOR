#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "typevalue.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayResult(double_error displayedNumber);

private slots:
    void onButtonClicked();
    void onComputeClicked();
    void onRemoveCharClicked();
    void onClearExpressionClicked();
    void toggleReversePolish();

private:
    Ui::MainWindow *ui;
    bool reversePolish = false;
};

#endif // MAINWINDOW_HPP
