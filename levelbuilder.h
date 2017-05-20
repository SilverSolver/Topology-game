#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QStringList>
#include <gameboard.h>
#include <cell.h>

class LevelBuilder : public QObject
{
    Q_OBJECT
public:
    explicit LevelBuilder(QObject *parent = 0);
signals:

public slots:
    void setGameBoard(GameBoard* gameBoard);
    void *buildGameBoard(GameBoard* gameBoard, QFile* file);
private:
    GameBoard* gameBoard;
    QByteArray* fileData;
};

#endif // LEVELBUILDER_H
