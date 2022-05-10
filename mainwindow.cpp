#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "result.hpp"

#include <cctype>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->buttonProduct->setText(QString::fromUtf8("\u00D7"));
    ui->buttonDivide->setText(QString::fromUtf8("\u00F7"));
    ui->buttonPow->setText(QString::fromUtf8("x\u207F"));
    ui->buttonSqrt->setText(QString::fromUtf8("\u221A"));

    connect(ui->buttonComa, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonSpace, &QPushButton::released, this, &MainWindow::displayCalculSpaceButton);

    connect(ui->buttonNumber0, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber1, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber2, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber3, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber4, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber5, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber6, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber7, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber8, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonNumber9, &QPushButton::released, this, &MainWindow::onButtonClicked);
    
    connect(ui->buttonAdd, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonSubstract, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonProduct, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonDivide, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonPow, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonSqrt, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonLeftBracket, &QPushButton::released, this, &MainWindow::onButtonClicked);
    connect(ui->buttonRightBracket, &QPushButton::released, this, &MainWindow::onButtonClicked);

    connect(ui->buttonResult, &QPushButton::released, this, &MainWindow::displayCalculOnResultButton);
    connect(ui->buttonRemoveCharacter, &QPushButton::released, this, &MainWindow::displayCalculRemoveOnCharacter);

    connect(ui->buttonPolish, &QPushButton::released, this, &MainWindow::toggleReversePolish);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    auto button_text = qobject_cast<QPushButton*>(sender())->text().toStdString();
    if (button_text == "\u00D7")
        button_text = "*";
    else if (button_text == "\u00F7")
        button_text = "/";
    else if (button_text == "x\u207F")
        button_text = "^";
    else if (button_text == "\u221A") {
        if (reversePolish)
            button_text = "sqrt";
        else
            button_text = "sqrt(";
    }

    if (reversePolish && (button_text[0] == '(' || button_text[0] == ')'))
        return;

    const auto displayed_text = ui->calculDisplay->toPlainText().toStdString();
    if (std::empty(displayed_text)) {
        ui->calculDisplay->setText(QString::fromStdString(button_text));
        return;
    }

    const auto last_ch = displayed_text.back();
    if (std::size(button_text) == 1) {
        auto to_append = std::string{};
        if ((!std::isdigit(last_ch) && last_ch != '.') || (!std::isdigit(button_text[0]) && !std::isspace(button_text[0]) && button_text[0] != '.'))
            to_append.append(" ");

        to_append.append(button_text);
        ui->calculDisplay->setText(ui->calculDisplay->toPlainText().append(QString::fromStdString(to_append)));
        return;
    }

    ui->calculDisplay->setText(ui->calculDisplay->toPlainText().append(QString::fromStdString(std::string{" "}.append(button_text))));
}

void MainWindow::displayResult(double_error result)
{
    ui->resultDisplay->setText(QString{ (result.error) ? "error" : QString::number(result.value) });
}

// ======================================================

void MainWindow::displayCalculOnResultButton()
{
    QString displayed = QString(ui->calculDisplay->toPlainText());
    if (displayed.size() == 0) {
        ui->resultDisplay->setText("");
        return;
    }

    Result res(reversePolish);
    std::string result;
    double_error double_result;
    if (!reversePolish){
        result = res.CleanCalcul(displayed.toStdString());
        double_result = res.Forward(result, 0, result);
    }
    else {
        result = res.CleanReversePolishCalcul(displayed.toStdString());
        double_result = res.ForwardReversePolish(result);
    }
    displayResult(double_result);
    ui->calculDisplay->setText(displayed);
}

void MainWindow::onRemoveCharClicked()
{
    QString displayed = QString(ui->calculDisplay->toPlainText());
    std::string stringDisplayed(displayed.toStdString());
    if (stringDisplayed[stringDisplayed.length() - 1] != '>'){
        displayed.remove(displayed.length() - 1, displayed.length());
    }
    if (stringDisplayed[stringDisplayed.length() - 2] == ' ')
        displayed.remove(displayed.length() - 1, displayed.length());
    ui->calculDisplay->setText(displayed);
}

void MainWindow::onClearExpressionClicked()
{
    ui->calculDisplay->setText("");
    ui->resultDisplay->setText("");
}

void MainWindow::toggleReversePolish()
{
    reversePolish = !reversePolish;
    ui->buttonPolish->setText((reversePolish) ? "Toggle regular calculator" : "Toggle reverse polish");
}
