#include "circle.h"

Circle::Circle(int leftToFall, bool* timeToMove) : QGraphicsEllipseItem (),
    leftToFall(leftToFall),
    timeToMove(timeToMove)
{

}


void Circle::advance(int phase)
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
        if (timeToMove) *timeToMove = 1;
    }

    leftToFall -= step;
}
