#include "levelwidget.h"
#include "qdebug.h"

#define MARGIN 10

LevelWidget::LevelWidget(QWidget *parent, GameBoard* gameBoard) : QWidget(parent)
{
    this->gameBoard = gameBoard;
}

void LevelWidget::setGameBoard(GameBoard *gameBoard)
{
    this->gameBoard = gameBoard;
}

void LevelWidget::rePaintMe()
{
    this->repaint();
}

void LevelWidget::paintEvent(QPaintEvent *)
{
    //qDebug() << "HELLO, THIS IS PAINT EVENT!!!11";
    if (this->gameBoard == NULL)
        qDebug() << "I HAVE NOT A GAMEBOARD, CANT DRAW ANYTHING, HELP ME PLS!";
    else
    {
        QPainter painter(this);     // Инициализируем Qt-рисовальщик
        painter.setPen(Qt::black);  // Будем рисовать черные контуры ячеек
        int x0 = 0;
        int y0 = 0;                 // Начальная позиция рисовальщика
        int x  = x0;
        int y  = y0;
        int numCellsX = gameBoard->field[0].size();
        int numCellsY = gameBoard->field.size();        // Размеры поля

        for (auto i = gameBoard->field.begin(); i != gameBoard->field.end(); i++)
        {
            QString qString;        // Строка для вывода в поток отладки
            for (auto j = i->begin(); j != i->end(); j++)
            {
                // j должен иметь тип Cell
                QRect rect(x, y, width()/numCellsX, height()/numCellsY);
                if (j->type == 0) // Рисуем пустую клетку Cell
                {
                    qString.append("0 ");
                    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
                    painter.drawRect(rect);
                }
                else if (j->type == 1) // Рисуем стену
                {
                    qString.append("# ");
                    painter.setBrush(QBrush(Qt::black, Qt::DiagCrossPattern));
                    painter.drawRect(rect);
                }
                else if (j->type == 2) // Рисуем выход
                {
                    qString.append("E ");
                    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
                    painter.drawRect(rect);
                    painter.setBrush(QBrush(Qt::cyan, Qt::Dense1Pattern));
                    QRect rect2(x + MARGIN, y + MARGIN,
                               width()/numCellsX  - 2 * MARGIN,
                               height()/numCellsY - 2 * MARGIN);
                    painter.drawRect(rect2);
                    painter.drawText(rect2, "EXIT");
                }
                else if (j->type <  0) // Рисуем рычаг
                {
                    qString.append("l ");
                    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
                    painter.drawRect(rect);
                    painter.setBrush(Qt::black);
                    painter.drawRect(x + MARGIN, y + MARGIN,
                                     MARGIN, height()/numCellsY - 2 * MARGIN);
                }
                else                   // Что-то не так
                {
                    painter.setBrush(QBrush(Qt::magenta, Qt::SolidPattern));
                    painter.drawRect(rect);
                    qString.append("? ");
                }

                // Рисуем портал, если он есть
                if (j->hasWormHole > 0)
                {
                    painter.setBrush(Qt::blue);
                    if (j->hasWormHole == LEFT)
                    {
                        painter.drawRect(x, y, MARGIN, height()/numCellsY);
                    }
                    else if (j->hasWormHole == UP)
                    {
                        painter.drawRect(x, y, width()/numCellsX, MARGIN);
                    }
                    else if (j->hasWormHole == RIGHT)
                    {
                        painter.drawRect(x + width()/numCellsX - MARGIN, y,
                                         MARGIN, height()/numCellsY);
                    }
                    else if (j->hasWormHole == DOWN)
                    {
                        painter.drawRect(x, y + height()/numCellsY - MARGIN,
                                         width()/numCellsX, MARGIN);
                    }
                    else
                    {
                        qDebug() << "something wrong at " << x << " " << y << "cell";
                    }
                }
                x += width()/numCellsX;
            }
            x =  x0;                    // Переходим на след. "строку" рисования
            y += height()/numCellsY;
            //qDebug() << y;
            //qDebug() << qString;
        }
        // Нарисуем игрока
        int playerX = x0 + (gameBoard->player.x() + 0.5) * width()/numCellsX;
        int playerY = y0 + (gameBoard->player.y() + 0.5) * height()/numCellsY;
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(QPoint(playerX, playerY), MARGIN * 2, MARGIN * 2);

    }
}
