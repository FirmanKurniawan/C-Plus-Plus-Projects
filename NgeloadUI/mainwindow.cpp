#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    processSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QUiLoader ui_loader;
    QFile fl(":/ui_file/components/calc.ui");
    fl.open(QFile::ReadOnly);

    widCalc = ui_loader.load(&fl, this);
    fl.close();

//    grid_layout = new QGridLayout(this);
//    grid_layout->addWidget(widCalc);
//    setLayout(grid_layout);
    ui->gridLayout->addWidget(widCalc);
}

void MainWindow::processSignals()
{
    qDebug() << Q_FUNC_INFO << "masuk";
    QList<QObject*> listObjs = ui->gridLayout->findChildren<QObject*>();
    foreach(auto item, listObjs){
        QString txt = item->objectName();
        qDebug() << Q_FUNC_INFO << txt;

    }


}

void MainWindow::processCalcCommand(QString cmd)
{
    qDebug() << Q_FUNC_INFO << cmd;
}

