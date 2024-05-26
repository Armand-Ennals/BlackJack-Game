#pragma once
// Shoe.h
#ifndef SHOE_H
#define SHOE_H

#include "Queue.h"
#include "Deck.h"


class Shoe {
public:
    void createShoe(int numberOfDecks);
    Card drawCard(); // Add this line
    


private:
    Queue queue;
    std::vector<Card> deck;

};

#endif // SHOE_H

