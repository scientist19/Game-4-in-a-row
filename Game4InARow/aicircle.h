#ifndef AICIRCLE_H
#define AICIRCLE_H

#include "circle.h"

class AICircle : public Circle
{
public:
    AICircle(int leftToFall, int* timeToMove);
    void advance(int phase);
};

#endif // AICIRCLE_H
