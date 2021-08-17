#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/Card.h"
#include "headers/CardDefenition.h"
#include "headers/Deck.h"
#include "headers/myconio.h"
#include "headers/Hand.h"

int main() {
    /*
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Card Engine");
    while (window.isOpen()) {
            sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }


    Deck deck(56);
    CARDCOLORS c = (CARDCOLORS) BLACK;

    myio::setColorAndBackground(WHITE, GREEN);
    for(int j = 0; j < 4; j++){

        if((CARDSIGN) j == HEARTS || (CARDSIGN) j == DIAMONDS){
            c = (CARDCOLORS) RED;
        }else{
            c = (CARDCOLORS) BLACK;
        }

        for(int i = 0; i < 14; i++){
            deck.push(new Card((CARDTYPE) i, (CARDSIGN) j, c, true));
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 14; j++){
            deck.pop()->printCard();
        }
        std::cout << std::endl;
    }

    deck.shuffle();

    Card *card =  deck.pop();
    card->printCard();
    */


    Deck deck(56);
    CARDCOLORS c = (CARDCOLORS) BLACK;

    myio::setColorAndBackground(WHITE, GREEN);
    for(int j = 0; j < 4; j++){

        if((CARDSIGN) j == HEARTS || (CARDSIGN) j == DIAMONDS){
            c = (CARDCOLORS) RED;
        }else{
            c = (CARDCOLORS) BLACK;
        }

        for(int i = 0; i < 14; i++){
            deck.push(new Card((CARDTYPE) i, (CARDSIGN) j, c, false));
        }
    }
    /*
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 14; j++){
            deck.pop()->printCard();
        }
        std::cout << std::endl;
    }
    */

    deck.shuffle();

    Hand h(5);

    for(int i = 0; i < 5; i++){
        h.addCard(deck.pop());
    }
    std::cout <<"Hand: ";
    h.flipHand();
    h.show();
    std::cout << std::endl << "Deck: ";
    for(int i = 0; i < deck.getElements(); i++){
        deck.getCardByIndex(i)->setVisible(true);
        deck.getCardByIndex(i)->printCard();
    }
    return 0;
}
