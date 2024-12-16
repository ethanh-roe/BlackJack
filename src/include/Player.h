#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "Deck.h"

using namespace std;

class Player{
    private:
    vector<Card> hand;
    int bet;
    int chips;

    public:
    Player();
    Player(int initChips);

    vector<Card> getHand();
    void addCardToHand(Card);
    int getBet();
    void addToBet(int);
    int getChips();
    void addChips(int);
};
#endif