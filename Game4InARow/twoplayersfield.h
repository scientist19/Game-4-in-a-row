#ifndef TWOPLAYERSFIELD_H
#define TWOPLAYERSFIELD_H

#include "field.h"

class TwoPlayersField : public Field
{
public:
    TwoPlayersField(Scene* scene, int cellSize);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void changePlayer();

    void playerWin();
};

#endif // TWOPLAYERSFIELD_H
