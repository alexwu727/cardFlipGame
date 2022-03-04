#ifndef BOARD_H
#define BOARD_H
#include "card.h"
#include "player.h"
class Board
{
private:
    string winner;
    bool over;
    Card cards[16];
    int unflippedCards;
    Player players[2];
    int currentPlayerIndex;

public:
    Board();
    void setPlayer(Player p1, Player p2);
    void displayScore();
    bool isOver();
    void action(); // next turn
    void reset();
    void cheat();
    string getWinner();
};

#endif