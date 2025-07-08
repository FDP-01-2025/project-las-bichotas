#include "src/users.h"
#include "src/trivia.h"
#include "src/deck.h"
#include "src/player.h"
#include "src/persistence.h"
#include "src/utils.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <cctype>

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
    cout << "========================================" << endl;
    cout << "      Bienvenido a Juegos Bichotas      " << endl;
    cout << "========================================" << endl;
    cout << "Selecciona uno de los dos juegos:" << endl;
    cout << "1. Trivia Bichota" << endl;
    cout << "2. Blackjack Bichota" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Tu opcion: ";
    cin >> gameChoice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (gameChoice == 1) {
        runTrivia();
    } else if (gameChoice == 2) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        runBlackjack();
    } else {
        cout << "Opcion invalida. Por favor, ingresa 1 o 2." << endl;
    }

    cout << "\nGracias por jugar a Juegos Bichotas! Hasta la proxima!" << endl;
    return 0;
}

void runTrivia() {
    int option;
    int userOption;

    cout << "\n========================================" << endl;
    cout << "      Bienvenido a Trivia Bichota       " << endl;
    cout << "========================================" << endl;
    cout << "Vamos a pasarla bien respondiendo preguntas de cultura general!!!" << endl;
    cout << "Selecciona una de las opciones que le seran mostradas" << endl;
    cout << "\n1. Crear usuario\n2. Cargar usuario\n" << endl;

    loadUsers();
    showUsers();

    cin >> userOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (userOption) {
        case 1: createUser(); break;
        case 2: selectUser(); break;
        default:
            cout << "Opcion invalida. Por favor, selecciona 1 o 2." << endl;
            return;
    }

    do {
        cout << "\n--- Menu de Categorias de Trivia ---" << endl;
        cout << "1. Historia" << endl;
        cout << "2. Musica" << endl;
        cout << "3. Deportes" << endl;
        cout << "4. Geografia" << endl;
        cout << "5. Opciones de Usuario" << endl;
        cout << "6. Pausar y guardar" << endl;
        cout << "7. Salir de Trivia" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {
            case 1: playHistory(); break;
            case 2: playMusic(); break;
            case 3: playSports(); break;
            case 4: playGeography(); break;
            case 5: {
                int subOption;
                do {
                    cout << "\n--- Opciones de Usuario ---" << endl;
                    cout << "1. Mostrar todos los usuarios" << endl;
                    cout << "2. Seleccionar otro usuario" << endl;
                    cout << "3. Eliminar usuario" << endl;
                    cout << "4. Volver al Menu de Categorias" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Ingresa tu opcion: ";
                    cin >> subOption;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (subOption) {
                        case 1: showUsers(); break;
                        case 2: selectUser(); break;
                        case 3: deleteUser(); break;
                        case 4: cout << "Saliendo de opciones de usuario.\n"; break;
                        default: cout << "Opcion invalida. Por favor, ingresa un numero entre 1 y 4.\n"; break;
                    }
                } while (subOption != 4);
                break;
            }
            case 6:
                saveUsers();
                cout << "Juego pausado y usuarios guardados.\n";
                break;
            case 7:
                cout << "Saliendo de Trivia. Gracias por jugar!\n";
                saveUsers();
                break;
            default:
                cout << "Opcion invalida. Por favor, ingresa un numero entre 1 y 7.\n";
                break;
        }
    } while (option != 7);
}

void playerTurn(Player& player, Deck& deck) {
    char choice;
    while (true) {
        displayMessage("\n--- Turno de " + player.name + " ---", YELLOW_COLOR);
        player.displayHand();
        displayMessage("Puntos: " + to_string(player.calculatePoints()), CYAN_COLOR);

        if (player.calculatePoints() == 21 && player.hand.size() == 2) {
            displayAchievement("BLACKJACK!");
            break;
        }
        if (player.calculatePoints() > 21) {
            displayMessage(player.name + " se paso (mas de 21).", RED_COLOR);
            displayAchievement("TE PASASTE!");
            break;
        }
        if (player.hand.size() == 5 && player.calculatePoints() <= 21) {
            displayAchievement("5 CARTAS SIN PASARSE!");
            break;
        }

        displayMessage("Quieres otra carta? (y/n): ", GREEN_COLOR);
        cin >> choice;

        while (cin.fail() || (tolower(choice) != 'y' && tolower(choice) != 'n')) {
            displayMessage("Entrada invalida. Por favor ingresa 'y' o 'n'.", RED_COLOR);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresa tu opcion: ";
            cin >> choice;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(choice) == 'y') {
            Card newCard = deck.deal();
            player.receiveCard(newCard);
            displayMessage("Recibiste: ", BLUE_COLOR);
            displayCardText(newCard.rank, newCard.suit);
        } else {
            break;
        }
    }
}

