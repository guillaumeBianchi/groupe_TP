#include "ladders.h"

ladders::ladders()
{

}

ladders::ladders(float _ladders_pos_x, float _ladders_pos_y, float _width, float _height)
{
    this->ladders_pos_x = _ladders_pos_x;
    this->ladders_pos_y = _ladders_pos_y;
    this->width = _width;
    this->height = _height;


    //Set position
    setPos(this->ladders_pos_x,this->ladders_pos_y);

    //draw rect
    //setRect(0,0,this->width,this->height);
    setPixmap(QPixmap(":/images/ladder.png"));
}

float ladders::getPosX()
{
    return this->ladders_pos_x;
}

float ladders::getPosY()
{
    return this->ladders_pos_y;
}

float ladders::getWidth()
{
    return this->width;
}

float ladders::getHeight()
{
    return this->height;
}
