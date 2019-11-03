#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Quiz
{
public:
    Quiz();
    void AddQuestion();
    string GetTitle();
    void SetTitle();
    vector<map<string, vector<string>>> GetQuestions();
private:
    string title;
    vector<map<string, vector<string>>> questions;

};

#endif // QUIZ_H
