// Queue.cpp
#include <stdexcept>

#include "Queue.h"

void Queue::enqueue(const Card& card) {
    cards.push_back(card);
}

Card Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Card card = cards.front();
    cards.erase(cards.begin());
    return card;
}

bool Queue::isEmpty() const {
    return cards.empty();
}
