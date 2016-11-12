#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsPixmapItem>

class levels: public QGraphicsPixmapItem{
public:
    levels(float,float,float);
    float getHeight();
    float getPosY();
private:
    float pos_y;
    float width;
    float height;
};

#endif // LEVELS_H
