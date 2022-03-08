#ifndef PLAYER_H
#define PLAYER_H
#include <QDialog>
using namespace std;

class Player
{
private:
    QString name;
    int score;

public:
    Player(QString n = "TBD", int s = 0);
    QString getName();
    int getScore();
    void addScore(int v);
    void resetScore();
    int choose();
};

#endif
