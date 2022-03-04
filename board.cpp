#include <iostream>
#include "board.h"
using namespace std;
void mySwap(Card *a, Card *b)
{
    Card temp = *a;
    *a = *b;
    *b = temp;
}
void myShuffle(Card arr[])
{
    srand(time(0));
    for (int i = 15; i > 0; i--)
    {
        int j = rand() % (i + 1);
        mySwap(&arr[i], &arr[j]);
    }
}
Board::Board()
{
    reset();
}
void Board::setPlayer(Player p1, Player p2)
{
    players[0] = p1;
    players[1] = p2;
}
void Board::displayScore()
{
    cout << players[0].getName() << " " << players[0].getScore() << " vs " << players[1].getScore() << " " << players[1].getName() << endl;
}

bool Board::isOver()
{
    return over;
}

string Board::getWinner()
{
    return winner;
}
void Board::action()
{
    Player *currentPlayer = &players[currentPlayerIndex];

    // card1
    cout << "----- Choose first card -----" << endl;
    Card *card1 = &cards[currentPlayer->choose()];
    while (card1->getFlipped())
    {
        cout << "This card has been already flipped, choose another card." << endl;
        card1 = &cards[currentPlayer->choose()];
    }
    cout << "Card1's val is " << card1->getVal() << endl;
    card1->toggleFlipped();

    // card2
    cout << "----- Choose second card -----" << endl;
    Card *card2 = &cards[currentPlayer->choose()];
    while (card2->getFlipped())
    {
        cout << "This card has been already flipped, choose another card." << endl;
        card2 = &cards[currentPlayer->choose()];
    }
    cout << "Card2's val is " << card2->getVal() << endl;

    // compare card1 and card2
    cout << "====================================" << endl;
    if (*card1 == *card2)
    {
        cout << "They match! " << currentPlayer->getName() << " got 5 points!" << endl;
        currentPlayer->addScore(5);
        card2->toggleFlipped();
        unflippedCards -= 2;
    }
    else
    {
        cout << "Sorry, they don't match :(" << endl;
        card1->toggleFlipped();
    }

    // round result
    displayScore();
    cout << unflippedCards << " cards remain" << endl;

    currentPlayerIndex = 1 - currentPlayerIndex;
    if (unflippedCards == 0)
    {
        over = true;
        winner = (players[0].getScore() > players[1].getScore()) ? players[0].getName() : players[1].getName();
    }
}
void Board::reset()
{
    winner = "TBD";
    over = false;
    unflippedCards = 16;
    currentPlayerIndex = 0;

    for (int i = 0; i < 8; i++)
    {
        Card cardA(i);
        Card cardB(i);
        cards[2 * i] = cardA;
        cards[2 * i + 1] = cardB;
    }
    myShuffle(cards);
}
void Board::cheat()
{
    for (int i = 0; i < 16; i++)
    {
        cout << i << ": " << cards[i].getVal() << endl;
    }
}
