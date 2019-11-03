#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Player
{
public:
    Player(string name);
    string GetName();
    vector<map<string, int>> GetScoreBoard();
    void SetScoreBoard(vector<map<string, int>> scoreBoard);
private:
    string name;
    vector<map<string, int>> scoreBoard;
};

#endif // PLAYER_H
