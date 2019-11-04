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
};

#endif // GAMEENGINE_H
