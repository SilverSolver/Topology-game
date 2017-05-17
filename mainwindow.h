#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <gamecore.h>

namespace Ui {
class MainWindow;
}

// Класс, ответственный за интерфейс игры

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
    unsigned int currentLevel;
};

#endif // MAINWINDOW_H