void dealerTurn(Player& dealer, Deck& deck, int playerPoints) {
    displayMessage("\n--- Turno del Dealer ---", YELLOW_COLOR);
    displayMessage("Mano del Dealer: ", YELLOW_COLOR);
    dealer.displayHand();
    displayMessage("Puntos del Dealer: " + to_string(dealer.calculatePoints()), GREEN_COLOR);

    while (true) {
        int points = dealer.calculatePoints();
        if ((points >= 17 && points >= playerPoints) || points > 21) {
            if (points > 21) {
                displayMessage("El Dealer se paso (mas de 21).", RED_COLOR);
                displayAchievement("DEALER SE PASO!");
            } else {
                displayMessage("El Dealer se planta con " + to_string(points) + " puntos.", CYAN_COLOR);
            }
            break;
        }
        displayMessage("El Dealer toma una carta...", YELLOW_COLOR);
        Card c = deck.deal();
        dealer.receiveCard(c);
        displayCardText(c.rank, c.suit);
        dealer.displayHand();
        displayMessage("Puntos del Dealer: " + to_string(dealer.calculatePoints()), GREEN_COLOR);
    }
}

void playAgainstDealer(mt19937& rng) {
    if (currentName == "Ninguno") {
        displayMessage("No hay un usuario seleccionado. Por favor, selecciona o crea uno en el menu de Trivia.", RED_COLOR);
        return;
    }

    Deck deck;
    deck.shuffle(rng);

    Player player(currentName);
    Player dealer("Dealer");

    player.receiveCard(deck.deal());
    dealer.receiveCard(deck.deal());
    player.receiveCard(deck.deal());
    dealer.receiveCard(deck.deal());

    displayMessage("\n--- Manos Iniciales ---", YELLOW_COLOR);
    player.displayHand();
    displayMessage("El Dealer muestra: ", YELLOW_COLOR);
    displayCardText(dealer.hand[0].rank, dealer.hand[0].suit);
    displayMessage("La segunda carta del Dealer esta boca abajo.", YELLOW_COLOR);

    playerTurn(player, deck);

    if (player.calculatePoints() > 21) {
        displayMessage("\n--- Resultados Finales ---", YELLOW_COLOR);
        displayMessage("Puntos de " + player.name + ": " + to_string(player.calculatePoints()), RED_COLOR);
        dealer.displayHand();
        displayMessage(player.name + " se paso. Gana el Dealer!", LOSER_COLOR);
        beepSound();
        // Update ranking for the dealer (as they won)
        updateRanking(dealer.name);
        return;
    }

    dealerTurn(dealer, deck, player.calculatePoints());

    int playerPoints = player.calculatePoints();
    int dealerPoints = dealer.calculatePoints();

    displayMessage("\n--- Resultados Finales ---", YELLOW_COLOR);
    displayMessage("Puntos de " + player.name + ": " + to_string(playerPoints), GREEN_COLOR);
    displayMessage("Puntos del Dealer: " + to_string(dealerPoints), RED_COLOR);

    if (playerPoints <= 21 && (playerPoints > dealerPoints || dealerPoints > 21)) {
        displayMessage("Ganaste!", WINNER_COLOR);
        beepSound();
        // Update ranking for the player (as they won)
        updateRanking(player.name);
    } else if (dealerPoints <= 21 && (dealerPoints > playerPoints || playerPoints > 21)) {
        displayMessage("Gana el Dealer!", LOSER_COLOR);
        beepSound();
        // Update ranking for the dealer (as they won)
        updateRanking(dealer.name);
    } else {
        displayMessage("Empate!", YELLOW_COLOR);
    }
}

