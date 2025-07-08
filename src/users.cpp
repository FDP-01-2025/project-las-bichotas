#include "users.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef USER_DEFINED
#define USER_DEFINED
struct User {
    std::string name;
    int score;
};
#endif

using namespace std;

vector<User> users;
string currentName = "";

// Guarda los usuarios en archivo "usuario.txt"
void saveUsers() {
    ofstream file("users.txt");
    if (file.is_open()) {
        for (const User &user : users) {
            file << user.name << " " << user.score << endl;
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para guardar usuarios." << endl;
    }
}

// Crea un nuevo usuario
void createUser() {
    User u;
    cout << "Nombre de usuario, sin espacios: ";
    cin >> u.name;
    u.score = 0;

    // Verifica si ya existe usuario con ese nombre
    for (const User& user : users) {
        if (user.name == u.name) {
            cout << "El usuario ya existe." << endl;
            return;
        }
    }

    users.push_back(u);
    saveUsers();

    currentName = u.name;
    cout << "Usuario creado con exito" << endl;
}

// Carga usuarios desde archivo
void loadUsers() {
    users.clear();
    ifstream file("users.txt");
    if (file.is_open()) {
        User u;
        while (file >> u.name >> u.score) {
            users.push_back(u);
        }
        file.close();
    } else {
        cout << "No hay usuarios guardados todavia. Crea uno nuevo!" << endl;
    }
}

// Muestra todos los usuarios
void showUsers() {
    ifstream file("users.txt");
    User u;

    if (file.is_open()) {
        cout << "--- Usuarios Disponibles ---" << endl;
        bool hasUsers = false;
        while (file >> u.name >> u.score) {
            cout << "Nombre de Usuario: " << u.name << " - Puntaje: " << u.score << endl;
            hasUsers = true;
        }
        if (!hasUsers) {
            cout << "No hay usuarios creados por el momento.\n";
        }
        file.close();
    } else {
        cout << "No hay usuarios creados por el momento.\n";
    }
}

// Selecciona un usuario por nombre
void selectUser() {
    loadUsers();
    string searchName;
    cout << "Ingrese el nombre del usuario que quiere seleccionar: ";
    cin >> searchName;

    bool found = false;
    for (const User& u : users) {
        if (searchName == u.name) {
            currentName = u.name;
            cout << "Usuario seleccionado: " << u.name << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Usuario no encontrado" << endl;
    }
}

// Elimina un usuario por nombre
void deleteUser() {
    string deleteName;
    cout << "Ingrese el nombre de usuario que quiere eliminar: ";
    cin >> deleteName;

    vector<User> newUsers;
    bool found = false;

    for (const User& u : users) {
        if (u.name != deleteName) {
            newUsers.push_back(u);
        } else {
            found = true;
        }
    }

    if (!found) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    users = newUsers;
    saveUsers();
    cout << "Usuario eliminado con exito." << endl;
}

// Pausa el juego con opciones para continuar o guardar y salir
void pauseGame(vector<User>& users, int& exitFlag) {
    int option;
    cout << "--- JUEGO EN PAUSA ---" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Continuar" << endl;
    cout << "2. Guardar y salir" << endl;
    cin >> option;

    switch (option) {
        case 1:
            cout << "Continuando el juego..." << endl;
            exitFlag = 0;
            break;
        case 2:
            saveUsers();
            cout << "Datos guardados. Saliendo del juego..." << endl;
            exit(0);
            break;
        default:
            cout << "Opción invalida. El juego continuara automaticamente." << endl;
            exitFlag = 0;
            break;
    }
}
