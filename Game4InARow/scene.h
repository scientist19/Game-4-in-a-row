#ifndef SCENE_H
#define SCENE_H

#include <Box2D/Box2D.h>
#include <QGraphicsScene>

class Scene : public QGraphicsScene{
    Q_OBJECT
public:
    Scene(qreal x, qreal y, qreal width, qreal height, b2World* world);
public slots:
    void advance();

public:
    b2World* world;
};

#endif // SCENE_H
