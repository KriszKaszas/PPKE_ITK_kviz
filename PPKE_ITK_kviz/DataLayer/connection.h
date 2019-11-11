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
    void SetFilePath(QString filepath);
    void LoadQuizFromFile();
    Quiz *GetQuiz();
    void SetQuiz(QString title , vector<vector<QString>> questions);
    void CreateAppDefaultQuiz();
    void ReadDataFromLocalFile();
    void SetScore(vector<QString> score);

private:
    QString filepath;
    QString ParseQuizTitle();
    vector<vector<QString>> ParseQuizQuestions();
    void ReverseParseQuiz();
    void WritePlayerDataToFile();
    void WriteDataToLocalFile();
    Quiz *currentQuiz;
    vector<QString> rawQuiz;
    vector<QString> score;
};

#endif // CONNECTION_H
