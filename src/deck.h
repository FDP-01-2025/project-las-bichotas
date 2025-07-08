#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <random> // <- Asegúrate de tener esto

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

    // ✅ Cambiar esta línea:
    void shuffle(std::mt19937& rng);  // ← DEBE aceptar rng como referencia

    Card deal();
};

#endif // DECK_H
