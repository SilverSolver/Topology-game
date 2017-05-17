#include "mainwindow.h"
#include <QApplication>
#include <gamecore.h>

int main(int argc, char *argv[])
{
    GameBoard* board1 = new GameBoard(1);
    GameCore* gameCore = new GameCore(board1);

    QApplication a(argc, argv);
    MainWindow w(0, gameCore);

    w.show();

    return a.exec();
}
