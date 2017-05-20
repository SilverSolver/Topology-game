#include "mainwindow.h"
#include <QApplication>
#include <gamecore.h>
#include <levelbuilder.h>

int main(int argc, char *argv[])
{
    GameBoard*    board     = new GameBoard(1);
    LevelBuilder* builder   = new LevelBuilder();
    GameCore*     gameCore  = new GameCore(board, builder);

    QApplication a(argc, argv);
    MainWindow w(0, gameCore);

    w.show();

    return a.exec();
}
