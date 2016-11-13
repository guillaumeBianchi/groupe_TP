#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "ladders.h"

class enemy: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    enemy(ladders* ladder_first_level, ladders* ladder_second_level);
private:
    bool on_first_level;
    bool on_second_level;
    bool on_third_level;
    bool on_ladder;
    ladders* first_ladder;
    ladders* second_ladder;

public slots:
    void move();
};

#endif // ENEMY_H
