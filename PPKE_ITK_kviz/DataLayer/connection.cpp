#include "connection.h"

Connection::Connection()
{
    currentQuiz = new Quiz();
    CreateDefaultQuiz();
}

Quiz *Connection::GetQuiz()
{
    return currentQuiz;
}


void Connection::SetQuiz(QString title, vector<vector<QString>> questions)
{
    currentQuiz->SetTitle(title);
    currentQuiz->SetQuestions(questions);
}

void Connection::CreateDefaultQuiz()
{
    QString localTestQuizTitle = "Test Quiz";
    vector<vector<QString>> localTestQuizQuestions =
        {
            {"Can I Code?", "yes", "no", "maybe", "dunno", "A"},
            {"What am I doing?", "dunno", "bullshit", "something sensible", "coding like a god", "D"},
            {"What is C++?", "Something beyond our comprehension", "A lovely passtime", "The language of the gods", "Living hell", "C"}
        };
    currentQuiz->SetTitle(localTestQuizTitle);
    currentQuiz->SetQuestions(localTestQuizQuestions);
}
