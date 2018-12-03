#ifndef SINGLEPLAYERFIELD_H
#define SINGLEPLAYERFIELD_H

#include "field.h"

class SinglePlayerField : public Field
{
public:
    SinglePlayerField(QGraphicsScene* scene, int cellSize);

    std::pair<int, int> bestMove(int movesLeft, int player);
    void AIMove();

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SINGLEPLAYERFIELD_H
