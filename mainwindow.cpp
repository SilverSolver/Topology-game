#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, GameCore* gameCore) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->gameCore = gameCore;
    this->fileDialog = new QFileDialog(this);
    this->fileDialog->setNameFilter(tr("Level files (*.lvl)"));
    currentLevel = 0;

    QObject::connect(this->ui->QuitButton, SIGNAL(clicked(bool)),
                     this, SLOT(close()));
    QObject::connect(this->ui->newGameButton, SIGNAL(clicked(bool)),
                     this, SLOT(newGame(bool)));
    QObject::connect(this, SIGNAL(movePlayer(int)),
                     this->gameCore, SLOT(getPlayerMove(int)));
    QObject::connect(this, SIGNAL(actPlayer()),
                     this->gameCore, SLOT(getPlayerAction()));
    QObject::connect(this->gameCore, SIGNAL(levelComplete()),
                     this, SLOT(newLevel()));
    QObject::connect(this->ui->LoadButton, SIGNAL(clicked(bool)),
                     this->fileDialog, SLOT(show()));
}

void MainWindow::drawCurrentLevel()
{
    switch (this->ui->stackedWidget->currentIndex())
    {
    case 1:
    {
        qDebug() << "drawCurrentLevel case 1" << endl;

        this->ui->level_1->setGameBoard(this->gameCore->gameBoard);
        break;
    }
    default:
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
    {
        this->ui->stackedWidget->setCurrentIndex(0);
        break;
    }
    case Qt::Key_Up:
    {
        movePlayer(UP);
        break;
    }
    case Qt::Key_Left:
    {
        movePlayer(LEFT);
        break;
    }
    case Qt::Key_Down:
    {
        movePlayer(DOWN);
        break;
    }
    case Qt::Key_Right:
    {
        movePlayer(RIGHT);
        break;
    }
    case Qt::Key_Space:
    {
        actPlayer();
        break;
    }
    default:
        break;
    }
}

void MainWindow::newGame(bool)
{
    newLevel();
}

void MainWindow::newLevel()
{
    // Если уровень не первый, поздравим игрока с прохождением предыдущего
    if (this->ui->stackedWidget->currentIndex() > 0)
    {
        QMessageBox mBox;
        mBox.setText("Congratulations! Level complete");
        mBox.exec();
    }

    if (this->ui->stackedWidget->currentIndex() !=
        this->ui->stackedWidget->count())
    {
        this->ui->stackedWidget->setCurrentIndex(
                this->ui->stackedWidget->currentIndex() + 1);

        QObject::connect(this->gameCore, SIGNAL(fieldChanged()),
                         this->ui->stackedWidget->currentWidget(), SLOT(rePaintMe()));

        qDebug() << "Now Will Draw Level";
        drawCurrentLevel();
    }
    // Если вызван переход к новому уровню, когда уровни закончились, значит, это конец
    else
        endOfGame();
}

void MainWindow::endOfGame()
{
    // Пока не реализовано, но тут будет что-нибудь вроде поздравлений и т.п.
}

MainWindow::~MainWindow()
{
    delete ui;
}
