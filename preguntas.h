#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <vector>
#include <string>
using namespace std;

struct pregunta {
    string texto;
    vector<string> opciones;
    char respuesta;
};


extern vector<pregunta> preguntah;
extern vector<pregunta> preguntam;
extern vector<pregunta> preguntad;
extern vector<pregunta> preguntag;

#endif
