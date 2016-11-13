#include "levels.h"

levels::levels(float _pos_y, float _width, float _height)
{
    this->pos_y = _pos_y;
    this->width = _width;
    this->height = _height;

    //Set position
    setPos(0,this->pos_y);

    //draw rect
    //setRect(0,0,this->width,this->height);
    setPixmap(QPixmap(":/images/ground.png"));
}

float levels::getHeight()
{
    return this->height;
}

float levels::getPosY()
{
    return this->pos_y;
}

