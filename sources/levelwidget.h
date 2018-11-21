#ifndef LEVELWIDGET_H
#define LEVELWIDGET_H

#include <qstring.h>
#include <qpainter.h>
#include <QPaintEvent>
#include <QWidget>
#include <sources/gameboard.h>

class LevelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LevelWidget(QWidget *parent = 0, GameBoard *gameBoard = NULL);
    void setGameBoard(GameBoard* gameBoard);
public slots:
    void paintEvent(QPaintEvent *);
signals:

private:
    GameBoard* gameBoard;
};

#endif // LEVELWIDGET_H
