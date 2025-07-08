#include "users.h" 
#include <iostream>  
#include <fstream>  
#include <vector>   
#include <string>   
#include <limits>    
#include <algorithm> 

using namespace std;

vector<User> users;
string currentName = "Ninguno";


const string USERS_FILE_NAME = "users.txt";

void saveUsers() {
    ofstream file(USERS_FILE_NAME);
    if (file.is_open()) {
        for (const User &user : users) {
            file << user.name << " " << user.score << endl;
        }
        file.close();
        cout << "Usuarios guardados exitosamente." << endl;
    } else {
        cerr << "Error: No se pudo abrir el archivo '" << USERS_FILE_NAME << "' para guardar usuarios." << endl;
    }
}

// Carga usuarios desde el archivo
void loadUsers() {
    users.clear();
    ifstream file(USERS_FILE_NAME);
    if (file.is_open()) {
        User u;
        while (file >> u.name >> u.score) {
            users.push_back(u);
        }
        file.close();
        cout << "Usuarios cargados exitosamente." << endl;
    } else {
        // Mensaje más informativo si el archivo no existe
        cout << "No se encontro el archivo de usuarios ('" << USERS_FILE_NAME << "'). Se creara uno nuevo si guardas." << endl;
    }
}

// Crea un nuevo usuario
void createUser() {
    string new_name;
    cout << "Ingrese el nombre del nuevo usuario (sin espacios): ";
   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, new_name); 
    // Verifica si ya existe un usuario con ese nombre
    for (const User& user : users) {
        if (user.name == new_name) {
            cout << "El usuario '" << new_name << "' ya existe. Por favor, elija otro nombre." << endl;
            return;
        }
    }

    // Crear y añadir el nuevo usuario
    users.push_back({new_name, 0}); // Inicializar con 0 puntos
    saveUsers(); // Guardar el nuevo usuario en el archivo

    currentName = new_name; // Establecerlo como usuario actual
    cout << "Usuario '" << new_name << "' creado y seleccionado con exito." << endl;
}

// Muestra todos los usuarios cargados en memoria
void showUsers() {
    if (users.empty()) {
        cout << "No hay usuarios registrados por el momento. Crea uno nuevo!" << endl;
        return;
    }
    cout << "\n--- Usuarios Disponibles ---" << endl;
    for (const User& u : users) {
        cout << "Nombre: " << u.name << " - Puntaje: " << u.score;
        if (u.name == currentName) {
            cout << " (Actual)"; // Indicar cuál es el usuario actualmente seleccionado
        }
        cout << endl;
    }
    cout << "--------------------------" << endl;
}

// Selecciona un usuario existente por nombre
void selectUser() {
    // cargar los usuarios antes de intentar seleccionarlos,
    // por si el vector 'users' no está actualizado.
    loadUsers();

    if (users.empty()) {
        cout << "No hay usuarios para seleccionar. Crea uno primero." << endl;
        return;
    }

    string searchName;
    cout << "Ingrese el nombre del usuario que quiere seleccionar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, searchName);

    bool found = false;
    for (const User& u : users) {
        if (searchName == u.name) {
            currentName = u.name; // Actualizar el usuario actual
            cout << "Usuario seleccionado: " << u.name << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Usuario '" << searchName << "' no encontrado." << endl;
    }
}

// Elimina un usuario por nombre
void deleteUser() {
    // Asegurarse de que los usuarios estén cargados antes de intentar eliminar
    loadUsers();

    if (users.empty()) {
        cout << "No hay usuarios para eliminar." << endl;
        return;
    }

    string deleteName;
    cout << "Ingrese el nombre de usuario que quiere eliminar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar búfer
    getline(cin, deleteName);

    // Usar el patrón erase-remove para eliminar elementos de un vector
    // std::remove_if reordena los elementos, y luego .erase() los elimina físicamente.
    auto it = remove_if(users.begin(), users.end(),
                        [&](const User& u) {
                            return u.name == deleteName;
                        });

    // Comprobar si se encontró y eliminó algún usuario
    if (it != users.end()) {
        users.erase(it, users.end()); 
        cout << "Usuario '" << deleteName << "' eliminado con exito." << endl;
        if (currentName == deleteName) {
            currentName = "Ninguno";
            cout << "El usuario actual ha sido restablecido a 'Ninguno'." << endl;
        }
        saveUsers(); 
    } else {
        cout << "Usuario '" << deleteName << "' no encontrado." << endl;
    }
}
