#ifndef FIELD_H
#define FIELD_H

#include "circle.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include <QTimer>

class Field : public QGraphicsRectItem
{
public:
    Field(QGraphicsScene* scene, int cellSize);
    void setItem(QGraphicsPixmapItem* item, int i, int j);

    bool canAddToColumn(int column);
    int endOfGame();
    bool addToColumn(int column, int player);
    bool removeFromColumn(int column);
    std::pair<int, int> bestMove(int movesLeft, int player);

    void print();
    void AIMove();

    const static int NMAX = 10;
    const static int LEFT_SHIFT = 100;
    const static int TOP_SHIFT = 50;

    int isTimeToMove();

    // QGraphicsItem interface
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int field[NMAX][NMAX] = {{0}};
    int numberInColumn[NMAX] = {0};
    int width = 7;
    int height = 6;
    int cellSize;

    // 0 - user can make a move
    // 1 - circle is falling
    // 2 - circle falled, AI can make a move
    // 3 = AI making a move && its circle is falling
    int* timeToMove = new int(0);

    int curPlayer;

    QGraphicsPixmapItem* itemsList[NMAX][NMAX];
    QVector <Circle*> circlesList;
    QGraphicsScene* scene;


    int findClickedColumn(int x);

};

#endif // FIELD_H
