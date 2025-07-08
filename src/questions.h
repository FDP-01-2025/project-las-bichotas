#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector> 

struct Question {
    std::string text;              
    std::vector<std::string> options; 
    char answer;           
};

extern std::vector<Question> historyQuestions;
extern std::vector<Question> musicQuestions;
extern std::vector<Question> sportsQuestions;
extern std::vector<Question> geographyQuestions;

#endif 
