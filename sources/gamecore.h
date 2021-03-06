#ifndef GAMECORE_H
#define GAMECORE_H

#include <QString>
#include <sources/gameboard.h>
#include <sources/player.h>
#include <sources/pathswitch.h>
#include <sources/levelbuilder.h>

class GameCore : public QObject
{
    Q_OBJECT

public:
    // Тут планируется реализовать игровую логику -
    // какие взаимодействия между объектами возможны, а также взаимодействие с интерфейсом
    GameCore(GameBoard* gameBoard = NULL, LevelBuilder* builder = NULL);

    GameBoard*      gameBoard;
    LevelBuilder*   levelBuilder;
signals:
    void levelComplete();
    void fieldChanged();
public slots:
    void getPlayerMove(int direction);
    void getPlayerAction();
    void getTrigger();
    void setUpLevel(int levelNum);
};

#endif // GAMECORE_H
