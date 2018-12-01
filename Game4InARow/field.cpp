#include "field.h"

#include <QtGui>
#include <QGraphicsSceneMouseEvent>

Field::Field()
{

}

void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->pos().x() << " " << event->pos().y();
}
