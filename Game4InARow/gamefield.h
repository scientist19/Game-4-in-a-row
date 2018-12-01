#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "field.h"

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class GameField;
}

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(QWidget *parent = nullptr);
    ~GameField();

    const static int NMAX = 10;
    const static int LEFT_SHIFT = 100;
    const static int TOP_SHIFT = 50;

public slots: void checkForMove();

private:
    Ui::GameField *ui;

    QGraphicsScene* scene = new QGraphicsScene(0, 0, 1000, 750, this);
    Field* myRect;
    QTimer* animationTimer;
    QTimer* moveTimeTimer;

    void createField();
};

#endif // GAMEFIELD_H
