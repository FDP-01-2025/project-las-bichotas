#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

// Códigos de escape ANSI para colores en la consola
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR "\033[36m"

//variables de color para resultados del juego
extern string WINNER_COLOR;
extern string LOSER_COLOR;

//muestra un mensaje con un color opcional
void displayMessage(const string &message, const string &color = RESET_COLOR);

//reproduce un sonido 
void beepSound();

//muestra la información de una carta (ejemplo: "[As de Espadas]")
void displayCardText(const string &rank, const string &suit);

// Muestra un mensaje de logro con un color especial y sonido
void displayAchievement(const string &achievement);

#endif
