#include "gamecore.h"
#include <QDebug>

GameCore::GameCore(GameBoard *gameBoard) : QObject()
{
    this->gameBoard = gameBoard;
    for (auto s : gameBoard->switches)
        QObject::connect(s, SIGNAL(iWasTriggered()), this, SLOT(getTrigger()));
}

void GameCore::getPlayerMove(int direction)
{
    //qDebug() << "handling " << direction << " move";
    int playerX = this->gameBoard->player.x();
    int playerY = this->gameBoard->player.y();
    int newX = playerX;
    int newY = playerY;
    //qDebug() << playerX << playerY;
    Cell cell(gameBoard->field[playerY][playerX]);

    bool isTeleportMove = false;    // Флаг - будет ли игрок телепортиться этим ходом

    // Посмотрим, куда игрок хочет переместиться
    switch (direction)
    {
    case UP:
    {
        if (cell.hasWormHole != UP)
            newY = playerY - 1;
        else
            isTeleportMove = true;
        break;
    }
    case DOWN:
    {
        if (cell.hasWormHole != DOWN)
            newY = playerY + 1;
        else
            isTeleportMove = true;
        break;
    }
    case LEFT:
    {
        if (cell.hasWormHole != LEFT)
            newX = playerX - 1;
        else
            isTeleportMove = true;
        break;
    }
    case RIGHT:
    {
        if (cell.hasWormHole != RIGHT)
           newX = playerX + 1;
        else
            isTeleportMove = true;
        break;
    }
    default:
        break;
    }

    if (isTeleportMove == true)
    {
        for (auto s : gameBoard->switches)
        {
            if (s->curSource.first  == playerX &&
                s->curSource.second == playerY)
            {
                newX = s->curDest.first;
                newY = s->curDest.second;
            }
            if (s->curDest.first  == playerX &&
                s->curDest.second == playerY)
            {
                newX = s->curSource.first;
                newY = s->curSource.second;
            }
        }
    }

    qDebug() << newX << newY;
    // Проверим, может ли он переместиться в избранную ячейку
    if (newX < 0 || newY < 0 ||
            newX >= gameBoard->field[0].size() || newY >= gameBoard->field.size())
        return; // Не может, если вышел за края поля

    Cell* newCell = &(gameBoard->field[newY][newX]);
    //qDebug() << "cell type " << newCell->type;
    //qDebug() << "wormHole  " << newCell->hasWormHole;

    if (newCell->type != 1)
    {
        //qDebug() << "Received player turn";
        gameBoard->player.moveTo(newX, newY);
        fieldChanged();
    }
    if (newCell->type == 2)
    {
        levelComplete();
    }
}

void GameCore::getPlayerAction()
{
    qDebug() << "action";
    for (auto s : gameBoard->switches)
    {
        if (s->x() == gameBoard->player.x() and s->y() == gameBoard->player.y())
        {
            qDebug() << "trigger";
            s->trigger();
        }
    }
}

void GameCore::getTrigger()
{
    for (auto c = gameBoard->field.begin(); c < gameBoard->field.end(); c++)
    {
        for (auto cell = c->begin(); cell < c->end(); cell++)
        {
            if (cell->hasWormHole != 0)
                cell->hasWormHole = 0;
        }
    }

    for (auto s : gameBoard->switches)
    {
        gameBoard->field[s->curSource.second][s->curSource.first].hasWormHole = RIGHT;
        gameBoard->field[s->curDest.second][s->curDest.first].hasWormHole = LEFT;
    }
    fieldChanged();
}
