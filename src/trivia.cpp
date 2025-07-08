#include "trivia.h"    // Se asume que contiene la definición de la estructura/clase Question
#include "questions.h" // Se asume que contiene los vectores historyQuestions, musicQuestions, etc.
#include "users.h"     // Se asume que contiene la estructura/clase User y el vector 'users'
#include <iostream>    // Para entrada/salida estándar (cout, cin)
#include <algorithm>   // Para std::shuffle
#include <random>      // Para std::random_device, std::mt19937
#include <limits>      // Para std::numeric_limits
#include <vector>      // Asegúrate de incluir vector si no está en otras cabeceras

// Se declara en otro lugar, probablemente en users.h o en un ámbito global.
extern std::string currentName;
// Asumiendo que el vector 'users' está declarado en users.h
extern std::vector<User> users;

// Función para guardar los datos de los usuarios, definida en otro lugar (ej. en users.cpp)
void saveUsers();

// Función para pausar la ejecución y esperar que el usuario presione Enter
void pressContinue() {
    std::cout << "\nPresiona Enter para continuar..." << std::endl;
    // Limpia el búfer de entrada.
    // numeric_limits<streamsize>::max() asegura que se ignoran todos los caracteres hasta el salto de línea.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Espera un carácter de nueva línea (tecla Enter)
}

// Funcionamiento principal del juego para una categoría específica.
void playCategory(std::vector<Question> &questions) {
    // Usa std::random_device para una semilla no determinista para el motor Mersenne Twister.
    std::random_device rd;
    std::mt19937 rng(rd()); // Sembrar el generador de números aleatorios
    char respuesta_char;    // Usar un nombre de variable diferente para evitar confusión con la respuesta correcta
    int puntaje_actual = 0; // Inicializar el puntaje para la ronda/categoría actual

    // Mezclar las preguntas usando el motor Mersenne Twister para una mejor aleatoriedad.
    // Usar std::min para asegurar que no intentamos jugar más preguntas de las disponibles.
    int num_preguntas_a_jugar = std::min((int)questions.size(), 7); // Jugar un máximo de 7 preguntas o todas si hay menos de 7

    std::shuffle(questions.begin(), questions.end(), rng);

    for (int i = 0; i < num_preguntas_a_jugar; ++i) {
        std::cout << "\n--- Pregunta " << i + 1 << " ---" << std::endl;
        std::cout << questions[i].text << std::endl;

        for (const auto &opcion : questions[i].options) {
            std::cout << opcion << std::endl;
        }

        std::cout << "Tu respuesta (A, B, C, D): ";
        // Bucle para un manejo robusto de la entrada del usuario
        while (!(std::cin >> respuesta_char) || (std::toupper(respuesta_char) < 'A' || std::toupper(respuesta_char) > 'D')) {
            std::cout << "Entrada inválida. Por favor, ingresa A, B, C o D: ";
            std::cin.clear(); // Limpiar el indicador de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar entrada inválida
        }

        // Limpiar el carácter de nueva línea restante después de leer 'respuesta_char'
        // para prevenir problemas con entradas subsiguientes.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        respuesta_char = std::toupper(respuesta_char); // Convertir la respuesta a mayúsculas para una comparación consistente

        // Comparar la respuesta del usuario con la respuesta correcta (también convertida a mayúsculas)
        if (respuesta_char == std::toupper(questions[i].correct_answer)) {
            std::cout << "¡Respuesta correcta! +10 puntos\n";
            puntaje_actual += 10;
        } else {
            std::cout << "Respuesta incorrecta. -5 puntos\n";
            std::cout << "La respuesta correcta era: " << questions[i].correct_answer << std::endl;
            puntaje_actual -= 5;
        }
    }

    // Actualizar el puntaje del usuario actual
    bool usuario_encontrado = false;
    for (User &u : users) {
        if (u.name == currentName) {
            u.score += puntaje_actual; // Añadir los puntos de esta ronda al puntaje total del usuario
            std::cout << "\nTu puntaje en esta categoría: " << puntaje_actual << std::endl;
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

    // No es necesario reiniciar 'puntaje_actual' aquí, ya que es una variable local
    // y se reinicializará en la próxima llamada a la función.

    pressContinue();
    std::cout << "Regresando al menú principal..." << std::endl;
}

// Funciones envoltorio para cada categoría de preguntas
void playHistory() { playCategory(historyQuestions); }    // Jugar preguntas de historia
void playMusic() { playCategory(musicQuestions); }      // Jugar preguntas de música
void playSports() { playCategory(sportsQuestions); }    // Jugar preguntas de deportes
void playGeography() { playCategory(geographyQuestions); } // Jugar preguntas de geografía