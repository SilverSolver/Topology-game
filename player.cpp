#include "player.h"

Player::Player()
{
    this->xPos = -1;
    this->yPos = -1;
}

Player::Player(int x, int y)
{
    this->xPos = x;
    this->yPos = y;
}

int Player::x()
{
    return xPos;
}

int Player::y()
{
    return yPos;
}

void Player::moveTo(int xNew, int yNew)
{
    this->xPos = xNew;
    this->yPos = yNew;
}
