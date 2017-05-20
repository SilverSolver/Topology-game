#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();
    Player(int x, int y);
    int x();
    int y();
    void moveTo(int newX, int newY);
private:
    int xPos;
    int yPos;
};

#endif // PLAYER_H
