#include "trivia.h"    
#include "questions.h" 
#include "users.h"    
#include <iostream>   
#include <algorithm>  
#include <random>      
#include <limits>      
#include <vector>      

extern std::string currentName;

extern std::vector<User> users;

void saveUsers();

void pressContinue() {
    std::cout << "\nPresiona Enter para continuar..." << std::endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 
}


void playCategory(std::vector<Question> &questions) {
    std::random_device rd;
    std::mt19937 rng(rd()); 
    char respuesta_char;   
    int puntaje_actual = 0;

    int num_preguntas_a_jugar = std::min((int)questions.size(), 7);

    std::shuffle(questions.begin(), questions.end(), rng);

    for (int i = 0; i < num_preguntas_a_jugar; ++i) {
        std::cout << "\n--- Pregunta " << i + 1 << " ---" << std::endl;
        std::cout << questions[i].text << std::endl;

        for (const auto &opcion : questions[i].options) {
            std::cout << opcion << std::endl;
        }

        std::cout << "Tu respuesta: ";
        // Bucle para un manejo robusto de la entrada del usuario
        while (!(std::cin >> respuesta_char) || (std::toupper(respuesta_char) < 'A' || std::toupper(respuesta_char) > 'D')) {
            std::cout << "Entrada invalida. Por favor, ingresa A, B, C o D: ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada inválida
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        respuesta_char = std::toupper(respuesta_char); // Convertir la respuesta a mayúsculas para una comparación consistente

        // Comparar la respuesta del usuario con la respuesta correcta (también convertida a mayúsculas)
        if (respuesta_char == std::toupper(questions[i].answer)) {
            std::cout << "Respuesta correcta! +10 puntos\n";
            puntaje_actual += 10;
        } else {
            std::cout << "Respuesta incorrecta. -5 puntos\n";
            std::cout << "La respuesta correcta era: " << questions[i].answer << std::endl;
            puntaje_actual -= 5;
        }
    }

    // Actualizar el puntaje del usuario actual
    bool usuario_encontrado = false;
    for (User &u : users) {
        if (u.name == currentName) {
            u.score += puntaje_actual; // Añadir los puntos de esta ronda al puntaje total del usuario
            std::cout << "\nTu puntaje en esta categoria: " << puntaje_actual << std::endl;
            std::cout << "Puntaje total de " << u.name << ": " << u.score << std::endl;
            usuario_encontrado = true;
            break;
        }
    }

    // Mensaje de error si el usuario actual no fue encontrado
    if (!usuario_encontrado) {
        std::cout << "\nError: Usuario actual no encontrado en la lista de usuarios." << std::endl;
    }

    saveUsers(); // Guardar los puntajes de usuario actualizados

    pressContinue();
    std::cout << "Regresando al menú principal..." << std::endl;
}


void playHistory() { playCategory(historyQuestions); }    
void playMusic() { playCategory(musicQuestions); }
void playSports() { playCategory(sportsQuestions); }
void playGeography() { playCategory(geographyQuestions); }