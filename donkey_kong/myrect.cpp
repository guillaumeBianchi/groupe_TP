#include "myrect.h"
#include <QDebug>
#include <QKeyEvent>
#include <typeinfo.h>
#include "ladders.h"
#include <QTimer>

void myrect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 1200)
        {
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        //Check colliding with ladder
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i =0;i< colliding_items.size(); i++){
            if(typeid(*(colliding_items[i])) == typeid(ladders)){
                setPos(x(),y() - 20);
            }
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        //Check colliding with ladder
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i =0;i< colliding_items.size(); i++){
            if(typeid(*(colliding_items[i])) == typeid(ladders)){
                setPos(x(),y() + 10);
            }
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(this->canJump)
        {
            this->isJumping = true;
            setPos(x(),y() - 150);
        }
    }
}

void myrect::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
        {
            this->isJumping = false;
        }
}

void myrect::move()
{
    if(pos().y() <= this->level_one->getPosY())
    {
        setCurrentLevel(level_one);
    }
    else if(pos().y() <= this->level_two->getPosY() && pos().y() >= this->level_one->getPosY())
    {
        setCurrentLevel(level_two);
    }
    else if(pos().y() >= this->level_two->getPosY() && pos().y() <= this->level_three->getPosY() )
    {
        setCurrentLevel(level_three);
    }

    if(pos().y() == this->current_level->getPosY() - 100)
    {
        this->canJump = true;
    }
    else
    {
        this->canJump = false;
    }

    if(this->isJumping == false){
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i =0;i< colliding_items.size(); i++){
            if(typeid(*(colliding_items[i])) == typeid(ladders)){
                if(pos().y() != (this->current_level->getPosY() - 100))
                {
                    setPos(x(),y() - 5);
                }
            }
            if(typeid(*(colliding_items[i])) != typeid(ladders)){
                if(pos().y() != (this->current_level->getPosY() - 100))
                {
                    setPos(x(),y() + 5);
                }
            }

        }
    }
}

void myrect::setCurrentLevel(levels* current_lvl)
{
    this->current_level = current_lvl;
}

void myrect::getLevels(levels* _level_one,levels* _level_two,levels* _level_three)
{
    this->level_one = _level_one;
    this->level_two = _level_two;
    this->level_three = _level_three;
}

