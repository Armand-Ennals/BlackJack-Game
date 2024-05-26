// Dealer.cpp
#include <iostream>

#include "Dealer.h"
#include "player.h"

void Dealer::dealInitialCards(Player& player, Shoe& shoe) {
    // Deal two cards to the player
    player.hit(shoe);
    player.hit(shoe);

    // Deal two cards to the dealer
    hit(shoe);
    hit(shoe);
}


void Dealer::hit(Shoe& shoe) {
    Card card = shoe.drawCard(); // Assuming drawCard() is a method in the Shoe class that draws a card
    hand.push_back(card); // Assuming hand is a std::vector<Card> that represents the dealer's hand
}


void Dealer::stand() {
    // Implementation depends on your game rules
}

void Dealer::dealerTurn(Shoe& shoe) {
    // Reveal the dealer's face down card
    // This could be done in your game logic, depending on how you've set up your game

    while (calculateOptimalValue() < 17) { // Assuming calculateOptimalValue() calculates the total value of the dealer's hand
        hit(shoe);
    }

    if (calculateOptimalValue() > 21) {
        // Dealer has busted
        // You could handle this in your game logic
    }
    else {
        // Dealer stands
        stand();
    }

    // Total up the hands and end the round
    // This could be done in your game logic
}

int Dealer::calculateHandTotal() const {
    int total = 0;
    for (const auto& card : hand) {
        total += card.getValue();
    }
    return total;
}

bool Dealer::isBust() const {
    if (calculateOptimalValue() > 21) {
        return true;
    }
    return false;
}

std::string Dealer::getHand() {
    std::string handStr;
    for (const Card& card : hand) {
        handStr += card.toString() + " ";
    }
    return handStr;
}

void Dealer::clearHand() {
    hand.clear();
}

int Dealer::calculateOptimalValue() const {
    int total = 0;
    int aceCount = 0;

    // Calculate total value and count the number of Aces
    for (Card card : hand) {
        if (card.isAce()) {
            aceCount++;
            total += 11;  // Initially consider Ace as 11
        }
        else {
            total += card.getValue();
        }
    }

    // If total value > 21 and there's an Ace in the hand, consider Ace as 1
    while (total > 21 && aceCount > 0) {
        total -= 10;  // Subtract 10 from total value (change Ace value from 11 to 1)
        aceCount--;   // Decrease the count of Aces
    }

    return total;
}