#include "quiz.h"

Quiz::Quiz()
{
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

void Quiz::SetQuestions(vector<vector<QString> > questions)
{
    this->questions = questions;
}
