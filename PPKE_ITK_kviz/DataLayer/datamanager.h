#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "connection.h"

#include "player.h"
#include "quiz.h"

#include <QString>

#include <map>
#include <vector>

using namespace std;

class DataManager
{
public:
    DataManager();
    Quiz *GetQuiz();
    void UpdateQuestions(QString title, vector<vector<QString>> questions);
    void SaveQuiz();
    void SetFilePath(QString filepath);
    void LoadDataFromLocalFile();
    void SetScore(vector<QString> score);
private:
    Connection *connection;
};

#endif // DATAMANAGER_H
