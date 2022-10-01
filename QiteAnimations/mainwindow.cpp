#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AnimatedToggle *atog = new AnimatedToggle(this);
    ui->gridLayout->addWidget(atog);

    CustomButton *btn = new CustomButton(this);
    ui->gridLayout->addWidget(btn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

