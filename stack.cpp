// Stack.cpp
#include <stdexcept>

#include "Stack.h"

void Stack::push(const Card& card) {
    cards.push_back(card);
}

Card Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

bool Stack::isEmpty() const {
    return cards.empty();
}

void Stack::shuffle() {
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(cards.begin(), cards.end());
}