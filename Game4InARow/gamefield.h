#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <iostream>

class GameField
{
    public:
        GameField(int height, int width);
        bool canAddToColumn(int column);
        int endOfGame();
        bool addToColumn(int column, int player);
        bool removeFromColumn(int column);
        std::pair<int, int> bestMove(int movesLeft, int player);

        void print();

    private:
        const static int NMAX = 10;
        int field[NMAX][NMAX] = {{0}};
        int numberInColumn[NMAX] = {0};
        int width;
        int height;
};

#endif // GAMEFIELD_H
