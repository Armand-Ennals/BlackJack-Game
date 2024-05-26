// Shoe.cpp
#include "Shoe.h"
#include <stdexcept>

void Shoe::createShoe(int numberOfDecks) {
    for (int i = 0; i < numberOfDecks; ++i) {
        Deck deck;
        deck.createDeck();
        deck.shuffleDeck();
        while (!deck.isEmpty()) {
            queue.enqueue(deck.pop());
        }
    }
}

Card Shoe::drawCard() { // Add this function
    if (queue.isEmpty()) {
        throw std::runtime_error("The shoe is empty");
    }

    Card card = queue.dequeue();
    return card;
}

