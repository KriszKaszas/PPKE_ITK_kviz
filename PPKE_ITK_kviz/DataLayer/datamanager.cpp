#include "datamanager.h"

DataManager::DataManager()
{
    connection = new Connection();
    connection->CreateAppDefaultQuiz();
    connection->SetUpLoadedQuiz();
}

Quiz *DataManager::GetQuiz()
{
    return connection->GetQuiz();
}

void DataManager::UpdateQuestions(QString title, vector<vector<QString>> questions)
{
    connection->SetQuiz(title, questions);
}
