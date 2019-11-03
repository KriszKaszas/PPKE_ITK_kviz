#include "player.h"

Player::Player(string name)
{
    this->name = name;
}

string Player::GetName()
{
    return this->name;
}

void Player::SetScoreBoard(vector<map<string, int>> scoreBoard)
{
    this->scoreBoard = scoreBoard;
}

vector<map<string, int>> Player::GetScoreBoard()
{
    return this->scoreBoard;
}
