#include "gameboard.h"
#include <QDebug>

GameBoard::GameBoard(int levelNum)
{
    switch (levelNum)
    {
    case 1:
    {
        QVector<Cell> line1, line2, line3;
        line1.append(Cell(0));
        line1.append(           Cell(WALL));
        line1.append(                       Cell(0, LEFT));
        line2.append(Cell(0, RIGHT));
        line2.append(           Cell(WALL));
        line2.append(                       Cell(WALL));
        line3.append(Cell(-1));
        line3.append(           Cell(WALL));
        line3.append(                       Cell(EXIT));
        field.clear();
        field.append(line1);
        field.append(line2);
        field.append(line3);

        PathSwitch* pswitch = new PathSwitch(0, 2);
        pswitch->init(QPair<int, int>(0, 1), QPair<int, int>(2, 0),
                      QPair<int, int>(0, 1), QPair<int, int>(2, 2));

        switches.clear();
        switches.append(pswitch);

        player = Player(0, 0);
        qDebug() << "First layer initialized" << endl;
        break;
    }
    default:
        break;
    }
}
