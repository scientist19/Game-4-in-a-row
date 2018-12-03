#ifndef TWOPLAYERSFIELD_H
#define TWOPLAYERSFIELD_H

#include "field.h"

class TwoPlayersField : public Field
{
public:
    TwoPlayersField(QGraphicsScene* scene, int cellSize);
};

#endif // TWOPLAYERSFIELD_H
