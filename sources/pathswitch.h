#ifndef PATHSWITCH_H
#define PATHSWITCH_H

#include <QVector>
#include <QPair>
#include <QObject>
#include <QDebug>
#include <sources/cell.h>

class PathSwitch : public QObject
{
    Q_OBJECT

public:
    PathSwitch(int x = -1, int y = -1);
    // Разрешим создавать переключатель с известными координатами
    bool trigger();
    void init(QPair<int, int> source0, QPair<int, int> dest0,
              QPair<int, int> source1, QPair<int, int> dest1,
              QPair<int, int> dir0, QPair<int, int> dir1);
    int x();
    int y();
    int condition();

    QPair<int, int> curSource;
    QPair<int, int> curDest;
    QPair<int, int> curDir;     // Направления порталов для текущих Source и Dest

signals:
    void iWasTriggered();
private:
    int xPos;
    int yPos;           // Координаты клетки, где стоит переключатель
    bool isTriggered;   // Нажат ли переключатель

    QPair<int, int> source0;
    QPair<int, int> dest0;    // Склейка клеток в случае если положение 0
    QPair<int, int> dir0;

    QPair<int, int> source1;
    QPair<int, int> dest1;    // -"- 1
    QPair<int, int> dir1;
};

#endif // PATHSWITCH_H
