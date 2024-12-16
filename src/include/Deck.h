#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <random>
#include <iostream>
#include <string>

using namespace std;

enum facecard{
    A,
    K,
    Q,
    J
};

typedef struct Card{
    int rank;

} Card;

class Deck{
private:
    vector<Card> deck;

public:
    void initDeck();
    void shuffle();
    Card getCard();
    void printDeck();
};
#endif