#include "circle.h"

Circle::Circle(b2World* world, int* timeToMove, QPointF pos) : QGraphicsEllipseItem (),
    timeToMove(timeToMove)
{
  //  setRect(pos.x(), pos.y(), CIRCLE_RADIUS*2, CIRCLE_RADIUS*2);
    setRect(5, 5, SMALLER_RADIUS*2, SMALLER_RADIUS*2);
    setPos(pos.x(), pos.y());

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;

    float32 posx = (pos.x()+CIRCLE_RADIUS)/SCALE;
    float32 posy = (pos.y()+CIRCLE_RADIUS)/SCALE;
    bodyDef.position.Set(posx, posy);
    bodyDef.linearDamping = 0.1f;

    body = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = CIRCLE_RADIUS/SCALE;

    b2Fixture* fixture = body->CreateFixture(&shape, 1.0f);
    fixture->SetRestitution(0.5f);
}
