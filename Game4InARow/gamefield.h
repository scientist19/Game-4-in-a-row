#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "field.h"
#include "scene.h"

#include <Box2D/Box2D.h>

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class GameField;
}

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(bool isSingleGame, QWidget *parent = nullptr);
    ~GameField();

    const static int NMAX = 10;
    const static int LEFT_SHIFT = 50;
    const static int TOP_SHIFT = 50;

    void playerWin();
    void playerWin(int player);
    void AIWin();
public slots: void checkForMove();

public:
    Ui::GameField *ui;

private:
    Scene* scene;
    Field* myField;
    QTimer* animationTimer;
    QTimer* moveTimeTimer;

    b2World* world;

    void createField(bool isSingleGame);
    void resizeWinnerLabel();
};

#endif // GAMEFIELD_H
