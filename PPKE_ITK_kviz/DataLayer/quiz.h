#ifndef QUIZ_H
#define QUIZ_H

#include <QString>

#include <vector>

using namespace std;

class Quiz
{
public:
    Quiz(QString title, vector<vector<QString>> questions);
    void AddQuestion(vector<QString> question);
    QString GetTitle();
    void SetTitle(QString title);
    vector<vector<QString>> GetQuestions();
private:
    QString title;
    vector<vector<QString>> questions;

};

#endif // QUIZ_H
