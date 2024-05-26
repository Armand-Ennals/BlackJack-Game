#pragma once
// Card.h
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
        Card(char suit, int rank);

    Card(const std::string& rank, const std::string& suit, int value);

    std::string getRank() const;
    std::string getSuit() const;
    int getValue() const;
    void setValue(int newValue); // Add this line
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
        bool isAce() const;

private:
    std::string rank;
    std::string suit;
    int value;
};

#endif // CARD_H


