#include "deck.h"
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::mt19937
#include <stdexcept> // Para runtime_error
#include <string>

using namespace std;

// Inicializa una baraja estándar de 52 cartas
Deck::Deck() {
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "J", "Q", "K"};

    // Crea las 52 cartas
    for (const auto &suit : suits) {
        for (const auto &rank : ranks) {
            int points = 0;
            if (rank == "A") {
                points = 11; // El As cuenta inicialmente como 11
            } else if (rank == "J" || rank == "Q" || rank == "K") {
                points = 10; // Las figuras cuentan como 10
            } else {
                points = stoi(rank); // Las cartas numéricas cuentan su valor
            }
            cards.push_back({suit, rank, points});
        }
    }
}

// Mezcla las cartas de la baraja usando un generador externo
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);
}

// Reparte una sola carta de la parte superior de la baraja
Card Deck::deal() {
    if (cards.empty()) {
        throw runtime_error("La baraja está vacía. No se pueden repartir más cartas.");
    }
    Card c = cards.back();
    cards.pop_back();
    return c;
}