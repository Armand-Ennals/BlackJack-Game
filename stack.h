#pragma once

// Stack.h
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <algorithm> // for std::random_shuffle
#include <ctime> // for std::time
#include <cstdlib> // for std::rand, std::srand
#include "Card.h"

class Stack {
public:
    void push(const Card& card);
    Card pop();
    bool isEmpty() const;
    void shuffle();

protected:
    void shuffleCards() {
        std::srand(unsigned(std::time(0)));
        std::random_shuffle(cards.begin(), cards.end());
    }

private:
    std::vector<Card> cards;
};

#endif // STACK_H

