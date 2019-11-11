#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "DataLayer/datamanager.h"
#include "DataLayer/quiz.h"
#include "quizgame.h"

using namespace std;

class GameEngine
{
public:
    GameEngine();
    DataManager *datamanager;
    QuizGame *quizGame;
    void setQuiz(Quiz *quiz);
    void SetScore(vector<QString> score);
};

#endif // GAMEENGINE_H
