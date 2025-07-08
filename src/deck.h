#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <random> 

using namespace std;

struct Card {
    string suit;
    string rank;
    int points;
};

class Deck {
private:
    vector<Card> cards;

public:
    Deck();

   
    void shuffle(std::mt19937& rng); 

    Card deal();
};

#endif // DECK_H
