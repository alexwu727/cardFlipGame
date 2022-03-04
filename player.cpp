#include <iostream>
#include "player.h"
using namespace std;

Player::Player(string n, int s) : name(n), score(s)
{
}
string Player::getName()
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