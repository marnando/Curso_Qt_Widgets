#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar->addWidget(new QPushButton("Calc"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
