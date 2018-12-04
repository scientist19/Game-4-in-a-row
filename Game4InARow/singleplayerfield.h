#ifndef SINGLEPLAYERFIELD_H
#define SINGLEPLAYERFIELD_H

#include "field.h"

class SinglePlayerField : public Field
{
public:
    SinglePlayerField(QGraphicsScene* scene, int cellSize);

    std::pair<int, int> bestMove(int movesLeft, int player);
    void AIMove();
    void changePlayer();

protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
     void playerWin();
     void AIWin();
};

#endif // SINGLEPLAYERFIELD_H
