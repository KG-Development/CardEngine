#include "../headers/Deck.h"
#include "time.h"
#include <windows.h>
#include <iostream>

Deck::Deck(int size) : size(size){

    this->deck = new Card*[size];
    this->noe = 0;

    for(int i = 0; i < size; i++){
        this->deck[i] = new Card();
    }
}

void Deck::shuffle(){
    srand(time(NULL));
    for(int i = 0; i < this->noe; i++){
        int randPos = rand() % this->noe;
        std::swap(this->deck[i], this->deck[randPos]);
    }
}

void Deck::push(Card *card){

    if(this->isFull())
        return;

    this->deck[this->noe] = card;

    this->noe++;
}
Card* Deck::pop(){

    if(this->isEmpty())
        return new Card();

    this->noe -= 1;

    Card* returnVal = this->deck[this->noe];

    return returnVal;
}
Card* Deck::peek(){

    if(this->isEmpty())
        return new Card();

    Card* returnVal = this->deck[this->noe - 1];

    return returnVal;
}


bool Deck::isFull(){
    return (this->size == this->noe);
}
bool Deck::isEmpty(){
    return (this->noe <= 0);
}
int Deck::getSize(){
    return this->size;
}
int Deck::getElements(){
    return this->noe;
}
