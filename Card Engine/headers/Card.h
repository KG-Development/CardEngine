#pragma once

#include "CardDefenition.h"

class Card{

public:
    Card(CARDTYPE number = AS, CARDSIGN symbol = SPADES, CARDCOLORS color = BLACK, bool visible = false);
    CARDSIGN getSign();
    CARDTYPE getNumber();
    CARDCOLORS getColor();

    bool isVisible();

    char getSignChar();
    char getNumberChar();

    void setSign(CARDSIGN symbol);
    void setNumber(CARDTYPE number);
    void setColor(CARDCOLORS color);
    void setVisible(bool visible);

    bool equalTo(const Card &card);

    void printCard();

private:
    CARDTYPE number;
    CARDSIGN symbol;
    CARDCOLORS color;

    bool visible;

};
