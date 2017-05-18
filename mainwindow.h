#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "levelwidget.h"
#include "gameboard.h"
#include "gamecore.h"
#include <qdebug.h>
#include <QFile>
#include <QByteArray>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, GameCore *gameCore = NULL);
    void endOfGame();
    void drawCurrentLevel();
    void keyPressEvent(QKeyEvent*event);
    ~MainWindow();
signals:
    void movePlayer(int direction);
    void actPlayer();
public slots:
    void newGame(bool);
    void newLevel();
private:
    Ui::MainWindow *ui;
    GameCore* gameCore;
    QFileDialog* fileDialog;
    unsigned int currentLevel;
    QVector<QString> fileNames;
};

#endif // MAINWINDOW_H
