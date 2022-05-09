#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "result.hpp"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonComa, &QPushButton::released, this, &MainWindow::displayCalculOnComaButton);
    connect(ui->buttonNumber0, &QPushButton::released, this, &MainWindow::displayCalculOnNumber0Button);
    connect(ui->buttonNumber1, &QPushButton::released, this, &MainWindow::displayCalculOnNumber1Button);
    connect(ui->buttonNumber2, &QPushButton::released, this, &MainWindow::displayCalculOnNumber2Button);
    connect(ui->buttonNumber3, &QPushButton::released, this, &MainWindow::displayCalculOnNumber3Button);
    connect(ui->buttonNumber4, &QPushButton::released, this, &MainWindow::displayCalculOnNumber4Button);
    connect(ui->buttonNumber5, &QPushButton::released, this, &MainWindow::displayCalculOnNumber5Button);
    connect(ui->buttonNumber6, &QPushButton::released, this, &MainWindow::displayCalculOnNumber6Button);
    connect(ui->buttonNumber7, &QPushButton::released, this, &MainWindow::displayCalculOnNumber7Button);
    connect(ui->buttonNumber8, &QPushButton::released, this, &MainWindow::displayCalculOnNumber8Button);
    connect(ui->buttonNumber9, &QPushButton::released, this, &MainWindow::displayCalculOnNumber9Button);

    connect(ui->buttonAdd, &QPushButton::released, this, &MainWindow::displayCalculOnAddButton);
    connect(ui->buttonSubstract, &QPushButton::released, this, &MainWindow::displayCalculOnSubstractButton);
    connect(ui->buttonProduct, &QPushButton::released, this, &MainWindow::displayCalculOnProductButton);
    connect(ui->buttonDivide, &QPushButton::released, this, &MainWindow::displayCalculOnDivideButton);

    connect(ui->buttonLeftBracket, &QPushButton::released, this, &MainWindow::displayCalculOnLeftBracketButton);
    connect(ui->buttonRightBracket, &QPushButton::released, this, &MainWindow::displayCalculOnRightBracketButton);

    connect(ui->buttonResult, &QPushButton::released, this, &MainWindow::displayCalculOnResultButton);
    connect(ui->buttonRemoveCharacter, &QPushButton::released, this, &MainWindow::displayCalculRemoveOnCharacter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayCalculOnComaButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9)) ){
        displayed.append(" ");
    }
    displayed.append(".");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber0Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("0");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber1Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("1");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber2Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("2");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber3Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("3");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber4Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("4");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber5Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("5");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber6Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("6");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber7Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("7");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber8Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("8");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnNumber9Button()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0 or (48 /*ASCII char '0'*/ + 0 <= displayed.toStdString()[displayed.toStdString().length() - 1] and displayed.toStdString()[displayed.toStdString().length() - 1] <= 48 + 9) or '.' == displayed.toStdString()[displayed.toStdString().length() - 1])){
        displayed.append(" ");
    }
    displayed.append("9");
    ui->calculDisplay->setText(displayed);
}

// ======================================================

void MainWindow::displayCalculOnAddButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("+");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnSubstractButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("-");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnProductButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("*");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnDivideButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("/");
    ui->calculDisplay->setText(displayed);
}

// ======================================================

void MainWindow::displayCalculOnLeftBracketButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("(");
    ui->calculDisplay->setText(displayed);
}

void MainWindow::displayCalculOnRightBracketButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append(")");
    ui->calculDisplay->setText(displayed);
}

// ======================================================

void MainWindow::displayCalculOnResultButton()
{
    QString displayed = QString(ui->calculDisplay->text());
    //Result result;
    //std::string rft = result.CleanCalcul(displayed.toStdString());
    if (!(displayed.toStdString().length() == 0)){
        displayed.append(" ");
    }
    displayed.append("=");
    displayed.append(" ");
    ui->calculDisplay->setText(displayed);
}


void MainWindow::displayCalculRemoveOnCharacter(){


    QString displayed = QString(ui->calculDisplay->text());
    std::string stringDisplayed(displayed.toStdString());
    if (stringDisplayed[stringDisplayed.length() - 1] != '>'){
        displayed.remove(displayed.length() - 1, displayed.length());
    }
    if (stringDisplayed[stringDisplayed.length() - 2] == ' ')
        displayed.remove(displayed.length() - 1, displayed.length());
    ui->calculDisplay->setText(displayed);
}

