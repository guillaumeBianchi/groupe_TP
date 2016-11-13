#include "donkeykong.h"
#include "enemy.h"
#include <QGraphicsScene>
#include "ladders.h"
#include "myrect.h"
#include <typeinfo.h>
#include <QList>
#include <QMessageBox>

donkeykong::donkeykong(ladders* _first_ladder, ladders* _second_ladder)
{
    this->first_ladder = _first_ladder;
    this->second_ladder = _second_ladder;

    //Set position
    setPos(0,100);

    //draw rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/donkeykong.png"));

}

void donkeykong::spawn()
{
    //create enemy
    enemy* projectile = new enemy(this->first_ladder,this->second_ladder);
    scene()->addItem(projectile);
}

void donkeykong::finish()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i< colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(myrect)){
             delete colliding_items[i];
             delete this;
             QMessageBox msgBox;
             msgBox.setText("WELL DONE ! You defeated donkey kong. Thanks for playing !");
             msgBox.exec();
             return;
        }
    }
}
