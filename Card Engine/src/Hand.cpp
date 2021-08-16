#include "../headers/Card.h"
#include "../headers/Hand.h"

Hand::Hand(int size) : size(size) {

    this->hand = new Card*[size];
    this->noe = 0;

    for(int i = 0; i < size; i++){
        this->hand[i] = new Card();
    }
}

void Hand::addCard(Card* card){

    if(this->isFull())
        return;

    this->hand[this->noe] = card;

    this->noe++;
}
Card* Hand::getCard(int index){
    if(index > this->noe - 1 || index < 0)
        return nullptr;
    return this->hand[index];
}
Card* Hand::playCard(int index){
    if(index > this->noe - 1 || index < 0)
        return nullptr;

    Card* returnVal = this->hand[index];
    returnVal->setVisible(true);

    this->noe -= 1;

    for(int i = index; i < this->noe; i++){
        this->hand[i] = this->hand[i + 1];
    }

    return returnVal;
}

void Hand::removeCard(int index){
    if(index > this->noe - 1 || index < 0)
        return;
    this->noe -= 1;

    for(int i = index; i < this->noe; i++){
        this->hand[i] = this->hand[i + 1];
    }
}

void Hand::flipCard(int index){
    if(index > this->noe - 1 || index < 0)
        return;
    if(this->hand[index]->isVisible()){
        this->hand[index]->setVisible(false);
    }else{
        this->hand[index]->setVisible(true);
    }
}
void Hand::flipHand(){

    for(int i = 0; i < this->noe; i++){
        this->hand[i]->setVisible(true);
    }
}


void Hand::show(){
    for(int i = 0; i < this->noe; i++){
        this->hand[i]->printCard();
    }
}

bool Hand::isFull(){
    return (this->size == this->noe);
}
bool Hand::isEmpty(){
    return (this->noe <= 0);
}
