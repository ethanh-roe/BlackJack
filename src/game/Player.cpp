#include "../include/Player.h"

using namespace std;

Player::Player(){
    chips = 1000;
}

Player::Player(int initChips){
    chips = initChips;
}

vector<Card> Player::getHand(){
    return hand;
}

void Player::addCardToHand(Card card){
    hand.push_back(card);
}

int Player::getBet(){
    return bet;
}

void Player::addToBet(int amt){
    bet += amt;
}

int Player::getChips(){
    return chips;
}

void Player::addChips(int amt){
    chips += amt;
}