#pragma once

#include "Card.h"
#include "CardDefenition.h"

class Deck{

public:
    Deck(int size = 52);

    void shuffle();

    void push(Card *card);
    Card* pop();
    Card* peek();
    Card* getCardByIndex(int index);

    int getSize();
    int getElements();

    bool isFull();
    bool isEmpty();


private:
    Card* *deck;

    int size;
    int noe;
};
