#include "player.h"

Player::Player(QString name)
{
    this->name = name;
}

QString Player::GetName()
{
    return this->name;
}

void Player::SetScoreBoard(vector<map<QString, int>> scoreBoard)
{
    this->scoreBoard = scoreBoard;
}

vector<map<QString, int>> Player::GetScoreBoard()
{
    return this->scoreBoard;
}
