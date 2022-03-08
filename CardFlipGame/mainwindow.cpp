#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->menu->setAlignment(Qt::AlignHCenter);
    ui->menu->setAlignment(Qt::AlignVCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    gameSetting = new GameSetting(this);
    gameSetting->show();
}

