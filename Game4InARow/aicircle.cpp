#include "aicircle.h"

AICircle::AICircle(int leftToFall, int* timeToMove) : Circle(leftToFall, timeToMove)
{
}

void AICircle::advance(int phase)
{
    if (!phase) return;
    if (leftToFall <= 0) return;

    if (++curP > period){
        step+=2;
        curP = 0;
    }

    if (leftToFall >= step) moveBy(0, step);
    else {
        moveBy(0, leftToFall);
        *timeToMove = 0;
    }

    leftToFall -= step;
}
