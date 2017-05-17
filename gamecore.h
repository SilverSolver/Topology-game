#ifndef GAMECORE_H
#define GAMECORE_H

#include <QtGui>
#include <gameboard.h>
#include <player.h>
#include <pathswitch.h>

class GameCore : public QObject
{
    Q_OBJECT

public:
    // Тут планируется реализовать игровую логику -
    // какие взаимодействия между объектами возможны, а также взаимодействие с интерфейсом
    GameCore(GameBoard* gameBoard = NULL);

    GameBoard*  gameBoard;
signals:
    void levelComplete();
    void fieldChanged();
public slots:
    void getPlayerMove(int direction);
    void getPlayerAction();
    void getTrigger();
};

#endif // GAMECORE_H
