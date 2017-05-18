#ifndef LEVELBUILDER_H
#define LEVELBUILDER_H

#include <QObject>

class LevelBuilder : public QObject
{
    Q_OBJECT
public:
    explicit LevelBuilder(QObject *parent = 0);

signals:

public slots:
};

#endif // LEVELBUILDER_H