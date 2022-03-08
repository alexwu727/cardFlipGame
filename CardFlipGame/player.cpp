#include <iostream>
#include "player.h"
using namespace std;

Player::Player(QString n, int s) : name(n), score(s)
{
}
QString Player::getName()
{
    return name;
}
int Player::getScore()
{
    return score;
}
void Player::addScore(int v)
{
    score += v;
}
int Player::choose()
{
    int i;
    cin >> i;
    return i;
}
void Player::resetScore(){
    score = 0;
}
