#include "gameengine.h"

GameEngine::GameEngine()
{
    datamanager = new DataManager();
    quizGame = new QuizGame(datamanager->GetQuiz());
}

void GameEngine::setQuiz(Quiz *quiz)
{
    quizGame->SetQuiz(quiz);
}

void GameEngine::SetScore(vector<QString> score)
{
    datamanager->SetScore(score);
}
