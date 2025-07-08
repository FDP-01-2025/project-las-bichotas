#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <string>
using namespace std;

struct Usuario {
    string name;
    int puntaje;
};

extern vector<Usuario> usuarios;
extern string name;

void crearUSUARIO();
void mostrarUSUARIO();
void seleccionarUsuario();
void eliminarUsuario();
void guardarUsuarios();
void cargarUsuarios();
void pausa(vector<Usuario> &usuarios, int &salir);

#endif
