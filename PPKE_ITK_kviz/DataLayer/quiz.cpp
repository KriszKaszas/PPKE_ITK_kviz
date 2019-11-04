#include "quiz.h"

Quiz::Quiz(QString title, vector<vector<QString>> questions)
{
    this->title = title;
    this->questions = questions;
}

void Quiz::AddQuestion(vector<QString> question)
{
   questions.push_back(question);
}

QString Quiz::GetTitle()
{
    return title;
}

void Quiz::SetTitle(QString title)
{
    this->title = title;
}

vector<vector<QString>> Quiz::GetQuestions()
{
    return questions;
}
