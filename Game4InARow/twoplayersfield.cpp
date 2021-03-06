#include "twoplayersfield.h"
#include "gamefield.h"

TwoPlayersField::TwoPlayersField(Scene* scene, int cellSize) : Field(scene, cellSize)
{

}


void TwoPlayersField::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (*timeToMove != 0) return;
    if (gameOver) return;

    qDebug() << event->pos().x() << " " << event->pos().y();
    int clickedColumn = findClickedColumn(event->pos().x());

    if (!canAddToColumn(clickedColumn)) return;
    *timeToMove = 1;
    setCursor(Qt::ForbiddenCursor);

    int toFall = (height - numberInColumn[clickedColumn])*cellSize;
    addToColumn(clickedColumn, player);
    qDebug() << "NUMBER OF COLUMN = " << clickedColumn;

    userCircle* myCircle = new userCircle(scene->world, timeToMove,
                                          QPointF(LEFT_SHIFT + clickedColumn*cellSize, TOP_SHIFT - cellSize));
 //   myCircle->setRect(LEFT_SHIFT + clickedColumn*cellSize, TOP_SHIFT - cellSize, 95, 95);

    QBrush brush1 = QBrush(QColor(255, 255, 0)),
           brush2 = QBrush(QColor(255, 0, 0));
    QBrush brush;

    if (player == 1) brush = brush1;
    else brush = brush2;

    myCircle->setBrush(brush);
    scene->addItem(myCircle);

    circlesList.push_back(myCircle);
}

// 0 - player can make a move
// 1 - circle is falling
// 2 - circle falled, need to change player
void TwoPlayersField::changePlayer(){

    if (*timeToMove == 2){

        if (endOfGame()) playerWin();

        player = 3-player;
        *timeToMove = 0;
        setCursor(Qt::PointingHandCursor);
    }
}

void TwoPlayersField::playerWin()
{
    gameOver = true;

    setFieldCellsColor();
    lightWinnerCells();

    this->setAcceptHoverEvents(false);
    this->setCursor(Qt::ForbiddenCursor);

    gameField->playerWin(player);
}
