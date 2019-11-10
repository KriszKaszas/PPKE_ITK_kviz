#include "gameengine.h"

GameEngine::GameEngine()
{
    datamanager = new DataManager();
    quizGame = new QuizGame(datamanager->GetQuiz());
}

