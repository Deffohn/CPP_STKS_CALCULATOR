#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <typevalue.hpp>

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
    void displayCalculOnComaButton();
    void displayCalculOnNumber0Button();
    void displayCalculOnNumber1Button();
    void displayCalculOnNumber2Button();
    void displayCalculOnNumber3Button();
    void displayCalculOnNumber4Button();
    void displayCalculOnNumber5Button();
    void displayCalculOnNumber6Button();
    void displayCalculOnNumber7Button();
    void displayCalculOnNumber8Button();
    void displayCalculOnNumber9Button();

    void displayCalculSpaceButton();

    void displayCalculOnAddButton();
    void displayCalculOnSubstractButton();
    void displayCalculOnProductButton();
    void displayCalculOnDivideButton();

    void displayCalculOnPowButton();
    void displayCalculOnSqrtButton();

    void displayCalculOnLeftBracketButton();
    void displayCalculOnRightBracketButton();

    void displayCalculOnResultButton();
    void displayCalculRemoveOnCharacter();

    void toggleReversePolish();

private:
    Ui::MainWindow *ui;
    bool reversePolish = false;
};
#endif // MAINWINDOW_HPP
