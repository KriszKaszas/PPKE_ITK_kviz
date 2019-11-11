#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

#include <vector>
#include <map>

using namespace std;

class Player
{
public:
    Player(QString name);
    QString GetName();
    vector<map<QString, int>> GetScoreBoard();
    void SetScoreBoard(vector<map<QString, int>> scoreBoard);
private:
    QString name;
    vector<map<QString, int>> scoreBoard;
};

#endif // PLAYER_H
