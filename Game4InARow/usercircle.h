#ifndef USERCIRCLE_H
#define USERCIRCLE_H

#include "circle.h"

class userCircle : public Circle
{
public:
    userCircle(b2World* world, int* timeToMove, QPointF pos);
    void advance(int phase);
};

#endif // USERCIRCLE_H
