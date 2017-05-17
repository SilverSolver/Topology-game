#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>  // Нужен, если захочу использовать сигналы и слоты
#include <QVector>  // QVector - аналог класса Vector из STL
#include <player.h>
#include <pathswitch.h>
#include <cell.h>

class GameBoard     // Хранит информацию о игровом поле текущего уровня
{
public:
    GameBoard(int levelNum);    // Можно создавать игровое поле по номеру уровня
    GameBoard();

    QVector<QVector<Cell> > field;// Игровое поле - состоит из массива m x n клеток.
    QVector<PathSwitch*> switches; // Тут будет хранится набор переключателей, находящихся
                                  // на данном игровом поле
    Player player; // Храним местоположение игрока
};

#endif // GAMEBOARD_H
