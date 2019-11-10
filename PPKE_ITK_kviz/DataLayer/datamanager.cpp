#include "datamanager.h"

DataManager::DataManager()
{
    connection = new Connection();
    connection->CreateDefaultQuiz();
}

Quiz *DataManager::GetQuiz()
{
    return connection->GetQuiz();
}

void DataManager::UpdateQuestions(QString title, vector<vector<QString>> questions)
{
    connection->SetQuiz(title, questions);
}
