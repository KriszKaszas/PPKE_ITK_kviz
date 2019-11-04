#include "quizgame.h"

QuizGame::QuizGame(Quiz *quiz)
{
    this->quiz = quiz;
    currentQuestionIndex = 0;
    score = 0;
}

//Adatok Kinyerése
//QString QuizGame::GetQuizTitle()
//{
//    return quiz->GetTitle();
//}

//QString QuizGame::GetNextQuizQuestion(int currentQuestionIndex)
//{
//    map<QString, vector<QString>> question = quiz->GetQuestions()[static_cast<unsigned long long int>(currentQuestionIndex)];
//    if(!question.empty())
//    {
//        return question.begin()->first;
//    }
//    else
//    {
//        return "Ehhez a kérdéshez nem található megnevezés";
//    }
//}

//vector<QString> QuizGame::GetNextQuizAnswers()
//{
//    vector<QString> error = {"Ehhez a kérdéshez nem található válaszlehetőség"};
//    map<QString, vector<QString>> question = quiz->GetQuestions()[static_cast<unsigned long long int>(currentQuestionIndex)];
//    if(!question.empty())
//    {
//        return question.begin()->second;
//    }
//    else
//    {
//        return error;
//    }
//}

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
    return currentQuestionIndex == quiz->GetQuestions().size();
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
