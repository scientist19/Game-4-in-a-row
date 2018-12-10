#ifndef CIRCLE_H
#define CIRCLE_H


#include "constanter.h"
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <Box2D/Box2D.h>

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(b2World* world, int* timeToMove, QPointF pos);

protected:

    double prevY;
    bool fallen = false;

    int* timeToMove;
    b2Body* body;
};

#endif // CIRCLE_H
