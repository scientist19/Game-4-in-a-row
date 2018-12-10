#ifndef AICIRCLE_H
#define AICIRCLE_H

#include "circle.h"

class AICircle : public Circle
{
public:
    AICircle(b2World* world, int* timeToMove, QPointF pos);
    void advance(int phase);
};

#endif // AICIRCLE_H
