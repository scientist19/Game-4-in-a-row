#include "singleplayerfield.h"

SinglePlayerField::SinglePlayerField(Scene* scene, int cellSize) : Field(scene, cellSize)
{

}

void SinglePlayerField::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (*timeToMove != 0) return;

    if (gameOver) return;

    qDebug() << event->pos().x() << " " << event->pos().y();
    int clickedColumn = findClickedColumn(event->pos().x());

    if (!canAddToColumn(clickedColumn)) return;

    *timeToMove = 1;
    setCursor(Qt::ForbiddenCursor);

    int toFall = (height - numberInColumn[clickedColumn])*cellSize;
    addToColumn(clickedColumn, 1);
    qDebug() << "NUMBER OF COLUMN = " << clickedColumn;

    userCircle* myCircle = new userCircle(scene->world, timeToMove,
                                          QPointF(LEFT_SHIFT + clickedColumn*cellSize, TOP_SHIFT - cellSize));
    /*
    myCircle->setRect(LEFT_SHIFT + clickedColumn*cellSize, TOP_SHIFT - cellSize, 95, 95);
    myCircle->setBrush(QBrush(QColor(255, 255, 0)));
    */
    scene->addItem(myCircle);

    circlesList.push_back(myCircle);

 //   if (endOfGame()) playerWin();
}

void SinglePlayerField::playerWin()
{
    gameOver = true;

    setFieldCellsColor();
    lightWinnerCells();

    this->setAcceptHoverEvents(false);
    this->setCursor(Qt::ForbiddenCursor);
}

void SinglePlayerField::AIWin()
{
    gameOver = true;

    setFieldCellsColor();
    lightWinnerCells();

    this->setAcceptHoverEvents(false);
    this->setCursor(Qt::ForbiddenCursor);
}

void SinglePlayerField::AIMove()
{
    if (endOfGame()) playerWin();
    if (gameOver) return;

    player = 2;
    *timeToMove = 3;
    auto bm = bestMove(6, 2);
    int column = bm.first;

    int toFall = (height - numberInColumn[column])*cellSize;
    addToColumn(column, 2);

    AICircle* circle = new AICircle(scene->world, timeToMove,
                                    QPointF(LEFT_SHIFT + column*cellSize, TOP_SHIFT - cellSize));
    /*
    circle->setRect(LEFT_SHIFT + column*cellSize, TOP_SHIFT - cellSize, 95, 95);
    circle->setBrush(QBrush(QColor(255, 0, 0)));
    */
    scene->addItem(circle);

    circlesList.push_back(circle);
}

void SinglePlayerField::changePlayer(){

    if (*timeToMove == 0) {
        player = 1;
        setCursor(Qt::PointingHandCursor);
        if (endOfGame()) AIWin();
    }
    if (*timeToMove == 2) AIMove();
}

std::pair<int, int> SinglePlayerField::bestMove(int movesLeft, int player){

    if (movesLeft == 0) return std::make_pair(0, 0);
    std::vector<int> potentialMoves;
    std::vector<int> loseMoves;
    for (int j = 0; j < width; j++){

        if (canAddToColumn(j)){

            addToColumn(j, player);
            int indEndOfGame = endOfGame();
            removeFromColumn(j);

            //if (movesLeft == 8) qDebug() << "indEndOfGame = " << indEndOfGame;
            if (indEndOfGame == player) return std::make_pair(j, 1);
            else if (indEndOfGame == -1) return std::make_pair(j, 0);

            addToColumn(j, player);
            std::pair<int, int> opponentMove = bestMove(movesLeft-1, 3-player);
            removeFromColumn(j);

            if (opponentMove.second == -1) return std::make_pair(j, 1);
            else if (opponentMove.second == 0) potentialMoves.push_back(j);
            else loseMoves.push_back(j);
        }
    }

    // debug
    if (movesLeft == 7){

        qDebug() << "Potential moves:";
        QString s;
        for (int i = 0; i < potentialMoves.size(); i++)
            s += QString::number(potentialMoves[i]) + " ";
        qDebug() << s;

        qDebug() << "Lose moves:";
        s = "";
        for (int i = 0; i < loseMoves.size(); i++)
            s += QString::number(loseMoves[i]) + " ";
        qDebug() << s;
    }


    if (potentialMoves.size() == 0) return std::make_pair(loseMoves[rand() % loseMoves.size()], -1);
    return std::make_pair(potentialMoves[rand() % potentialMoves.size()], 0);
}
