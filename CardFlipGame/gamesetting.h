#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <QDialog>
#include "gamewindow.h"

namespace Ui {
class GameSetting;
}

class GameSetting : public QDialog
{
    Q_OBJECT

public:
    explicit GameSetting(QWidget *parent = nullptr);
    ~GameSetting();

private slots:
    void on_gameStart_clicked();

private:
    Ui::GameSetting *ui;
    GameWindow *gameWindow;
};

#endif // GAMESETTING_H
