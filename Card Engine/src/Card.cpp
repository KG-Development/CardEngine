#include "../headers/Card.h"
#include "../headers/myconio.h"
#include <iostream>

Card::Card(CARDTYPE number, CARDSIGN symbol, CARDCOLORS color, bool visible) : number(number), symbol(symbol), color(color), visible(visible) {}

CARDSIGN Card::getSign() {
    return this->symbol;
}
CARDTYPE Card::getNumber(){
    return this->number;
}
CARDCOLORS Card::getColor(){
    return this->color;
}
bool Card::isVisible(){
    return this->visible;
}

void Card::setSign(CARDSIGN symbol){
    this->symbol = symbol;
}
void Card::setNumber(CARDTYPE number){
    this->number = number;
}
void Card::setColor(CARDCOLORS color){
    this->color = color;
}
void Card::setVisible(bool visible){
    this->visible = visible;
}

bool Card::equalTo(const Card &card){

    return (this->number == card.number && this->symbol == card.symbol && this->color == card.color);
}

void Card::printCard(){
    if(!this->visible){
        std::cout << "[#]";
        return;
    }
    std::cout << "[";
    myio::setColor(this->color);

    (this->getNumberChar() == ':') ? std::cout << 10 : std::cout <<  this->getNumberChar();
    std::cout << this->getSignChar();
    myio::setColor(WHITE);
    std::cout << "]";
}

char Card::getSignChar(){

    switch(this->symbol){
        case CLUBS:
            return char(5);
        case DIAMONDS:
            return char(4);
        case HEARTS:
            return char(3);
        case SPADES:
            return char(6);
    }
    return -1;
}
char Card::getNumberChar(){
    switch(this->number){
    case AS:
        return 'A';
    case ONE:
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
    case SIX:
    case SEVEN:
    case EIGHT:
    case NINE:
    case TEN:
        return char(number + '0');
    case JOLLY:
        return 'B';
    case QEEN:
        return 'Q';
    case KING:
        return 'K';
    case JOKER:
        return 'J';
    }
    return -1;
}

