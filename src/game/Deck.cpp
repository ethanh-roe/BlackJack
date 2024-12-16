#include "../include/Deck.h"

vector<int> deck;


void Deck::initDeck(){
    deck = {
        A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
        A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
        A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,
        A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
    };
}

void Deck::shuffle(){
    for(int i = 0; i < 52; i++){
        int randNum = rand() % 52;
        swap(deck[i], deck[randNum]);
    }
}

int Deck::getCard(){
    int card = deck.front();
    deck.erase(deck.begin());
    return card;
}

void Deck::printDeck(){
    int t=0;
	for (auto i : deck) {
		cout << i << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
}