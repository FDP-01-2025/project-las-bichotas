#include "src/users.h" 
#include "src/trivia.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include "src/deck.h"
#include "src/player.h"
#include "src/persistence.h"
#include "src/utils.h"
#include "src/questions.h"

using namespace std;

void runTrivia();
void runBlackjack();
void playerTurn(Player& player, Deck& deck);
void dealerTurn(Player& dealer, Deck& deck, int playerPoints);
void playAgainstDealer(mt19937& rng);
void playMultiplayer(mt19937& rng);
void displayMainMenu();

extern vector<User> users;  
extern string currentUserName; 

int main() {
    int gameChoice;
    cout << "Bienvenido a Juegos Bichotas, selecciona uno de los dos juegos:\n1. Trivia Bichota\n2. Blackjack Bichota" << endl;
    cin >> gameChoice;

    if (gameChoice == 1) {
        runTrivia();
    } else if (gameChoice == 2) {
        runBlackjack();
    } else {
        cout << "Debe ingresar una opcion valida" << endl;
    }

    return 0;
}

void runTrivia() {
    int option, userOption;
    int exitFlag = 0;
    cout << "Bienvenido a nuestra trivia, vamos a pasarla bien respondiendo preguntas de cultura general!!!\n1. Crear usuario\n2. Cargar usuario\n";
    cout << "Selecciona una de las opciones que le seran mostradas" << endl;
    loadUsers();
    showUsers();
    cin >> userOption;

    switch (userOption) {
        case 1: createUser(); break;
        case 2: selectUser(); break;
        default: cout << "Opcion invalida\n"; return;
    }

    do {
        cout << "Categorias:\n1. Historia\n2. Musica\n3. Deportes\n4. Geografia\n5. Opciones de Usuario\n6. Pausar y guardar\n7. Salir\n";
        cin >> option;

        switch (option) {
            case 1: playHistory(); break;
            case 2: playMusic(); break;
            case 3: playSports(); break;
            case 4: playGeography(); break;
            case 5: {
                int subOption;
                do {
                    cout << "1. Mostrar usuarios\n2. Seleccionar usuario\n3. Eliminar usuario\n4. Salir\n";
                    cin >> subOption;
                    switch (subOption) {
                        case 1: showUsers(); break;
                        case 2: selectUser(); break;
                        case 3: deleteUser(); break;
                        case 4: cout << "Saliendo de opciones.\n"; break;
                        default: cout << "Opcion invalida.\n"; break;
                    }
                } while (subOption != 4);
                break;
            }
            case 6:
            cout << "Funcionalidad de pausar no implementada.\n"; break;
            case 7: 
            cout << "Saliendo del juego, gracias por jugar!\n"; break;
            default: 
            cout << "Opcion invalida\n"; break;
        }
    } while (option != 7);
}

void displayMainMenu() {
    cout << "\n====== BLACKJACK ======" << endl;
    cout << "1. Play against Dealer" << endl;
    cout << "2. Multiplayer" << endl;
    cout << "3. Show Users" << endl;
    cout << "4. Show Ranking" << endl;
    cout << "5. Reset Ranking" << endl;
    cout << "6. Exit" << endl;
    cout << "\nIngresa tu opcion: ";
}

void playAgainstDealer(mt19937& rng) {
    cout << "[Blackjack] Playing against Dealer... (simulated function)" << endl;
    // Aquí va la lógica real del juego contra dealer
}

void playMultiplayer(mt19937& rng) {
    cout << "[Blackjack] Multiplayer game started... (simulated function)" << endl;
    // Aquí va la lógica real del juego multijugador
}

void runBlackjack() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    random_device rd;
    mt19937 rng(rd());

    int option;
    do {
        displayMainMenu();
        cin >> option;

        while (cin.fail() || option < 1 || option > 6) {
            displayMessage("Opcion invalida. Ingresa un numero entre 1 y 6.", RED_COLOR);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            displayMainMenu();
            cin >> option;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
            case 1: playAgainstDealer(rng); break;
            case 2: playMultiplayer(rng); break;
            case 3: displayUsers(); break;
            case 4: displayRanking(); break;
            case 5: resetRanking(); break;
            case 6: displayMessage("Gracias por jugar. Hasta luego!", CYAN_COLOR); break;
            default: displayMessage("Opcion invalida.", RED_COLOR); break;
        }

        if (option != 6) {
            displayMessage("\nPresiona Enter para continuar...", YELLOW_COLOR);
            cin.get();
        }
    } while (option != 6);
}
