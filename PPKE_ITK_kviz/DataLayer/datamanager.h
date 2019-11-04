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
    Connection *connection;
};

#endif // DATAMANAGER_H
