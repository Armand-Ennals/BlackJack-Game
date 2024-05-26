#pragma once
// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include "Card.h"

class Queue {
public:
    void enqueue(const Card& card);
    Card dequeue();
    bool isEmpty() const;

private:
    std::vector<Card> cards;
};

#endif // QUEUE_H

