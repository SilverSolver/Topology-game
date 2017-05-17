#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player
{
public:
    Player();
    Player(int x, int y);   //Можно создавать игрока с известными координатами

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveTo(int xNew, int yNew);
    void action();

    int x();
    int y();                //Можно узнавать положение игрока

private:
    Player(const Player&);  //Запрет копирования

    int xPos;
    int yPos;
};

#endif // PLAYER_H
