// Deck.cpp
#include <algorithm> // for std::random_shuffle
#include <ctime> // for std::time
#include <cstdlib> // for std::rand, std::srand
#include "Deck.h"

void Deck::createDeck() {
    std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    std::string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            int value = 0;
            if (rank == "A") {
                value = 1;
            }
            else if (rank == "K" || rank == "Q" || rank == "J") {
                value = 10;
            }
            else {
                value = std::stoi(rank);
            }
            std::string cardname = rank + suit;
            Card card(rank, suit, value);
            push(card);
        }
    }
}

void Deck::shuffleDeck() {
    shuffleCards();
}
