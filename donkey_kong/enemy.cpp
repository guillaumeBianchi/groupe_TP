#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "myrect.h"
#include <typeinfo>
#include <QDebug>
#include "ladders.h"
#include <QMessageBox>

enemy::enemy(ladders* ladder_first_level,ladders* ladder_second_level): QObject(),QGraphicsPixmapItem()
{
    //Set position
    setPos(100,150);

    //draw rect
    //setRect(0,0,50,50);
    setPixmap(QPixmap(":/images/barrel.png"));

    //Where it is on the map
    on_first_level = true;
    on_second_level = false;
    on_third_level = false;
    on_ladder = false;

    first_ladder = ladder_first_level;
    second_ladder = ladder_second_level;

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
    //Check colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i< colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(myrect)){
            //remove from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both
            delete colliding_items[i];
            delete this;
            QMessageBox msgBox;
            msgBox.setText("GAME OVER! Thanks for playing !");
            msgBox.exec();
            return;
        }
    }

    //move projectile
    //bool moving_right = true;

    if(this->on_first_level)
    {

        if(!this->on_ladder)
        {
            setPos(x()+10,y());
        }else{
            setPos(x(),y()+10);
        }

        if(pos().x() >= (this->first_ladder->getPosX()))
        {
            this->on_ladder = true;
        }

        if(pos().y() >= (this->first_ladder->getPosY()+this->first_ladder->getHeight()-50))
        {
            this->on_first_level = false;
            this->on_ladder = false;
            this->on_second_level = true;
            //qDebug() << on_ladder;
            //qDebug() << first_level;
            //qDebug() << second_level;
        }
    }
    else if(this->on_second_level)
    {
        if(!this->on_ladder)
        {
            setPos(x()-10,y());
        }else{
            setPos(x(),y()+10);
        }

        if(pos().x() <= this->second_ladder->getPosX())
        {
            this->on_ladder = true;
        }

        if(pos().y() >= (this->second_ladder->getPosY()+this->second_ladder->getHeight()-50))
        {
            this->on_second_level = false;
            this->on_ladder = false;
            this->on_third_level = true;
            //qDebug() << on_ladder;
            //qDebug() << first_level;
            //qDebug() << second_level;
        }
    }
    else if(this->on_third_level)
    {

        setPos(x()+10,y());

        if(pos().x() <= 200)
        {
            this->on_ladder = true;
        }
    }

    if(pos().x()>1200)
    {
        scene()->removeItem(this);
        delete this;
    }
}
