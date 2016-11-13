#ifndef DONKEYKONG_H
#define DONKEYKONG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "ladders.h"

class donkeykong: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    donkeykong();
    donkeykong(ladders*,ladders*);
public slots:
    void finish();
    void spawn();
private:
    ladders* first_ladder;
    ladders* second_ladder;
};

#endif // DONKEYKONG_H
