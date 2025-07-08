#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "deck.h"

using namespace std;

//Class Player para gestionar la mano y lógica del jugador
class Player
{
public:
    string name;
    vector<Card> hand; //Almacena las cartas en la mano del jugador

    //Inicializa un jugador con un nombre
    Player(string n);

    //Recibe una carta y la añade a la mano del jugador
    void receiveCard(Card c);

    //Calcula el total de puntos de la mano del jugador

    int calculatePoints() const;

    // Muestra las cartas en la mano del jugador
    void displayHand() const;
};

#endif