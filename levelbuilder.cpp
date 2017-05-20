#include "levelbuilder.h"

LevelBuilder::LevelBuilder(QObject *parent) : QObject(parent)
{
    this->fileData = new QByteArray();
}

void LevelBuilder::setGameBoard(GameBoard* gameBoard)
{
    this->gameBoard = gameBoard;
}

void *LevelBuilder::buildGameBoard(GameBoard *gameBoard, QFile *file)
{
    this->gameBoard = gameBoard;
    if (file->open(QIODevice::ReadOnly))
    {
        fileData->clear();
        fileData->append(file->readLine());

        // Проверка на правильность формата файла
        if (QString(fileData->data()).indexOf("board:") == -1)
        {
            //qDebug() << fileData->data();
            //qDebug() << "Wrong format";
            return NULL;
        }

        // Инициализация массива ячеек
        //qDebug() << "load cells array...";

        bool flagArrayEnd = false;
        QString tempString("");
        QStringList coordList;
        QVector<Cell> fieldLine;
        gameBoard->field.clear();

        while (!flagArrayEnd)
        {
            tempString = file->readLine();
            fileData->append(tempString);
            coordList  = tempString.split(QRegExp("\\s+"));

            if (coordList.length() <= 2)
            {
                flagArrayEnd = true;
                break;
            }
            fieldLine.clear();

            for (auto c : coordList)
                if (c.length() >= 1)
                    fieldLine.append(c.toInt());

            gameBoard->field.append(fieldLine);
        }

        // Пропускаем строки до момента описания переключателей
        while(QString(fileData->data()).indexOf("switches:") < 0)
            fileData->append(file->readLine());

        // Инициализация переключателей
        //qDebug() << "init switches...";
        flagArrayEnd = false;
        gameBoard->switches.clear();

        while(!flagArrayEnd)
        {
            // Считываем координаты переключателя
            tempString = file->readLine();
            fileData->append(tempString);
            coordList  = tempString.split(QRegExp("\\s+"));
            //qDebug() << coordList;

            if (coordList.length() <= 2)
            {
                flagArrayEnd = true;
                break;
            }

            PathSwitch* pswitch =
                    new PathSwitch(coordList[0].toInt(), coordList[1].toInt());

            // Считываем параметры переключателя
            tempString = file->readLine();
            fileData->append(tempString);
            coordList  = tempString.split(QRegExp("\\s+"));

            //qDebug() << coordList;
            pswitch->init(QPair<int, int>(coordList[0].toInt(),  coordList[1].toInt()),
                          QPair<int, int>(coordList[2].toInt(),  coordList[3].toInt()),
                          QPair<int, int>(coordList[4].toInt(),  coordList[5].toInt()),
                          QPair<int, int>(coordList[6].toInt(),  coordList[7].toInt()),
                          QPair<int, int>(coordList[8].toInt(),  coordList[9].toInt()),
                          QPair<int, int>(coordList[10].toInt(), coordList[11].toInt()));

            gameBoard->switches.append(pswitch);
        }

        // Пропускаем строки до момента описания положения игрока
        while(QString(fileData->data()).indexOf("player:") < 0)
            fileData->append(file->readLine());

        tempString = file->readLine();
        fileData->append(tempString);
        coordList  = tempString.split(QRegExp("\\s+"));
        gameBoard->player = Player(coordList[0].toInt(),  coordList[1].toInt());
    }
    else
        qDebug() << "File can't be loaded";
}
