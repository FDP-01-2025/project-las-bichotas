#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
using namespace std;

struct User {
    string name;
    int score;
};

extern vector<User> users;
extern string currentName;

void createUser();
void showUsers();
void selectUser();
void deleteUser();
void saveUsers();
void loadUsers();
void pauseGame(vector<User> &users, int &exitFlag);

#endif
