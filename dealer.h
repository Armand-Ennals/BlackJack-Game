// Dealer.h
#ifndef DEALER_H
#define DEALER_H

#include "Shoe.h"
#include "Card.h"
#include <vector>

class Player;

class Dealer {
public:
    void dealInitialCards(Player& player, Shoe& shoe);
    void hit(Shoe& shoe);
    void stand();
    bool isBust() const;
    std::string getHand();
    bool shouldHit() const;
    int calculateWinner() const;
    void dealerTurn(Shoe& shoe);
    int calculateHandTotal() const;
    std::string getHand() const;
    void clearHand();
    int calculateOptimalValue() const;  // Calculate the optimal value of the hand


private:
    std::vector<Card> hand;
};

#endif // DEALER_H
