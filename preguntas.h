<<<<<<< HEAD
#ifndef TRIVIA_H
#define TRIVIA_H

void jugarHistoria();
void jugarMusica();
void jugarDeportes();
void jugarGeografia();

#endif
=======
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
>>>>>>> 7759191501c07ddc739855e49b73406249c6c9bf
