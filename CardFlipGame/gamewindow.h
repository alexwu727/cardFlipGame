#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "player.h"
#include "card.h"
#include <QGridLayout>
namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, QString p1Name = "player1", QString p2Name = "player2", int targetScore=20);
    ~GameWindow();
    void reset();

private slots:

//    void on_pushButton_clicked();

private:
    Ui::GameWindow *ui;
    Player players[2];
    Card cards[16];
    QPushButton *m_button[16];
    int winningScore;
    int currentCardIndex;
    int unflippedCards;
    int selectedCards[2];
    int currentPlayerIndex;
    void buttonOnClick(int index, QString imagePath, QPushButton *btn);
    void unflipSelectedCards();
    void deleteBoard(QLayout *board);
    void resetBoard();
    QString winner;


};

#endif // GAMEWINDOW_H
