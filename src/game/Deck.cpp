#include "../include/Deck.h"

void Deck::initDeck(){
    int ranks[13] = {A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card c = {.rank = ranks[j]};
            deck.push_back(c);
        }
    }
}

void Deck::shuffle(){
    for(int i = 0; i < 52; i++){
        int randNum = rand() % 52;
        swap(deck[i], deck[randNum]);
    }
}

Card Deck::getCard(){
    Card c = deck.front();
    deck.erase(deck.begin());
    return c;
}

void Deck::printDeck(){
    int t=0;
	for (Card i : deck) {
		cout << i.rank << ", ";
		t++;
	}
    cout << endl;
}