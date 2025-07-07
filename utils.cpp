#include "utils.h"
#include <iostream> 

using namespace std;

// Inicializa variables globales de color
string WINNER_COLOR = GREEN_COLOR;
string LOSER_COLOR = RED_COLOR;

// Muestra un mensaje en la consola con un color opcional
void displayMessage(const string& message, const string& color) {
    cout << color << message << RESET_COLOR << endl;
}

// Reproduce un sonido de beep del sistema
void beepSound() {
    cout << "\a";
}

