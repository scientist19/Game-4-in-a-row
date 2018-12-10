#include "scene.h"

Scene::Scene(qreal x, qreal y, qreal width, qreal height, b2World *world)
    : QGraphicsScene (x, y, width, height)
{
    this->world = world;
}

void Scene::advance()
{
    world->Step(1.00f/60.00, 6, 2);
    QGraphicsScene::advance();
}
