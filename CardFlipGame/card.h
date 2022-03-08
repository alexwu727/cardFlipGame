#ifndef CARD_H
#define CARD_H
class Card
{
private:
    int val;
    bool flipped;

public:
    Card(int v = -1);
    int getVal();
    void toggleFlipped();
    bool getFlipped();
    bool operator==(const Card &other)
    {
        return val == other.val;
    };
};

#endif
