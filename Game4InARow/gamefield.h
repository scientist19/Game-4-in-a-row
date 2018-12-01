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

    GameField(QWidget *parent, int height, int width);
    bool canAddToColumn(int column);
    int endOfGame();
    bool addToColumn(int column, int player);
    bool removeFromColumn(int column);
    std::pair<int, int> bestMove(int movesLeft, int player);

    void print();

    const static int NMAX = 10;
    const static int LEFT_SHIFT = 100;
    const static int TOP_SHIFT = 50;

private:
    Ui::GameField *ui;

    QGraphicsScene* scene = new QGraphicsScene(0, 0, 1000, 750, this);
    Field* myRect;
    QVector <QGraphicsItem*> itemsList;

    int field[NMAX][NMAX] = {{0}};
    int numberInColumn[NMAX] = {0};
    int width = 6;
    int height = 7;

    void createField();
};

#endif // GAMEFIELD_H
