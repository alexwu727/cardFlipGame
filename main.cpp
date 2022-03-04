#include <iostream>
using namespace std;
#include "card.h"
#include "board.h"
#include "player.h"
// using "clang++ main.cpp card.cpp board.cpp player.cpp -o main.out" to build this file
int main()
{

    Board board;
    string p1Name, p2Name;
    cout << "Welcome! This is a dual card flipping game." << endl;
    cout << "Please enter your names" << endl;
    cout << "Player 1: ";
    cin >> p1Name;
    cout << "Player 2: ";
    cin >> p2Name;

    Player p1(p1Name);
    Player p2(p2Name);
    board.setPlayer(p1, p2);
    board.displayScore();
    // board.cheat(); // function cheat can show all card's value
    while (!board.isOver())
    {
        board.action();
    }
    cout << board.getWinner() << " win!!" << endl;

    return 0;
}