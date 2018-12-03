#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(int leftToFall, int* timeToMove);

protected:
    int leftToFall;
    int period = 5;
    int curP = 0;
    int step = 3;

    int* timeToMove;
};

#endif // CIRCLE_H
