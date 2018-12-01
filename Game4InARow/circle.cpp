#include "circle.h"

Circle::Circle(int leftToFall, int* timeToMove, bool f) : QGraphicsEllipseItem (),
    leftToFall(leftToFall),
    timeToMove(timeToMove),
    f(f)
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
        if (!f) *timeToMove = 2;
        else *timeToMove = 0;
    }

    leftToFall -= step;
}
