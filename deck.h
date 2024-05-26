#pragma once
// Deck.h
#ifndef DECK_H
#define DECK_H

#include "Stack.h"

class Deck : public Stack {
public:
    void createDeck();
    void shuffleDeck();
};

#endif // DECK_H


