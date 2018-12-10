#include "usercircle.h"

userCircle::userCircle(b2World* world, int* timeToMove, QPointF pos) : Circle(world, timeToMove, pos)
{
    setBrush(QBrush(Qt::yellow));
}

void userCircle::advance(int phase)
{
    if (!phase) return;
    if (fallen) return;

    prevY = pos().y();

    qreal posx = (body->GetPosition().x)*SCALE - CIRCLE_RADIUS;
    qreal posy = (body->GetPosition().y)*SCALE - CIRCLE_RADIUS;
    setPos(posx, posy);

    if (prevY == posy){

        *timeToMove = 2;
        fallen = true;
    }
}
