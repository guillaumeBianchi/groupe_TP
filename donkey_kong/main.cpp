#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "enemy.h"
#include "donkeykong.h"
#include "ladders.h"
#include "levels.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Scene
    QGraphicsScene* scene = new QGraphicsScene();

    QGraphicsPixmapItem* background = new QGraphicsPixmapItem();
    //background->setRect(0,0,1200,1200);
    background->setPixmap(QPixmap(":/images/background.png"));
    scene->addItem(background);

    //Levels
    levels* level_one = new levels(200,1200,50);
    scene->addItem(level_one);
    levels* level_two = new levels(500,1200,50);
    scene->addItem(level_two);
    levels* level_three = new levels(800,1200,50);
    scene->addItem(level_three);

    //Player
    myrect * player = new myrect();
    //player->setRect(0,0,100,100);
    player->setPixmap(QPixmap(":/images/Mario.png"));
    player->setCurrentLevel(level_three);
    player->getLevels(level_one,level_two,level_three);

    //add player
    scene->addItem(player);

    //ladders
    ladders* ladder_first_lvl = new ladders(1000,150,50,350);
    ladders* ladder_second_lvl = new ladders(200,450,50,350);
    scene->addItem(ladder_first_lvl);
    scene->addItem(ladder_second_lvl);

    //Donkey kong
    donkeykong * donkey = new donkeykong(ladder_first_lvl,ladder_second_lvl);
    scene->addItem(donkey);

    enemy* projectile = new enemy(ladder_first_lvl,ladder_second_lvl);
    scene->addItem(projectile);

    //focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->show();
    view->setFixedSize(1200,900);
    scene->setSceneRect(0,0,1200,900);

    player->setPos(view->width()/2,level_three->getPosY() - 100);
    //test
    //player->setPos(600,0);

    //Spawn projectile
    QTimer * timer_spawn = new QTimer();
    QObject::connect(timer_spawn,SIGNAL(timeout()),donkey,SLOT(spawn()));
    timer_spawn->start(6000);

    QTimer * check_finish = new QTimer();
    QObject::connect(check_finish,SIGNAL(timeout()),donkey,SLOT(finish()));
    check_finish->start(200);

    QTimer * timer_for_gravity= new QTimer();
    QObject::connect(timer_for_gravity,SIGNAL(timeout()),player,SLOT(move()));
    timer_for_gravity->start(50);

    return a.exec();
}
