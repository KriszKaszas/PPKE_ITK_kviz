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
    void ReadDataFromLocalFile();
    QString ParseQuizTitle();
    vector<vector<QString>> ParseQuizQuestions();
    void SetUpLoadedQuiz();
    Quiz BrowseQuizFiles();
    void LoadQuizFromFile();
    void WritePlayerDataToFile();
    void WriteQuizToFile();
    Quiz *GetQuiz();
    void SetQuiz(QString title , vector<vector<QString>> questions);
    void CreateAppDefaultQuiz();
private:
    Quiz *currentQuiz;
    vector<QString> rawQuiz;
};

#endif // CONNECTION_H
