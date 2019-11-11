#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include "player.h"
#include "quiz.h"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <map>
#include <vector>

using namespace std;

class Connection
{
public:
    Connection();
    Player ReadPlayerDataFromFile();

    void SetUpLoadedQuiz();
    void SaveQuiz();
    Quiz BrowseQuizFiles();
    void LoadQuizFromFile();
    Quiz *GetQuiz();
    void SetQuiz(QString title , vector<vector<QString>> questions);
    void CreateAppDefaultQuiz();
private:
    void ReadDataFromLocalFile();
    QString ParseQuizTitle();
    vector<vector<QString>> ParseQuizQuestions();
    void ReverseParseQuiz();
    void WritePlayerDataToFile();
    void WriteDataToLocalFile();
    Quiz *currentQuiz;
    vector<QString> rawQuiz;
};

#endif // CONNECTION_H
