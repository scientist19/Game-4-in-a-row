#include "field.h"

#include <time.h>

Field::Field(Scene* scene, int cellSize) :
    cellSize(cellSize),
    scene(scene)
{
    this->setAcceptHoverEvents(true);
    setCursor(Qt::PointingHandCursor);
    srand(time(0));

}

void Field::setGameField(GameField *gameField)
{
    this->gameField = gameField;
}

void Field::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    int selectedColumn = findClickedColumn(event->pos().x());
    qDebug() << "Selected column = " << selectedColumn;

    if (this->selectedColumn == selectedColumn) return;

    if (this->selectedColumn != -1)
    for (int i = 0; i < height; i++)
        itemsList[i][this->selectedColumn]->setPixmap(cellImage);

    this->selectedColumn = selectedColumn;
//    setCursor(Qt::PointingHandCursor);

    if (canAddToColumn(selectedColumn)){
        for (int i = 0; i < height; i++)
            itemsList[i][selectedColumn]->setPixmap(selectedCellImage);
        setCursor(Qt::PointingHandCursor);
    }
    else setCursor(Qt::ForbiddenCursor);

}

void Field::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

    if (this->selectedColumn != -1)
    for (int i = 0; i < height; i++)
        itemsList[i][this->selectedColumn]->setPixmap(cellImage);
    this->selectedColumn = -1;

//    setCursor(Qt::PointingHandCursor);
}

void Field::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    int selectedColumn = findClickedColumn(event->pos().x());
    qDebug() << "Selected column = " << selectedColumn;

    if (this->selectedColumn == selectedColumn) return;

    if (this->selectedColumn != -1)
    for (int i = 0; i < height; i++)
        itemsList[i][this->selectedColumn]->setPixmap(cellImage);

    this->selectedColumn = selectedColumn;
//    setCursor(Qt::PointingHandCursor);

    if (canAddToColumn(selectedColumn)){
        for (int i = 0; i < height; i++)
            itemsList[i][selectedColumn]->setPixmap(selectedCellImage);
        setCursor(Qt::PointingHandCursor);
    }
    else setCursor(Qt::ForbiddenCursor);
}


int Field::isTimeToMove()
{
    return *timeToMove;
}

int Field::findClickedColumn(int x)
{
    x -= LEFT_SHIFT;
    return std::min(width-1, x/cellSize);
}


void Field::setItem(QGraphicsPixmapItem* item, int i, int j){

    itemsList[i][j] = item;
}



bool Field::canAddToColumn(int column)
{
    if (column < 0 || column >= width) return false;
    if (numberInColumn[column] < height) return true;
    return false;
}

bool Field::addToColumn(int column, int player)
{
    if (!canAddToColumn(column)) return false;

    int pos = numberInColumn[column]++;
    field[height-pos-1][column] = player;
    return true;
}

bool Field::removeFromColumn(int column){

    if (column < 0 || column >= width) return false;
    if (numberInColumn[column] == 0) return false;

    int pos = --numberInColumn[column];
    field[height-pos-1][column] = 0;
    return true;
}

int Field::endOfGame()
{
    int h, v, d1, d2;

    // horizontal
    for (int i = 0; i < height; i++){
        h = 1;
        for (int j = 1; j < width; j++){

            if (field[i][j] == field[i][j-1]) h++;
            else h = 1;

            if (h == 4 && field[i][j] != 0) return field[i][j];
        }
    }

    // vertical
    for (int j = 0; j < width; j++){
        v = 1;
        for (int i = 1; i < height; i++){

            if (field[i][j] == field[i-1][j]) v++;
            else v = 1;

            if (v == 4 && field[i][j] != 0) return field[i][j];
        }
    }

    // diagonal 1
    for (int sub = -width + 3; sub <= height - 3; sub++){
        d1 = 1;
        for (int i = std::max(1, 1+sub); i <= std::min(height-1, width+sub); i++){

            int j = i - sub;
            if (field[i-1][j-1] == field[i][j]) d1++;
            else d1 = 1;

            if (d1 == 4 && field[i][j] != 0) return field[i][j];
        }
    }

    // diagonal 2
    for (int sum = 3; sum <= height + width - 3; sum++){
        d2 = 1;
        for (int i = std::max(1, sum-width+1); i <= std::min(height-1, sum); i++){

            int j = sum - i;
            if (field[i-1][j+1] == field[i][j]) d2++;
            else d2 = 1;

            if (d2 == 4 && field[i][j] != 0) return field[i][j];
        }
    }


    for (int j = 0; j < width; j++)
        if (canAddToColumn(j)) return 0;

    // draw
    return -1;
}

void Field::print(){

    for (int i = 0; i < height; i++){
        QString s;
        for (int j = 0; j < width; j++)
            s += QString::number(field[i][j]);
        qDebug() << s;
    }

    qDebug() << "\n";
}

void Field::lightWinnerCells()
{
    int h, v, d1, d2;

    // horizontal
    for (int i = 0; i < height; i++){
        h = 1;
        for (int j = 1; j < width; j++){

            if (field[i][j] == field[i][j-1]) h++;
            else h = 1;

            if (h == 4 && field[i][j] != 0) {

                lightWinnerCell(i, j);
                lightWinnerCell(i, j-1);
                lightWinnerCell(i, j-2);
                lightWinnerCell(i, j-3);
                return;
            }
        }
    }

    // vertical
    for (int j = 0; j < width; j++){
        v = 1;
        for (int i = 1; i < height; i++){

            if (field[i][j] == field[i-1][j]) v++;
            else v = 1;

            if (v == 4 && field[i][j] != 0) {

                lightWinnerCell(i, j);
                lightWinnerCell(i-1, j);
                lightWinnerCell(i-2, j);
                lightWinnerCell(i-3, j);
                return;
            }
        }
    }

    // diagonal 1
    for (int sub = -width + 3; sub <= height - 3; sub++){
        d1 = 1;
        for (int i = std::max(1, 1+sub); i <= std::min(height-1, width+sub); i++){

            int j = i - sub;
            if (field[i-1][j-1] == field[i][j]) d1++;
            else d1 = 1;

            if (d1 == 4 && field[i][j] != 0){

                lightWinnerCell(i, j);
                lightWinnerCell(i-1, j-1);
                lightWinnerCell(i-2, j-2);
                lightWinnerCell(i-3, j-3);
                return;
            }
        }
    }

    // diagonal 2
    for (int sum = 3; sum <= height + width - 3; sum++){
        d2 = 1;
        for (int i = std::max(1, sum-width+1); i <= std::min(height-1, sum); i++){

            int j = sum - i;
            if (field[i-1][j+1] == field[i][j]) d2++;
            else d2 = 1;

            if (d2 == 4 && field[i][j] != 0) {

                lightWinnerCell(i, j);
                lightWinnerCell(i-1, j+1);
                lightWinnerCell(i-2, j+2);
                lightWinnerCell(i-3, j+3);
                return;
            }
        }
    }

}

void Field::lightWinnerCell(int i, int j)
{
    itemsList[i][j]->setPixmap(winnerCellImage);
}

void Field::setFieldCellsColor()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            itemsList[i][j]->setPixmap(cellImage);
}


