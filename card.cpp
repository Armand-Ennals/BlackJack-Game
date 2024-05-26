// Card.cpp
#include "Card.h"

Card::Card(const std::string& rank, const std::string& suit, int value)
    : rank(rank), suit(suit), value(value) {}

std::string Card::getRank() const {
    return rank;
}

std::string Card::getSuit() const {
    return suit;
}

int Card::getValue() const {
    if (rank == "A") {
        return 11;  // Ace is initially considered as 11
    }
    else if (rank == "K" || rank == "Q" || rank == "J") {
        return 10;  // Face cards are worth 10
    }
    else {
        return std::stoi(rank);  // Number cards are worth their face value
    }
}


void Card::setValue(int newValue) { // Add this method
    value = newValue;
}

std::string Card::toString() const {
    std::string cardString = rank;

    // Add suit to string
    if (suit == "Clubs") {
        cardString += "\u2663"; // ♣
    }
    else if (suit == "Diamonds") {
        cardString += "\u2666"; // ♦
    }
    else if (suit == "Hearts") {
        cardString += "\u2665"; // ♥
    }
    else if (suit == "Spades") {
        cardString += "\u2660"; // ♠
    }

    return cardString;
}

bool Card::isAce() const {
    return rank == "A";
}
