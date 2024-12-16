#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <random>
#include <iostream>

using namespace std;

class Deck{
    public:
        vector<int> deck;

        void initDeck();
        void shuffle();
        int getCard();
        void printDeck();
};

#endif