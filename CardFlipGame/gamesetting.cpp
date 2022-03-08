#include "gamesetting.h"
#include "ui_gamesetting.h"

GameSetting::GameSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSetting)
{
    ui->setupUi(this);
}

GameSetting::~GameSetting()
{
    delete ui;
}

void GameSetting::on_gameStart_clicked()
{
    QString player1Name = ui->lineEdit_p1Name->text();
    QString player2Name = ui->lineEdit_p2Name->text();
    int targetScore = ui->lineEdit_targetScore->text().toInt();
    hide();
    gameWindow = new GameWindow(this, player1Name, player2Name, targetScore);
    gameWindow->show();
}

