#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayLcd(double displayedNumber);

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

    void displayCalculOnAddButton();
    void displayCalculOnSubstractButton();
    void displayCalculOnProductButton();
    void displayCalculOnDivideButton();

    void displayCalculOnLeftBracketButton();
    void displayCalculOnRightBracketButton();

    void displayCalculOnResultButton();
    void displayCalculRemoveOnCharacter();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
