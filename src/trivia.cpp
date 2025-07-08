#include "trivia.h"
#include "preguntas.h"
#include "usuario.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
void continuar() {
    cout << "\nPresiona Enter para continuar..." << endl;
    cin.ignore();
    cin.get();
}
//funcionamiento principal del juego.
void jugarCategoria(vector<pregunta> &preguntas) {
    random_device rd;
    mt19937 rng(rd());
    char answer;
    int puntaje = 0, salir = 0;
       shuffle(preguntas.begin(), preguntas.end(), default_random_engine(time(0))); //shuffle y random, shuffle toma las preguntas de los vectores y las desordena para mostrarlas de manera aleatorea, 
       //random toma una variable cualquiera del vector y la muestra la cantidad de veces que deseamos la cual esta dada por el for

    for (int i = 0; i < 7; i++) {
        cout << "Pregunta " << i + 1 << ": " << preguntas[i].texto << endl;
        for (const auto &opcion : preguntas[i].opciones) {
            cout << opcion << endl;
        }
        cin >> answer;
        answer = toupper(answer);

        if (answer == preguntas[i].respuesta) {
            cout << "Respuesta correcta +10 puntos\n";
            puntaje += 10;
        } else {
            cout << "Respuesta incorrecta -5 puntos\n";
            puntaje -= 5;
        }
    }

    for (Usuario &u : usuarios) {
        if (u.name == name) {
            u.puntaje += puntaje;
            cout << "Nuevo puntaje: " << u.puntaje << endl;
            break;
        }
    }
    guardarUsuarios();
    puntaje = 0;
    continuar();
                cout << "regresando al menu principal!!!" << endl;
}

void jugarHistoria() { jugarCategoria(preguntah); }
void jugarMusica() { jugarCategoria(preguntam); }
void jugarDeportes() { jugarCategoria(preguntad); }
void jugarGeografia() { jugarCategoria(preguntag); }
