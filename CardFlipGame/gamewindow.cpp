#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "player.h"
#include <QGridLayout>
#include <QMainWindow>
#include <QtWidgets>
#include <chrono>
#include <thread>
#include <QtDebug>

GameWindow::GameWindow(QWidget *parent, QString p1Name, QString p2Name, int targetScore) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{

    ui->setupUi(this);
    players[0] = Player(p1Name);
    players[1] = Player(p2Name);
    reset();
    winningScore = targetScore;
    ui->player1->setText(p1Name);
    ui->player2->setText(p2Name);
//    ui->currentPlayer->setFont();
    ui->p1Info->setAlignment(Qt::AlignLeft);
    ui->p1Info->setAlignment(Qt::AlignRight);
}

GameWindow::~GameWindow()
{
    delete ui;
}

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
void GameWindow::reset(){
    winner = "TBD";
    currentCardIndex = 0;
    currentPlayerIndex = 0;

    players[0].resetScore();
    players[1].resetScore();
    ui->score1->setText("0");
    ui->score2->setText("0");
    ui->currentPlayer->setText(players[0].getName());
    resetBoard();
}
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void GameWindow::buttonOnClick(int index, QString imagePath, QPushButton *btn){
    qDebug() << "index: " << index << ", currentCardIndex: " << currentCardIndex;
    if (cards[index].getFlipped()){
        return; // ask to choose another card
    }
    QPixmap pix(imagePath);
    QIcon ButtonIcon(pix.scaled(50, 50));
    btn->setFixedSize(QSize(100, 100));
    btn->setIcon(ButtonIcon);
    btn->setIconSize(pix.rect().size());
    selectedCards[currentCardIndex] = index;
    cards[index].toggleFlipped();
    if (currentCardIndex != 0){
        if (cards[selectedCards[0]] == cards[index]){
            unflippedCards -= 2;
            players[currentPlayerIndex].addScore(5);
            int tmp = players[currentPlayerIndex].getScore();
            if (currentPlayerIndex == 0){
                ui->score1->setText(QString::number(tmp));
            } else {
                ui->score2->setText(QString::number(tmp));
            }
            if (unflippedCards == 0){
                deleteBoard(btn->parentWidget()->layout());
                resetBoard();
            }
            if (tmp >= winningScore){
                QString m = " win!";
                QMessageBox::about(this, "Game Over", players[currentPlayerIndex].getName()+m);
                deleteBoard(btn->parentWidget()->layout());
                reset();
                return;
            }
        } else {
            delay(300);
            unflipSelectedCards();
        }
        currentPlayerIndex = 1-currentPlayerIndex;
        ui->currentPlayer->setText(players[currentPlayerIndex].getName());
    }
    currentCardIndex = 1-currentCardIndex;
}
void GameWindow::unflipSelectedCards(){
    QPixmap pix(":/resources/img/organic-food.png");
    QIcon ButtonIcon(pix.scaled(50,50));
    m_button[selectedCards[0]]->setIcon(ButtonIcon);
    m_button[selectedCards[0]]->setIconSize(pix.rect().size());
    cards[selectedCards[0]].toggleFlipped();
    m_button[selectedCards[1]]->setIcon(ButtonIcon);
    m_button[selectedCards[1]]->setIconSize(pix.rect().size());
    cards[selectedCards[1]].toggleFlipped();
}

void GameWindow::deleteBoard(QLayout *board){
    if ( board != NULL )
    {
        QLayoutItem* item;
        while ( ( item = board->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete board;
    }
}

void GameWindow::resetBoard(){
    unflippedCards = 16;
    for (int i = 0; i < 8; i++){
        Card cardA(i);
        Card cardB(i);
        cards[2 * i] = cardA;
        cards[2 * i + 1] = cardB;
    }
    myShuffle(cards);
    QString imagePath[8] {":/resources/img/broccoli.png",
                           ":/resources/img/cabbage.png",
                           ":/resources/img/carrot.png",
                           ":/resources/img/lemon.png",
                           ":/resources/img/onion.png",
                           ":/resources/img/potato.png",
                           ":/resources/img/spinach.png",
                           ":/resources/img/tomato.png"};
    QGridLayout *btnLayout = new QGridLayout(this);
    for (int i = 0; i < 16; i++){
        int val = cards[i].getVal();
        QPushButton *btn = new QPushButton(this);
        QPixmap pix(":/resources/img/organic-food.png");
        QIcon ButtonIcon(pix.scaled(50,50));
        btn->setFixedSize(QSize(100, 100));
        btn->setIcon(ButtonIcon);
        btn->setIconSize(pix.rect().size());
        QString p = imagePath[val];
        QObject::connect(btn, &QPushButton::clicked, [this, i, p, btn] {
            buttonOnClick(i, p, btn);
        });
        m_button[i] = btn;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            btnLayout->addWidget(m_button[j + i * 4], 0 + i, j);
            btnLayout->setSpacing(0);
        }
    }
}




