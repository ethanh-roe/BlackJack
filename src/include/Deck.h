#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <random>
#include <iostream>

using namespace std;

enum facecards{
    A, // Ace
    K, // King
    Q, // Queen
    J  // Jack
};

class Deck{
    public:
        vector<int> deck;

        void initDeck();
        void shuffle();
        int getCard();
        void printDeck();
};

#endif