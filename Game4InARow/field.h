#ifndef FIELD_H
#define FIELD_H


#include <QGraphicsRectItem>

class Field : public QGraphicsRectItem
{
public:
    Field();
    void setItem(QGraphicsPixmapItem* item, int i, int j);


    const static int NMAX = 10;
    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QGraphicsPixmapItem* itemsList[NMAX][NMAX];
};

#endif // FIELD_H
