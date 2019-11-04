#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "DataLayer/quiz.h"

#include <QString>
#include <vector>

class QuizGame
{
public:
    QuizGame(Quiz *quiz);
    QString GetScoreToQString();
    QString GetQuizTitle();
    vector<QString> GetNextQuizQuestion();
    void Behavior(QString answer);
    QString GetCurrentQuestionNumberToQString();
    QString GetQuestionNumberFromTotalToString();
    bool IsGameOver();
    void ResetValues();
    int ReturnQuestionListLength();
    vector<vector<QString>> GetAllQuestions();
private:
    Quiz *quiz;
    int currentQuestionIndex;
    int score;
};

#endif // QUIZGAME_H
