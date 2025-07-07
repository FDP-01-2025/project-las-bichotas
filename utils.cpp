#include "utils.h"
#include <iostream>

using namespace std;

//variables globales de color
string WINNER_COLOR = GREEN_COLOR;
string LOSER_COLOR = RED_COLOR;

//Muestra un mensaje en la consola con un color opcional
void displayMessage(const string &message, const string &color)
{
    cout << color << message << RESET_COLOR << endl;
}

//Reproduce un sonido de beep
void beepSound()
{
    cout << "\a";
}

//Muestra la información de una carta(ejemplo: "[As de Espadas]")
void displayCardText(const string &rank, const string &suit)
{
    cout << "[" << rank << " de " << suit << "]" << endl;
}

//Muestra un mensaje de logro con un color especial y sonido
void displayAchievement(const string &achievement)
{
    displayMessage("LOGRO DESBLOQUEADO: " + achievement, MAGENTA_COLOR);
    beepSound();
}
