#ifndef CONNECTION_H
#define CONNECTION_H

#include "player.h"
#include "quiz.h"

#include <QString>

#include <map>
#include <vector>

using namespace std;

class Connection
{
public:
    Connection();
    Player ReadPlayerDataFromFile();
    Quiz ReadQuizFromLocalFile();
    Quiz BrowseQuizFiles();
    void WritePlayerDataToFile();
    void WriteQuizToFile();
    Quiz *GetTestQuiz();
    void SetTestQuiz();
private:
    Quiz *testQuiz;
};

#endif // CONNECTION_H
