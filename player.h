// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Shoe.h"
#include "Card.h"
#include <vector>
#include <string> // Include string library

class Player {
public:
    Player(int bankroll);
    Player(int bankroll, const std::string& name); // New constructor

    void bet(int amount);
    void hit(Shoe& shoe);
    void stand();
    int getBankroll() const;
    bool isBust() const;
    bool wantsToHit() const;
    void updateBankroll(int amount);
    void adjustAceValues();
    int calculateHandTotal() const;
    int calculateOptimalValue() const; // Added function
    std::string getName() const; // New method to get player's name
    std::string getHand() const;
    void clearHand();

private:
    int bankroll;
    std::vector<Card> hand;
    std::string name; // New member variable for player's name
};

#endif // PLAYER_H
