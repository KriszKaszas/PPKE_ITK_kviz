#include "connection.h"

Connection::Connection()
{
    SetTestQuiz();
}

















Quiz *Connection::GetTestQuiz()
{
    return testQuiz;
}


void Connection::SetTestQuiz()
{
    QString localTestQuizTitle = "Test Quiz";
    vector<vector<QString>> localTestQuizQuestions = {
        {
            {"Can I Code?", "yes", "no", "maybe", "dunno", "A"},
            {"What am I doing?", "dunno", "bullshit", "something sensible", "coding like a god", "D"},
            {"What is C++?", "Something beyond our comprehension", "A lovely passtime", "The language of the gods", "Living hell", "C"}
        }
    };
    testQuiz = new Quiz(localTestQuizTitle, localTestQuizQuestions);
}
