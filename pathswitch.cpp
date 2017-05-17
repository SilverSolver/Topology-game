#include "pathswitch.h"

PathSwitch::PathSwitch(int x, int y) : QObject()
{
    this->xPos = x;
    this->yPos = y;
    this->isTriggered = false; // В начале игры все переключатели не нажаты
}

void PathSwitch::init(QPair<int, int> source0, QPair<int, int> dest0,
                      QPair<int, int> source1, QPair<int, int> dest1)
{
    this->source0   = source0;
    this->dest0     = dest0;
    this->source1   = source1;
    this->dest1     = dest1;
    this->curDest   = dest0;
    this->curSource = source0;
}

bool PathSwitch::trigger()
{
    isTriggered = !isTriggered;// Если включен, выключаем и наоборот
    if (isTriggered)
    {
        curSource = source1;
        curDest   = dest1;
    }
    else
    {
        curSource = source0;
        curDest   = dest0;
    }
    iWasTriggered();
    return isTriggered;
}

int PathSwitch::x()
{
    return this->xPos;
}

int PathSwitch::y()
{
    return this->yPos;
}

int PathSwitch::condition()
{
    return this->isTriggered;
}
