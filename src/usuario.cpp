#include "usuario.h"
#include <iostream>
#include <fstream>
using namespace std;

vector<Usuario> usuarios;
string name = "";

void guardarUsuarios() {ofstream archivo("usuario.txt");
    if (archivo.is_open())
    {
        for (const Usuario &user : usuarios)
        {
            archivo << user.name << " " << user.puntaje << endl;
        }
        archivo.close();
    }}
void crearUSUARIO() { Usuario u;
    cout << "Nombre de usuario, sin espacios :( : ";
    cin >> u.name;
    u.puntaje = 0;

    usuarios.push_back(u);
    guardarUsuarios();
    
    name = u.name ;
    cout << "Usuario creado con exito" << endl; }
void cargarUsuarios() { usuarios.clear();
    ifstream archivo("usuario.txt");
    if (archivo.is_open())
    {
        Usuario u;
        while (archivo >> u.name >> u.puntaje)
        {
            usuarios.push_back(u);
        }
        archivo.close();
    }
    else
    {
        cout << "usuarios no encontrados" << endl;
    } }
void mostrarUSUARIO() { ifstream archivo("usuario.txt");
    Usuario u;

    if (archivo.is_open())
    {
        cout << "--- Usuarios Disponibles ---" << endl;
        while (archivo >> u.name >> u.puntaje)
        {
            cout << "Nombre de Usuario: " << u.name << " y su puntaje es: " << u.puntaje << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No hay usuarios creados por el momento\n";
    } }
void seleccionarUsuario() { cargarUsuarios();
    string buscarN;
    cout << "Ingrese el nombre del usuario que quiere seleccionar: ";
    cin >> buscarN;

    ifstream archivo("usuario.txt");
    Usuario u;

    if (archivo.is_open())
    {
        while (archivo >> u.name >> u.puntaje)
        {
            if (buscarN == u.name)
            {
                name = u.name;
                cout << "Usuario seleccionado: " << u.name << endl;
                archivo.close();
                return;
            }
        }
        archivo.close();
        cout << "Usuario no encontrado" << endl;
        return;
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    } }
void eliminarUsuario() { int usuariosA, usuariosD;
    string eliminarN;
    cout << "Ingrese el nombre de ususario que quiere eliminar: ";
    cin >> eliminarN;

    vector<Usuario> usuariosN;

    ifstream archivo("usuario.txt");
    Usuario u;
    int encontrado = 0;

    if (archivo.is_open())
    {
        while (archivo >> u.name >> u.puntaje)
        {
            if (u.name != eliminarN)
            {
                usuariosN.push_back(u);
            }
            else
            {
                encontrado++;
            }
        }
        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    ofstream archivoNuevo("usuario.txt");
    if (archivoNuevo.is_open())
    {
        for (const Usuario &user : usuariosN)
        {
            archivoNuevo << user.name << " " << user.puntaje << endl;
        }
        archivoNuevo.close();

        if (encontrado == 0)
        {
            cout << "Usuario no encontrado " << endl;
        }
        else
        {
            cout << "Usuario eliminado con exito" << endl;
        }
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    } }
void pausa(vector<Usuario> &usuarios, int &salir) { int opcion;
    cout << "--- JUEGO EN PAUSA ---" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Continuar" << endl;
    cout << "2. Guardar y salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Continuando el juego..." << endl;
        salir = 0;
        break;
    case 2:
        guardarUsuarios();
        cout << "Datos guardados. Saliendo del juego..." << endl;
        exit(0);
        break;
    default:
        cout << "Opción inválida. El juego continuará automáticamente." << endl;
        salir = 0;
        break;
    } }
