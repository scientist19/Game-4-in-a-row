#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(int leftToFall, bool* timeToMove = nullptr);

    // QGraphicsItem interface
public:
    void advance(int phase);

signals:
    void reachPlace();

private:
    int leftToFall;
    int period = 5;
    int curP = 0;
    int step = 3;

    bool* timeToMove;
};

#endif // CIRCLE_H
