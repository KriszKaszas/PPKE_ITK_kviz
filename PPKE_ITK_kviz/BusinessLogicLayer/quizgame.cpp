#include "quizgame.h"

QuizGame::QuizGame(Quiz *quiz)
{
    this->quiz = quiz;
    currentQuestionIndex = 0;
    score = 0;
}

void QuizGame::SetQuiz(Quiz *newQuiz)
{
    quiz = newQuiz;
}

QString QuizGame::GetQuizTitle()
{
    return quiz->GetTitle();
}

vector<QString> QuizGame::GetNextQuizQuestion()
{
    return quiz->GetQuestions()[static_cast<unsigned long long int>(currentQuestionIndex)];
}

QString QuizGame::GetCurrentQuestionNumberToQString()
{
    return QString::number(currentQuestionIndex+1);
}

QString QuizGame::GetQuestionNumberFromTotalToString()
{
    QString numberFromTotal = GetCurrentQuestionNumberToQString() + "/" + QString::number(quiz->GetQuestions().size());
    return numberFromTotal;
}

QString QuizGame::GetScoreToQString()
{
    return QString::number(score);
}


//Játékműködés

void QuizGame::Behavior(QString answer)
{
    if(answer == quiz->GetQuestions()[static_cast<unsigned long long int>(currentQuestionIndex)][5])
    {
        score++;
    }
    currentQuestionIndex++;
}

bool QuizGame::IsGameOver()
{
    return static_cast<unsigned long long int>(currentQuestionIndex) == quiz->GetQuestions().size();
}

void QuizGame::ResetValues()
{
    score = 0;
    currentQuestionIndex = 0;
}

int QuizGame::ReturnQuestionListLength()
{
    return quiz->GetQuestions().size();
}

vector<vector<QString>> QuizGame::GetAllQuestions()
{
    return quiz->GetQuestions();
}
