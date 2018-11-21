#include "gamefield.h"

#include <vector>
#include <QString>
#include <QtGui>

GameField::GameField(int height, int width)
{
    this->height = height;
    this->width = width;
}

bool GameField::canAddToColumn(int column)
{
    if (column < 0 || column >= width) return false;
    if (numberInColumn[column] < height) return true;
    return false;
}

bool GameField::addToColumn(int column, int player)
{
    if (!canAddToColumn(column)) return false;

    int pos = numberInColumn[column]++;
    field[height-pos-1][column] = player;
    return true;
}

bool GameField::removeFromColumn(int column){

    if (column < 0 || column >= width) return false;
    if (numberInColumn[column] == 0) return false;

    int pos = --numberInColumn[column];
    field[height-pos-1][column] = 0;
    return true;
}

int GameField::endOfGame()
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

    // droft
    return -1;
}


std::pair<int, int> GameField::bestMove(int movesLeft, int player){

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

    if (movesLeft == 8){

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

void GameField::print(){

    for (int i = 0; i < height; i++){
        QString s;
        for (int j = 0; j < width; j++)
            s += QString::number(field[i][j]);
        qDebug() << s;
    }

    qDebug() << "\n";
}


