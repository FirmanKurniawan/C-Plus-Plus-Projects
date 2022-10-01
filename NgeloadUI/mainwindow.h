#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QPushButton>
#include <QUiLoader>
#include <QGridLayout>
#include <QMessageBox>
#include <QSignalMapper>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *widCalc;
    QGridLayout *grid_layout;
    QSignalMapper *mapper = new QSignalMapper(this);
    void init();
    void processSignals();
    void processCalcCommand(QString cmd);
};
#endif // MAINWINDOW_H
