#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "player.h"
#include "quiz.h"
#include <string>
#include <map>
#include <vector>

using namespace std;

class DataManager
{
public:
    DataManager();
    Player ReadPlayerDataFromFile();
    Quiz ReadQuizFromFile();
    void WritePlayerDataToFile();
    void WriteQuizToFile();
};

#endif // DATAMANAGER_H
