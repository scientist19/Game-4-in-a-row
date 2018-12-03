#ifndef USERCIRCLE_H
#define USERCIRCLE_H

#include "circle.h"

class userCircle : public Circle
{
public:
    userCircle(int leftToFall, int* timeToMove);
    void advance(int phase);
};

#endif // USERCIRCLE_H
