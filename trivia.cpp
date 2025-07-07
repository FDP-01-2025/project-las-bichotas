#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
#include "preguntas.h"
using namespace std;
int opcion, puntaje = 0, puntajet = 0, puntajen = 0, juego, salir, us;
    char answer;
void jugarHistoria() {
     cout << "usted a seleccionado historia, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos. recuerde que sus respuestas deben ser en MAYUSCULAS" << endl;
                cout << "estas listo? Vamos!!!!" << endl;
                shuffle(preguntah.begin(), preguntah.end(), default_random_engine(time(0)));
                for (int i = 0; i <= 6; i++)
                {
                    cout << "pregunta numero: " << i + 1 << " " << preguntah[i].texto << endl;

                    for (int j = 0; j < preguntah[i].opciones.size(); j++)
                    {
                        cout << preguntah[i].opciones[j] << endl;
                    }
                    cin >> answer;
                    answer = toupper(answer);

                    if (answer == preguntah[i].respuesta)
                    {
                        cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                        puntaje += 10;
                    }
                    else
                    {
                        puntaje -= 5;
                        cout << "su respuesta es incorrecta " << -5 << " puntos" << endl;
                    }
                }
                cout << "su puntuacion es:" << puntaje << endl;
}

void jugarMusica() {
    cout << "usted a seleccionado Musica, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos." << endl;
                cout << "estas listo? Vamos!!!!" << endl;
                shuffle(preguntam.begin(), preguntam.end(), default_random_engine(time(0)));
                for (int i = 0; i <= 6; i++)
                {
                    cout << "pregunta numero: " << i + 1 << " " << preguntam[i].texto << endl;

                    for (int j = 0; j < preguntam[i].opciones.size(); j++)
                    {
                        cout << preguntam[i].opciones[j] << endl;
                    }
                    cin >> answer;
                    answer = toupper(answer);

                    if (answer == preguntam[i].respuesta)
                    {
                        cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                        puntaje += 10;
                    }
                    else
                    {
                        puntaje -= 5;
                        cout << "su respuesta es incorrecta " << -5 << " puntos" << endl;
                    }
                }
                cout << "su puntuacion es: " << puntaje << endl;
}

void jugarDeportes() {
    cout << "usted a seleccionado Deportes, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos." << endl;
                cout << "estas listo? Vamos!!!!" << endl;
                shuffle(preguntad.begin(), preguntad.end(), default_random_engine(time(0)));
                for (int i = 0; i <= 6; i++)
                {
                    cout << "pregunta numero:" << i + 1 << " " << preguntad[i].texto << endl;

                    for (int j = 0; j < preguntad[i].opciones.size(); j++)
                    {
                        cout << preguntad[i].opciones[j] << endl;
                    }
                    cin >> answer;
                    answer = toupper(answer);

                    if (answer == preguntad[i].respuesta)
                    {
                        cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                        puntaje += 10;
                    }
                    else
                    {
                        puntaje -= 5;
                        cout << "su respuesta es incorrecta " << -5 << " puntos" << endl;
                    }
                }
                cout << "su puntuacion es: " << puntaje << endl;
}

void jugarGeografia() {
    cout << "usted a seleccionado Geografia, debes responder 7 preguntas, las cuales tendran un puntaje de 10 por cada pregunta correcta, si no es el caso se restaran 5 puntos." << endl;
                cout << "estas listo? Vamos!!!!" << endl;
                shuffle(preguntag.begin(), preguntag.end(), default_random_engine(time(0)));
                for (int i = 0; i <= 6; i++)
                {
                    cout << "pregunta numero:" << i + 1 << " " << preguntag[i].texto << endl;

                    for (int j = 0; j < preguntag[i].opciones.size(); j++)
                    {
                        cout << preguntag[i].opciones[j] << endl;
                    }
                    cin >> answer;
                    answer = toupper(answer);

                    if (answer == preguntag[i].respuesta)
                    {
                        cout << "usted ha seleccionado la opcion correcta ha ganado 10 puntos" << endl;
                        puntaje += 10;
                    }
                    else
                    {
                        puntaje -= 5;
                        cout << "su respuesta es incorrecta " << -5 << " puntos" << endl;
                    }
                }
                cout << "su puntuacion es: " << puntaje << endl;
                cout << "su puntuacion es:" << puntaje << endl;
}