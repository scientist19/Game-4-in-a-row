#include "usercircle.h"

userCircle::userCircle(int leftToFall, int* timeToMove) : Circle(leftToFall, timeToMove)
{
}

void userCircle::advance(int phase)
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
        *timeToMove = 2;
    }

    leftToFall -= step;
}
