#ifndef LADDERS_H
#define LADDERS_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
class ladders: public QGraphicsPixmapItem{

public:
    ladders();
    ladders(float _ladders_pos_x,float _ladders_pos_y,float _width,float _height);
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();

private:
    float ladders_pos_x;
    float ladders_pos_y;
    float width;
    float height;
};

#endif // LADDERS_H
