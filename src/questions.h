#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <vector>
#include <string>
using namespace std;

struct Question {
    string text;
    vector<string> options;
    char answer;
};
// aqui se declaran los vectores para solo ser llamados como funcion en el main
extern vector<Question> historyQuestions;
extern vector<Question> musicQuestions;
extern vector<Question> sportsQuestions;
extern vector<Question> geographyQuestions;

#endif
