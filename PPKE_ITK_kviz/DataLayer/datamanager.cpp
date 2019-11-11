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

void DataManager::SaveQuiz()
{
    connection->SaveQuiz();
}

void DataManager::SetFilePath(QString filepath)
{
    connection->SetFilePath(filepath);
}

void DataManager::LoadDataFromLocalFile()
{
    connection->ReadDataFromLocalFile();
    connection->SetUpLoadedQuiz();
}

void DataManager::SetScore(vector<QString> score)
{
    connection->SetScore(score);
}
