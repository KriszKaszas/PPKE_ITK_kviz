#ifndef QUIZ_H
#define QUIZ_H

#include <QString>

#include <vector>

using namespace std;

class Quiz
{
public:
    Quiz();
    void AddQuestion(vector<QString> question);
    QString GetTitle();
    void SetTitle(QString title);
    void SetQuestions(vector<vector<QString>> questions);
    vector<vector<QString>> GetQuestions();
private:
    QString title;
    vector<vector<QString>> questions;

};

#endif // QUIZ_H