void playMultiplayer(mt19937& rng) {
    displayMessage("\n--- MODO MULTIJUGADOR (BLACKJACK) ---", BLUE_COLOR);
    int numPlayers;
    displayMessage("Ingresa el numero de jugadores (2-7): ", GREEN_COLOR);
    cin >> numPlayers;

    while (cin.fail() || numPlayers < 2 || numPlayers > 7) {
        displayMessage("Numero de jugadores invalido. Ingresa un numero entre 2 y 7.", RED_COLOR);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingresa el numero de jugadores (2-7): ";
        cin >> numPlayers;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Player> players;
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        displayMessage("Ingresa el nombre del Jugador " + to_string(i + 1) + ": ", GREEN_COLOR);
        getline(cin, name);
        players.push_back(Player(name));
    }

    Deck deck;
    deck.shuffle(rng);

    for (int i = 0; i < 2; ++i) {
        for (Player& p : players) {
            p.receiveCard(deck.deal());
        }
    }

    displayMessage("\n--- Manos Iniciales ---", YELLOW_COLOR);
    for (Player& p : players) {
        displayMessage("Mano de " + p.name + ":", CYAN_COLOR);
        p.displayHand();
    }

    for (Player& p : players) {
        playerTurn(p, deck);
    }

    displayMessage("\n--- Resultados del Juego Multijugador ---", YELLOW_COLOR);
    int maxPoints = 0;
    for (const Player& p : players) {
        int points = p.calculatePoints();
        displayMessage(p.name + " termino con " + to_string(points) + " puntos.", CYAN_COLOR);
        if (points <= 21 && points > maxPoints) {
            maxPoints = points;
        }
    }

    vector<string> winners;
    if (maxPoints == 0) {
        displayMessage("Todos los jugadores se pasaron. No hay ganador claro.", YELLOW_COLOR);
    } else {
        for (const Player& p : players) {
            if (p.calculatePoints() == maxPoints) {
                winners.push_back(p.name);
            }
        }

        if (winners.size() == 1) {
            displayMessage("El ganador es: " + winners[0] + "!", WINNER_COLOR);
            beepSound();
            // Update ranking for the single winner
            updateRanking(winners[0]);
        } else {
            displayMessage("Empate entre los siguientes jugadores:", YELLOW_COLOR);
            for (const string& winnerName : winners) {
                displayMessage("- " + winnerName, YELLOW_COLOR);
                // Update ranking for all tied winners
                updateRanking(winnerName);
            }
            beepSound();
        }
    }
}

void displayMainMenu() {
    cout << "\n" << YELLOW_COLOR << "=========================" << RESET_COLOR << endl;
    cout << YELLOW_COLOR << "       BLACKJACK       " << RESET_COLOR << endl;
    cout << YELLOW_COLOR << "=========================" << RESET_COLOR << endl;
    cout << "1. Jugar contra el Dealer" << endl;
    cout << "2. Jugar Multijugador" << endl;
    cout << "3. Ver Usuarios (Trivia Scores)" << endl;
    cout << "4. Ver Ranking (Blackjack)" << endl;
    cout << "5. Reiniciar Ranking (Blackjack)" << endl;
    cout << "6. Salir" << endl;
    cout << "\nIngresa tu opcion: ";
}

void runBlackjack() {
    random_device rd;
    mt19937 rng(rd());

    if (rng == mt19937(0)) {
        rng.seed(static_cast<unsigned>(time(nullptr)));
    }

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
            case 3: showUsers(); break; // This should call displayUsers from persistence.cpp if that's what you mean by "Ver Usuarios" for Trivia Scores.
            case 4: displayRanking(); break;
            case 5: resetRanking(); break;
            case 6: displayMessage("Gracias por jugar a Blackjack. Hasta luego!", CYAN_COLOR); break;
            default: displayMessage("Opcion invalida.", RED_COLOR);
        }

        if (option != 6) {
            displayMessage("\nPresiona Enter para continuar...", YELLOW_COLOR);
            cin.get();
        }
    } while (option != 6);
}