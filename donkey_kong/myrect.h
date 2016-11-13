#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "levels.h"

class myrect: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
    void getLevels(levels*, levels*, levels*);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void move();
    void setCurrentLevel(levels* current_lvl);
private:
    bool isJumping;
    bool canJump;
    QTimer* timer;
    levels* current_level;
    levels* level_one;
    levels* level_two;
    levels* level_three;
};


#endif // MYRECT_H
