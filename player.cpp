// Player.cpp
#include <iostream>

#include "Player.h"
#include <stdexcept> // Include this for std::invalid_argument

Player::Player(int bankroll) : bankroll(bankroll) {}

Player::Player(int bankroll, const std::string& name) : bankroll(bankroll), name(name) {} // New constructor

std::string Player::getName() const {
    return name;
} // New method

void Player::bet(int amount) {
    if (amount > bankroll) {
        throw std::invalid_argument("Bet amount cannot exceed bankroll");
    }
    bankroll -= amount;
}

void Player::updateBankroll(int amount) {
    bankroll += amount;
}

void Player::hit(Shoe& shoe) {
    Card card = shoe.drawCard(); // Assuming drawCard() is a method in the Shoe class that draws a card
    hand.push_back(card); // Assuming hand is a std::vector<Card> that represents the player's hand
    adjustAceValues(); // Adjust the value of Ace if total hand value exceeds 21
}

void Player::stand() {
    // Implementation depends on your game rules
}

int Player::getBankroll() const {
    return bankroll;
}

void Player::adjustAceValues() {
    int handTotal = 0;
    for (const auto& card : hand) {
        handTotal += card.getValue();
    }

    if (handTotal > 21) {
        for (auto& card : hand) {
            if (card.getRank() == "Ace" && card.getValue() == 11) {
                // Assuming Card class has a method to set value
                // If not, you need to add a method in Card class to set value
                card.setValue(1);
                break; // exit the loop after adjusting one Ace
            }
        }
    }
}

int Player::calculateHandTotal() const {
    int total = 0;
    for (const auto& card : hand) {
        total += card.getValue();
    }
    return total;
}

bool Player::isBust() const {
    return calculateOptimalValue() > 21;
}

bool Player::wantsToHit() const {
    if (calculateOptimalValue() == 21) {
        return false; // Player does not want to hit if they have 21
    }

    std::string response;
    do {
        std::cout << "\n";  //Line break
    	std::cout << "Do you want to hit? (y/n): ";
        std::getline(std::cin, response);
        if (response != "y" && response != "Y" && response != "n" && response != "N") {
            std::cout << "Invalid response. Please enter 'y' or 'n'.\n";
        }
    } while (response != "y" && response != "Y" && response != "n" && response != "N");
    return response == "y" || response == "Y";
}

std::string Player::getHand() const {
    std::string handStr;
    for (const Card& card : hand) {
        handStr += card.toString() + " ";
    }
    return handStr;
}

void Player::clearHand() {
    hand.clear();
}

int Player::calculateOptimalValue() const {
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
