#pragma once

#include "../headers/Card.h"

class Hand{

public:
    Hand(int size = 0);

    void addCard(Card* card);
    Card* getCard(int index);
    Card* playCard(int index);

    void removeCard(int index);
    void flipCard(int index);
    void flipHand();

    void show();

    bool isFull();
    bool isEmpty();
private:
    Card* *hand;

    int size;
    int noe;
};
