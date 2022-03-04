#include <iostream>
#include "card.h"
using namespace std;

Card::Card(int v)
{
    val = v;
    flipped = false;
}
int Card::getVal()
{
    return val;
}
void Card::toggleFlipped()
{
    flipped = !flipped;
}
bool Card::getFlipped()
{
    return flipped;
}
