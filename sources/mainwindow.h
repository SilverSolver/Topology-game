#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <ui_mainwindow.h>
#include <sources/gamecore.h>

namespace Ui
{
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, GameCore* gameCore);
    void keyPressEvent(QKeyEvent* event);
    ~MainWindow();
signals:
    void movePlayer(int);
    void actPlayer();
public slots:
    void showHelp(bool);
    void drawCurrentLevel();
    void newGame(bool);
    void newLevel();
    void endOfGame();
private:
    Ui::MainWindow *ui;
    GameCore* gameCore;
    QMessageBox* helpBox;
    int currentLevel;
};
#endif // MAINWINDOW_H
