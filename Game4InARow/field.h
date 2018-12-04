#ifndef FIELD_H
#define FIELD_H

#include "circle.h"
#include "aicircle.h"
#include "usercircle.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QtGui>
#include <QGraphicsSceneMouseEvent>
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
    void print();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;

    const static int NMAX = 10;
    const static int LEFT_SHIFT = 50;
    const static int TOP_SHIFT = 50;

    QPixmap cellImage = QPixmap::fromImage(QImage(":/rec/img/cellGray.png"));
    QPixmap selectedCellImage = QPixmap::fromImage(QImage(":/rec/img/selectedCell4.png"));
    QPixmap winnerCellImage = QPixmap::fromImage(QImage(":/rec/img/cellWhite.png"));

    int isTimeToMove();
    virtual void changePlayer() = 0;

protected:
    int field[NMAX][NMAX] = {{0}};
    int numberInColumn[NMAX] = {0};
    int width = 7;
    int height = 6;
    int cellSize;

    int player = 1;
    bool gameOver = false;

    // 0 - user can make a move
    // 1 - circle is falling
    // 2 - circle falled, AI can make a move
    // 3 = AI making a move && its circle is falling
    int* timeToMove = new int(0);
    int selectedColumn = -1;

    QGraphicsPixmapItem* itemsList[NMAX][NMAX];
    QVector <Circle*> circlesList;
    QGraphicsScene* scene;


    int findClickedColumn(int x);
    void lightWinnerCells();
    void lightWinnerCell(int i, int j);
    void setFieldCellsColor();


    // QGraphicsItem interface
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // FIELD_H
