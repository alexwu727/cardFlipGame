#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
private:
    string name;
    int score;

public:
    Player(string n = "TBD", int s = 0);
    string getName();
    int getScore();
    void addScore(int v);
    int choose();
};

#endif